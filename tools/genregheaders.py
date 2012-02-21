#!/usr/bin/env python

# Copyright (c) 2012 Freescale Semiconductor, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without modification,
# are permitted provided that the following conditions are met:
#
# o Redistributions of source code must retain the above copyright notice, this list
#   of conditions and the following disclaimer.
#
# o Redistributions in binary form must reproduce the above copyright notice, this
#   list of conditions and the following disclaimer in the documentation and/or
#   other materials provided with the distribution.
#
# o Neither the name of Freescale Semiconductor, Inc. nor the names of its
#   contributors may be used to endorse or promote products derived from this
#   software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
# ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

import sys, os, string, argparse, re, textwrap, datetime, codecs
from xml.etree import ElementTree
from UserDict import UserDict

##
# @main
#
# The purpose of this tool is to automatically generate register definition header files from the
# XML that is used to create the register sections of Freescale reference manuals.
#
# @par Remaining tasks:
# - Support RW/RO registers and bitfields.
# - Ensure bitfields are sorted in the correct order for struct members and #defines.
# - Support SCT variants of registers, and registers that dont have them.
# - Print warning for registers with too many bits.
# - Insert reserved bits if bits are missing from a register.
# - Insert padding into struct with all registers if there are holes in the address ranges.
# - Improve parsing of numeric values (fix failed generation for some XML files).
# - Improve formatting of long description comments.
# - Warn for registers with duplicate addresses or names.
# - Allow a base address, instances, and instance offsets to be specified if a design file is not
#   available.
# - Fully support feature attribtues.
# - Support creating multi-instance registers.
#
# @par Version history:
#
# 1.0:
# - initial version
#

# Tool version number and copyright string.
kToolVersion = "1.0b1"
kToolCopyright = "Copyright (c) 2012 Freescale Semiconductor, Inc. All rights reserved."

kProductNames = ['mx6dq', 'mx6sl', 'mx6sdl']

kAccessModes = ['RW', 'RO', 'ROZ', 'ROO', 'RU']

##
# @brief Turns an Element tree into a string.
#
# Given a tree of Element objects, this function will produce readable output from the text
# contained in those elements.
def formatText(rootElem):
    return " ".join([q.strip() for q in rootElem.itertext()])

##
# @brief Make text into a valid C identifier.
def formatIdentifier(text):
    if text is None:
        return "_"
    return text.strip().replace('\n', '').replace(' ', '_').upper()

##
# @brief Converts a hex address string to an integer value.
#
# @param addressString A string of hex digits in the form "020C_4000". There may be a "0x"
#   prefix. Any characters that are not hex digits are stripped.
# @param base Base of the number. Pass 0 to use the string prefix to determine the base.
# @return The integer value of @a addressString.
def convertHexValue(addressString, base=0):
    if base==0 and addressString.startswith('0x'):
        addressString = addressString[2:]
        base = 16
    return int(''.join([d for d in addressString if (d in string.hexdigits)]), base)

##
# @brief Check an attribute against a list of values.
# @retval True There was either no feature attribute or the feature was found in the features list.
# @retval False A feature attribute was present but none of its values were found in the features
#       list.
def checkAttribList(elem, attribName, values):
    attrib = elem.get(attribName)
    if attrib is None:
        return True
    
    # See if any of the features in the attribute are in our features list.
    for theAttribValue in attrib.split():
        if theAttribValue.lower() in values:
            return True
    
    # Didn't find a feature in our features list, so return false.
    return False

##
# @brief Filter attributes against a dictionary of values.
# @param elem The Element object with the attribetus to check.
# @param attribs Dictionary with attribute names as keys and allowed attribute value lists as values.
# @retval True Attribtues passed all checks.
# @retval False An attribute value was not present in the dictionary.
def filterAttributes(elem, attribs):
    for attribName in attribs.keys():
        if not checkAttribList(elem, attribName, attribs[attribName]):
            return False
    
    # Everything checks out.
    return True

##
# @brief Exception thrown to indicate a mismatched product.
class WrongProductException(Exception):
    pass

##
# @brief Holds component information.
class Component:
    def __init__(self, memoryMap, name):
        self.memoryMap = memoryMap
        self.name = name.upper()
        self.registers = []
        
        self.count = self.memoryMap.getInstanceCount(self.name)
        self.isMultiInstance = (self.count > 1)
        
        # Get address of first instance.
        self.baseAddress = self.memoryMap.getBaseAddress(self.name, 0)
        
        self.structName = "hw_%s_t" % (self.name.lower())
    
    def addRegister(self, reg):
        # Add the new register.
        self.registers.append(reg)
        
        # Sort registers by address.
        self.registers.sort(key=lambda reg:reg.addressOffset)

##
# @brief Register definition.
class Register:
    ##
    # @exception WrongProductException Raised when the XML element has an attribute that specifies
    #   that it belongs to a product other than the one passed on @a productName.
    def __init__(self, component, elem, filterAttribs):
        self.memoryMap = component.memoryMap
        self.component = component
        self.element = elem
        
        # Filter based on attributes.
        if not filterAttributes(elem, filterAttribs):
            raise WrongProductException()
        
        self.name = formatIdentifier(elem.find('registerName').text)
        self.fullName = elem.find('registerNameMore/registerNameFull').text.strip().replace('\n', '')
        self.description = formatText(elem.find('registerBody/registerDescription'))
        
        self.formattedName = "%s_%s" % (self.component.name, self.name)
        self.structName = "hw_%s_t" % (self.formattedName.lower())
        
        # Extract register details.
        props = elem.find('registerBody/registerProperties/registerPropset')
        self.addressOffset = convertHexValue(props.find('addressOffset').text)
        self.sizeInBits = convertHexValue(props.find('registerSize').text)
        self.sizeInBytes = self.sizeInBits / 8
        self.access = props.find('registerAccess').text
        self.isWritable = (self.access == 'RW')
        self.resetValue = convertHexValue(props.find('registerResetValue').text)
        
        if self.sizeInBits == 32:
            self.bitFieldType = "unsigned"
        elif self.sizeInBits == 16:
            self.bitFieldType = "unsigned short"
        elif self.sizeInBits == 8:
            self.bitFieldType = "unsigned char"
        else:
            raise Exception("invalid register size: " + str(self.sizeInBits))
        
        # Determine how many related registers there are.
        self.relatedRegisterSuffixes = []
        dims = props.find('dimension')
        if dims is not None:
            dimValue = dims.find('dimensionValue').text
            if dimValue is not None:
                self.relatedRegisterSuffixes = dims.find('unitQualifier').text.split(',')
        
        # Create the BitField objects.
        self.bitFields = []
        for e in elem.findall('bitField'):
            try:
                self.bitFields.append(BitField(self, e, filterAttribs))
            except WrongProductException:
                # Just ignore this exception
                pass
        
        # Make sure all bits have a bitfield.
        self._createMissingBitFields()
        
        # Now sort the bitfields by bit number.
        self.bitFields.sort(key=lambda field:field.offset)
    
    ##
    # @brief Create reserved bitfields for missing bits.
    def _createMissingBitFields(self):
        i = 0
        while i < self.sizeInBits:
            field = self.getBitFieldForBit(i)
            if field is not None:
                i += field.width
                continue
            
            # There is a hole in the bitfields, so fill it in. First find out how big the hole is.
            holeWidth = 1
            while (i + holeWidth < self.sizeInBits) and (self.getBitFieldForBit(i + holeWidth) is None):
                holeWidth += 1
            
            self.bitFields.append(ReservedBitField(self, holeWidth, i))
            
            i += holeWidth
    
    def getBitFieldForBit(self, bitNumber):
        for field in self.bitFields:
            if field.hasBit(bitNumber):
                return field
        
        # Didn't find a matching bitfield!
        return None
    
    def dump(self):
        print "%s (0x%08x, %d, %s, 0x%08x):" % (self.formattedName, self.addressOffset, self.sizeInBits, self.access, self.resetValue)
        print "  fullName: " + self.fullName
        print "  desc: " + self.description
        print "  offset: " + hex(self.addressOffset)
        print "  access: " + self.access
        print "  reset: " + hex(self.resetValue)
        print "  related: " + `self.relatedRegisterSuffixes`
        print "  fields: "
        for f in self.bitFields:
            f.dump()

##
# @brief A bit field of a register.
class BitField:
    ##
    # @brief Regular expression to help filter bitfield names.
    #
    # Some bitfield names in the XML definitions have the bit ranges appended to the name, but we
    # can't allow that since we need to produce valid C code.
    nameFilter = re.compile(r'^([a-zA-Z_]+[a-zA-Z0-9_]*)')
    
    ##
    # @exception WrongProductException Raised when the XML element has an attribute that specifies
    #   that it belongs to a product other than the one passed on @a productName.
    def __init__(self, reg, elem, filterAttribs):
        # Filter based on attributes.
        if not filterAttributes(elem, filterAttribs):
            raise WrongProductException()
        
        self.register = reg
        self.element = elem
        self.name = formatIdentifier(elem.find('bitFieldName').text)
        self.description = formatText(elem.find('bitFieldBody/bitFieldDescription'))
        
        # Check for the special reserved bitfield name.
        self.isReserved = (self.name == '-')
        
        # Filter up the bitfield name and uppercase it. Some of the bitfield names has the bit
        # range appended to them, so we have to get rid of that.
        if not self.isReserved:
            try:
                nameMatch = BitField.nameFilter.match(self.name)
                self.name = nameMatch.group(1).upper()
            except:
                # We couldn't find an identifier leading the name, so mark this field as reserved.
                self.isReserved = True
        
        self.formattedName = "%s_%s" % (self.register.formattedName, self.name)
        
        # Set the internal flag if the bitfield has an audience attribute with a value of "internal"
        self.isInternal = (elem.get('audience') == 'internal')
        
        # Get bitfield properties.
        props = elem.find('bitFieldBody/bitFieldProperties/bitFieldPropset')
        self.width = int(props.find('bitWidth').text)
        self.offset = int(props.find('bitOffset').text)
        self.access = props.find('bitFieldAccess').text
        
        # Build mask.
        self._buildMask()
        
        # Build values list.
        allValueElems = elem.findall('bitFieldBody/bitFieldValues/bitFieldValueGroup')
        
        self.values = []
        for valueElem in allValueElems:
            # Check filter.
            if not filterAttributes(elem, filterAttribs):
                continue
            
            value = valueElem.find('bitFieldValue')
            name = valueElem.find('bitFieldValueName')
            desc = valueElem.find('bitFieldValueDescription')
            if value is None or name is None:
                continue
            
            thisValue = UserDict()
            thisValue.value = int(value.text, 0)
            thisValue.name = name.text
            
            if desc is None:
                thisValue.desc = ''
            else:
                thisValue.desc = formatText(desc)
            
            self.values.append(thisValue)
    
    def _buildMask(self):
        self.mask = 0
        for i in range(self.width):
            self.mask = (self.mask << 1) | 1
        self.mask = self.mask << self.offset
    
    def hasBit(self, whichBit):
        return ((1 << whichBit) & self.mask) != 0
    
    def dump(self):
        if self.width == 1:
            b = str(self.offset)
        else:
            b = "%d:%d" % ((self.offset + self.width - 1), self.offset)
        
        print "    %s[%s] (%s)" % (self.formattedName, b, self.access) #, self.description)
        for v in self.values:
            print "        0x%08x = %s" % (v.value, v.name)

class ReservedBitField(BitField):
    def __init__(self, reg, width, offset):
        self.register = reg
        self.name = "-"
        self.width = width
        self.offset = offset
        self.access = 'ROZ'
        self.values = []
        self.isReserved = True
        self.isInternal = False
        self.formattedName = "-"
        self.description = ""
        
        self._buildMask()

##
# @brief Component memory map.
class MemoryMap:
    def __init__(self, elem):
        self.element = elem
        self.components = {}
        
        for theComponent in elem.findall('component-ref'):
            try:
                name, instances = self._processComponent(theComponent)
                
                self.components[name] = instances
                
            except Exception, e:
                print "Error processing component: " + str(e)
    
    ##
    # @return A list containing UserDict objects for each instance of the component.
    def _processComponent(self, component):
        # Create a dictionary to hold component info
        instances = []
        
        # Extract attribtues.
        name = component.get('ip-name').upper()
        base = convertHexValue(component.get('base-address'), 16) # string in the form "020C_4000"
        
        # Try to get attributes for multiple instances. These are optional attributes. If the
        # attribute doesn't exist, then Element.get() will return None.
        count = component.get('instancesNumber')
        if count is None:
            count = 1
        else:
            count = int(count)
            
        qualifiers = component.get('unitQualifier')
        if qualifiers is None:
            qualifiers = ['']
        else:
            qualifiers = qualifiers.split(',')
        
        offsets = component.get('instanceOffsets')
        if offsets is None:
            offsets = [0]
        else:
            offsets = [0] + [convertHexValue(o, 16) for o in offsets.split(',')]
        
        # Iterate over the instances.
        for i in range(count):
            instance = UserDict()
            instance.name = name + qualifiers[i]
            instance.offset = offsets[i]
            instance.baseAddress = base + offsets[i]
            
            instances.append(instance)
        
        return (name, instances)
    
    def dump(self):
        for k in sorted(self.components):
            i = self.components[k]
            print "%s: 0x%08x" % (i.name, i.baseAddress)
    
    def getBaseAddress(self, name, instance):
        return self.components[name][instance].baseAddress
    
    def getInstanceCount(self, name):
        return len(self.components[name])
        

fileTemplate = u"""/*
 * Copyright (C) {year}, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _{component.name}_H
#define _{component.name}_H

#include "regs.h"

#ifndef REGS_{component.name}_BASE
{baseAddressMacros}#endif

{registerDefinitions}

{moduleStructDefinition}

#endif // _{component.name}_H
"""

baseAddressTemplate = u"#define REGS_{component.name}_BASE (REGS_BASE + {component.baseAddress:#010x})\n"

baseAddressTemplateMulti = u"#define REGS_{component.name}{instanceNumber}_BASE (REGS_BASE + {instanceOffset:#010x})\n"

baseAddressMultiMacroTemplate1 = u"#define REGS_{component.name}_BASE(x) ( "
baseAddressMultiMacroTemplate2 = u"x == {instanceNumber} ? REGS_{component.name}{instanceNumber}_BASE : "
baseAddressMultiMacroTemplate3= u"0xffff0000)\n"

regTemplate = u"""
/*!
 * @brief HW_{reg.formattedName} - {reg.fullName}
 *
{regComment}
 */
#ifndef __LANGUAGE_ASM__
typedef union
{{
    reg{reg.sizeInBits}_t  U;
    struct
    {{
{bitFields}    }} B;
}} {reg.structName};
#endif

/*
 * constants & macros for entire {reg.formattedName} register
 */
#define HW_{reg.formattedName}_ADDR      (REGS_{component.name}_BASE + {reg.addressOffset:#x})

#ifndef __LANGUAGE_ASM__
#define HW_{reg.formattedName}           (*(volatile {reg.structName} *) HW_{reg.formattedName}_ADDR)
#define HW_{reg.formattedName}_RD()      (HW_{reg.formattedName}.U)
#define HW_{reg.formattedName}_WR(v)     (HW_{reg.formattedName}.U = (v))
#define HW_{reg.formattedName}_SET(v)    (HW_{reg.formattedName}_WR(HW_{reg.formattedName}_RD() |  (v)))
#define HW_{reg.formattedName}_CLR(v)    (HW_{reg.formattedName}_WR(HW_{reg.formattedName}_RD() & ~(v)))
#define HW_{reg.formattedName}_TOG(v)    (HW_{reg.formattedName}_WR(HW_{reg.formattedName}_RD() ^  (v)))
#endif


/*
 * constants & macros for individual {reg.formattedName} bitfields
 */
"""

regTemplateMulti = u"""
/*!
 * @brief HW_{reg.formattedName} - {reg.fullName}
 *
{regComment}
 */
#ifndef __LANGUAGE_ASM__
typedef union
{{
    reg{reg.sizeInBits}_t  U;
    struct
    {{
{bitFields}    }} B;
}} {reg.structName};
#endif

/*
 * constants & macros for entire multi-block {reg.formattedName} register
 */
#define HW_{reg.formattedName}_ADDR(x)      (REGS_{component.name}_BASE(x) + {reg.addressOffset:#x})

#ifndef __LANGUAGE_ASM__
#define HW_{reg.formattedName}(x)           (*(volatile {reg.structName} *) HW_{reg.formattedName}_ADDR(x))
#define HW_{reg.formattedName}_RD(x)        (HW_{reg.formattedName}(x).U)
#define HW_{reg.formattedName}_WR(x, v)     (HW_{reg.formattedName}(x).U = (v))
#define HW_{reg.formattedName}_SET(x, v)    (HW_{reg.formattedName}_WR(x, HW_{reg.formattedName}_RD(x) |  (v)))
#define HW_{reg.formattedName}_CLR(x, v)    (HW_{reg.formattedName}_WR(x, HW_{reg.formattedName}_RD(x) & ~(v)))
#define HW_{reg.formattedName}_TOG(x, v)    (HW_{reg.formattedName}_WR(x, HW_{reg.formattedName}_RD(x) ^  (v)))
#endif


/*
 * constants & macros for individual {reg.formattedName} bitfields
 */
"""

structBitFieldTemplate = u"        {fieldType} {fieldName} : {fieldWidth}; //!< {fieldDesc}\n"

bitFieldTemplate = u"""
/* --- Register HW_{reg.formattedName}, field {field.name}
 *
{fieldComment}
 */

#define BP_{field.formattedName}      {field.offset}
#define BM_{field.formattedName}      {field.mask:#010x}

#ifndef __LANGUAGE_ASM__
#define BF_{field.formattedName}(v)   ((((reg32_t) v) << {field.offset}) & BM_{field.formattedName})
#else
#define BF_{field.formattedName}(v)   (((v) << {field.offset}) & BM_{field.formattedName})
#endif
#ifndef __LANGUAGE_ASM__
#define BW_{field.formattedName}(v)   BF_CS1({component.name}_{reg.name}, {field.name}, v)
#endif
"""

bitFieldValueTemplate = u"#define BV_{field.formattedName}__{value.name}    {value.value:#x}\n"

moduleStructTemplate = u"""
/*!
 * @brief All {component.name} module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{{
{structMembers}}} {component.structName}
#endif
"""

moduleStructMemberTemplate = u"    volatile {reg.structName} {reg.name}; //!< {reg.fullName}\n"
moduleStructPaddingTemplate = u"    {paddingType} {paddingName}{paddingBytes};\n"

moduleStructRefTemplate = u"""
//! @brief Macro to access all {component.name} registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_{component.name}(0)</code>.
#define HW_{component.name}     (*(volatile {component.structName} *) REGS_{component.name}_BASE)
"""

moduleStructRefTemplateMulti = u"""
//! @brief Macro to access all {component.name} registers.
//! @param x {component.name} instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_{component.name}(0)</code>.
#define HW_{component.name}(x)     (*(volatile {component.structName} *) REGS_{component.name}_BASE(x))
"""

##
# @brief Generate a header file from a component.
class HeaderGenerator:
    def __init__(self, component):
        self.component = component
        
        self.commentWrapper = textwrap.TextWrapper(width=100, initial_indent=" * ", subsequent_indent=" * ")
    
    ##
    # @brief Generate output.
    def generate(self, outputFile=sys.stdout):
        regs = ""
        
        for aReg in self.component.registers:
            regs += self._generateRegister(aReg)
        
        baseAddressMacros = self._generateBaseAddressMacros()
        moduleStruct = self._generateModuleStruct()
        
        # Get the current year.
        year = datetime.datetime.today().year
        
        formatDict = { 'component':self.component,
                        'baseAddressMacros':baseAddressMacros,
                        'registerDefinitions':regs,
                        'moduleStructDefinition':moduleStruct,
                        'year':year}
        
        s = fileTemplate.format(**formatDict)
        
        # Write the header in UTF-8 encoding to the output file.
        writer = codecs.getwriter('utf-8')(outputFile)
        writer.write(s)
    
    def _generateBaseAddressMacros(self):
        output = ""
        
        if not self.component.isMultiInstance:
            output = baseAddressTemplate.format(component=self.component)
        else:
            txt = baseAddressMultiMacroTemplate1.format(component=self.component)
            
            for i in range(self.component.count):
                offset = self.component.memoryMap.getBaseAddress(self.component.name, i)
                formatDict = { 'component':self.component,
                                'instanceNumber':i,
                                'instanceOffset':offset }
                output += baseAddressTemplateMulti.format(**formatDict)
                txt += baseAddressMultiMacroTemplate2.format(**formatDict)
            
            output += txt + baseAddressMultiMacroTemplate3
        
        return output
        
    def _generateRegister(self, reg):
        bitFields = self._generateStructBitfields(reg)
        
        regComment = self.commentWrapper.fill(reg.description.strip().replace('\n', ' '))
        #"\n".join([" * " + l for l in textwrap.wrap(reg.description.strip(), 100)])
        
        formatDict = { 'component':self.component,
                        'reg':reg,
                        'bitFields':bitFields,
                        'regComment':regComment }
        
        if self.component.isMultiInstance:
            whichTemplate = regTemplateMulti
        else:
            whichTemplate = regTemplate
        
        output = whichTemplate.format(**formatDict)
        output += self._generateBitfields(reg)
        
        return output
    
    def _generateStructBitfields(self, reg):
        output = ""
        reservedCount = 0
        usedNames = []
        
        for f in reg.bitFields:
            # Choose the name of this struct member. If the field is reserved, then ensure that
            # we have a unique name.
            if f.isReserved:
                fieldName = "RESERVED%d" % reservedCount
                reservedCount += 1
            else:
                fieldName = f.name
            
            # Second check for name uniqueness. If there was already a field with the same name,
            # then add a suffix to unique it.
            origFieldName = fieldName
            uniqueCount = 1
            hadDuplicateName = False
            while fieldName in usedNames:
                hadDuplicateName = True
                fieldName = origFieldName + str(uniqueCount)
                uniqueCount += 1
            
            # Print a warning if there was a duplicate name.
            if hadDuplicateName:
                print >> sys.stderr, "Warning: register %s of %s has duplicate field %s, renamed to %s!" % (reg.name, self.component.name, origFieldName, fieldName)
            
            # Add to the list of used member names.
            usedNames.append(fieldName)
            
            # Clean up field description so it fits on one line.
            cleanDescription = " ".join([l.strip() for l in f.description.splitlines()])
            
            # Now generate this struct member definition.
            formatDict = { 'fieldName':fieldName,
                            'fieldWidth':f.width,
                            'fieldType':reg.bitFieldType,
                            'fieldDesc':cleanDescription}
            output += structBitFieldTemplate.format(**formatDict)
        
        return output
    
    def _generateBitfields(self, reg):
        output = ""
        
        for f in reg.bitFields:
            if f.isReserved:
                continue
            
            fieldComment = self.commentWrapper.fill(f.description.strip().replace('\n', ' '))
            
            formatDict = { 'component':self.component,
                            'reg':reg,
                            'field':f,
                            'fieldComment':fieldComment }
            output += bitFieldTemplate.format(**formatDict)
            
            if len(f.values):
                output += "\n"
            for v in f.values:
                output += bitFieldValueTemplate.format(value=v, **formatDict)
        
        return output
    
    def _generateModuleStruct(self):
        members = ""
        
        # Generate members of whole-module registers struct. If there are holes in the addresses,
        # 
        paddingCount = 0
        currentOffset = 0
        for aReg in self.component.registers:
            # Check if we need to insert padding.
            paddingBytes = aReg.addressOffset - currentOffset
            if paddingBytes > 0:
                currentOffset += paddingBytes
                
                if (paddingBytes % 4) == 0:
                    t = 'reg32_t'
                    n = paddingBytes / 4
                elif (paddingBytes % 2) == 0:
                    t = 'reg16_t'
                    n = paddingBytes / 2
                else:
                    t = 'reg8_t'
                    n = paddingBytes
                
                if n > 1:
                    nStr = "[%d]" % n
                else:
                    nStr = ''
                
                paddingName = "_reserved%d" % paddingCount
                paddingCount += 1
                
                members += moduleStructPaddingTemplate.format(paddingType=t, paddingName=paddingName, paddingBytes=nStr)
            
            members += moduleStructMemberTemplate.format(reg=aReg)
            currentOffset += aReg.sizeInBytes
        
        formatDict = { 'component':self.component,
                        'structMembers':members }
        output = moduleStructTemplate.format(**formatDict)
        
        if self.component.isMultiInstance:
            refTemplate = moduleStructRefTemplateMulti
        else:
            refTemplate = moduleStructRefTemplate
        
        output += refTemplate.format(**formatDict)
        
        return output

##
# @brief Tool to generate register header files from XML.
class HeaderGeneratorTool:
    def _printVersion(self):
        print os.path.basename(sys.argv[0]), kToolVersion
        print kToolCopyright

    ##
    # @brief Create a MemoryMap object from a design XML file.
    # @param self
    # @param design A file object containing the design XML.
    # @return A new MemoryMap instance that holds the component information read from the design XML.
    def _buildMap(self, designXml):
        if designXml is None:
            return None
        
        # Parse the design XML into a tree.
        designTree = ElementTree.ElementTree()
        designTree.parse(designXml)
        
        return MemoryMap(designTree.getroot())
    
    def _buildComponent(self, memoryMap, componentXml):
        # Parse the component XML into a tree.
        tree = ElementTree.ElementTree()
        tree.parse(componentXml)
        
        # Extract the component's name.
        componentName = tree.find('ip-data/ip-name').text
        
        # Create component instance.
        component = Component(memoryMap, componentName)
        
        addrBlock = tree.find('memoryMap/addressBlock')
        registerElements = addrBlock.findall('register')
        
        regs = []
        for r in registerElements:
            try:
                thisReg = Register(component, r, self.filterAttribs)
                #thisReg.dump()
                component.addRegister(thisReg)
            except WrongProductException:
                # Ignore this exception. It simply means that this register doesn't belong to the
                # product we're working with.
                pass
        
        return component
    
    ##
    # @brief Generate the register header file from input XML files.
    # @param self
    # @param designXml Chip design XML file object. May be None, but register addresses will be incorrect.
    # @param componentXml Component XML file object that contains the register definitions.
    def _generateHeader(self, designXml, componentXml):
        # Create memory map and component objects from XML.
        memoryMap = self._buildMap(designXml)
        component = self._buildComponent(memoryMap, componentXml)
        
        generator = HeaderGenerator(component)
        generator.generate()

    ##
    # @brief Read the command line and generate the output file.
    #
    # This method is the meat of the class; all other methods are here to support this one.
    #
    def run(self):
        # Process command line options.
        args = self._readOptions()
        
        # Check for version option.
        if args.showVersion:
            self._printVersion()
            return

        # Verify that there is input.
        if len(args.components) == 0:
            print "Error: no input component XML was provided"
            return
        
        # Make sure the product is known.
        if args.product.lower() not in kProductNames:
            print "Error: unrecognized product name '%s'" % args.product
        
        # Check for a design file.
        if args.design is None:
            print "Warning: no design XML was provided, register addresses will be invalid!"
        
        # Read features from a file and add to features list.
        if args.features_file is not None:
            args.feature += [k.strip() for k in args.features_file.readlines() if (len(k.strip()) > 0)]
        
        self.filterAttribs = { 'product':[args.product.lower()],
                                'feature':args.feature,
                                'audience':[args.audience.lower()] }
        #print >> sys.stderr, 'filter=' + repr(self.filterAttribs)
        
        # Generate the heade file from the input XML.
        for theComponent in args.components:
            self._generateHeader(args.design, theComponent)
        
    ##
    # @brief Parse command line options into an options dictionary.
    #
    # The options dictionary that is the first element in the tuple returned from this
    # method has the following attributes:
    #   - inputFilePath: Path to the input OTP bit settings file.
    #   - outputFilePath: Path to the output file, which will either be the .dat file
    #       containing the binary OTP bit data or the .sb file, depending on whether
    #       the user wants to run elftosb or not. This attribute may be None, in
    #       which case the user expects output file names to be based on the input
    #       file name.
    #   - showVersion: Boolean for whether to show the tool version and exit.
    #
    # @return A bi-tuple is returned that contains the command line options value dictionary
    #   and any leftover command line positional arguments.
    def _readOptions(self):
        # Build arg parser.
        parser = argparse.ArgumentParser(description="Generate register headers from XML")

        parser.add_argument("-V", "--version", action="store_true", dest="showVersion", help="Show version information.")
        parser.add_argument("-d", "--design", type=argparse.FileType('r'), help="Specify the design file with component details.")
        parser.add_argument("-p", "--product", default='mx6dq', help="Set the product name.")
        parser.add_argument("-f", "--feature", action="append", help="Add a named feature.", default=[])
        parser.add_argument("--features-file", type=argparse.FileType('r'), help="Read features from a file.")
        parser.add_argument("-a", "--audience", default='customer', help="Specify the audience.")
        parser.add_argument("-q", "--quiet", action="store_true", help="Don't print informational messages.")
        parser.add_argument("components", nargs='*', type=argparse.FileType('r'), help="Component XML file.")

        #Retrieve agruments(list) and options(dictionary)
        return parser.parse_args()

# Are we being executed directly?
if __name__ == '__main__':
    HeaderGeneratorTool().run()


