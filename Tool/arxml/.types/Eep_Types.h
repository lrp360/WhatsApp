/**
 * WhatsApp - the open source AUTOSAR platform https://github.com/parai
 *
 * Copyright (C) 2014  WhatsApp <parai@foxmail.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * Version: AUTOSAR 4.2.0
 * Generated by arxml.py
 */
#ifndef EEP_TYPES_H
#define EEP_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* Container for the references to DemEventParameter elements which shall be invoked using the
 *  API Dem_ReportErrorStatus API in case the corresponding error occurs. The EventId is taken
 *  from the referenced DemEventParameter's DemEventId value. The standardized errors are provided
 *  in the container and can be extended by vendor specific error references.
 */
typedef struct Eep_DemEventParameterRefsType_tag
{
/* Reference to the DemEventParameter which shall be issued when the error "EEPROM compare failed
 *  (HW)" has occurred.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* EEP_E_COMPARE_FAILED ;
/* Reference to the DemEventParameter which shall be issued when the error "EEPROM erase failed
 *  (HW)" has occurred.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* EEP_E_ERASE_FAILED ;
/* Reference to the DemEventParameter which shall be issued when the error "EEPROM read failed
 *  (HW)" has occurred.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* EEP_E_READ_FAILED ;
/* Reference to the DemEventParameter which shall be issued when the error "EEPROM write failed
 *  (HW)" has occurred.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* EEP_E_WRITE_FAILED ;
} Eep_DemEventParameterRefsType ;

/* This container is present for external EEPROM drivers only. Internal EEPROM drivers do not use
 *  the parameter listed in this container, hence its multiplicity is 0 for internal drivers.
 */
typedef struct Eep_ExternalDriverType_tag
{
/* Reference to SPI sequence (required for external EEPROM drivers). */
/* /AUTOSAR/EcucDefs/Spi/SpiDriver/SpiSequence */
	Spi_SequenceType* EepSpiReference ;
} Eep_ExternalDriverType ;

/* This parameter is the default EEPROM device mode after initialization. */
typedef enum
{
	EEP_DEFAULTMODE_MEMIF_MODE_FAST,
	EEP_DEFAULTMODE_MEMIF_MODE_SLOW
} Eep_DefaultModeType ;

/* This parameter is a reference to a callback function for positive job result (see EEP045). */
/* TODO: 
 * typedef void (*Eep_JobEndNotificationType)(void);
 */

/* This parameter is a reference to a callback function for negative job result (see EEP046). */
/* TODO: 
 * typedef void (*Eep_JobErrorNotificationType)(void);
 */

/* Container for general configuration parameters of the EEPROM driver. These parameters are always
 *  pre-compile.
 */
typedef struct Eep_GeneralType_tag
{
/* true:	Development error detection enabled.
 *                                         false:	Development error detection disabled.
 */
/* Pre-processor switch to enable and disable development error detection. */
	boolean EepDevErrorDetect ;
/* Index of the driver, used by EA. */
	uint8 EepDriverIndex ;
/* true:	Interrupt controlled job processing enabled.
 *                                         false:	Interrupt controlled job processing disabled.
 */
/* Switches to activate or deactivate interrupt controlled job processing. */
	boolean EepUseInterrupts ;
/* true:	Version info API enabled.
 *                                         false:	Version info API disabled.
 */
/* Pre-processor switch to enable / disable the API to read out the modules version information. */
	boolean EepVersionInfoApi ;
/* true:	Write cycle reduction enabled.
 *                                         false:	Write cycle reduction disabled.
 */
/* Switches to activate or deactivate write cycle reduction (EEPROM value is read and compared
 *  before being overwritten).
 */
	boolean EepWriteCycleReduction ;
} Eep_GeneralType ;

/* Container for runtime configuration parameters of the EEPROM driver. */
typedef struct Eep_InitConfigurationType_tag
{
	Eep_DemEventParameterRefsType* EepDemEventParameterRefs ;
	Eep_ExternalDriverType* EepExternalDriver ;
/* Implementation Type: Eep_AddressType. */
/* This parameter is the EEPROM device base address. */
	uint32 EepBaseAddress ;
/* Implementation Type: MemIf_ModeType. */
	Eep_DefaultModeType EepDefaultMode ;
/* Implementation Type: Eep_LengthType. */
/* Number of bytes read within one job processing cycle in fast mode. If the hardware does not
 *  support burst mode this parameter shall be set to the same value as EepNormalReadBlockSize.
 */
	uint32 EepFastReadBlockSize ;
/* Implementation Type: Eep_LengthType. */
/* Number of bytes written within one job processing cycle in fast mode. If the hardware does not
 *  support burst mode this parameter shall be set to the same value as EepNormalWriteBlockSize.
 */
	uint32 EepFastWriteBlockSize ;
/* Call cycle time of the EEPROM driver's main function. Unit: [s] */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 EepJobCallCycle ;
	Eep_JobEndNotificationType EepJobEndNotification ;
	Eep_JobErrorNotificationType EepJobErrorNotification ;
/* Implementation Type: Eep_LengthType. */
/* Number of bytes read within one job processing cycle in normal mode. */
	uint32 EepNormalReadBlockSize ;
/* Implementation Type: Eep_LengthType. */
/* Number of bytes written within one job processing cycle in normal mode. */
	uint32 EepNormalWriteBlockSize ;
/* Implementation Type: Eep_LengthType. */
/* This parameter is the used size of EEPROM device in bytes. */
	uint32 EepSize ;
} Eep_InitConfigurationType ;

/* Additional published parameters not covered by CommonPublishedInformation container. */
typedef struct Eep_PublishedInformationType_tag
{
/* Specified maximum number of write cycles under worst case conditions of specific EEPROM hardware
 *  (e.g. +90C)
 */
	uint32 EepAllowedWriteCycles ;
/* Maximum time for erasing one EEPROM data unit. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 EepEraseTime ;
/* Size of smallest erasable EEPROM data unit in bytes. */
	uint32 EepEraseUnitSize ;
/* Value of an erased EEPROM cell. */
	uint8 EepEraseValue ;
/* Minimum expected size of Eep_AddressType. */
	uint32 EepMinimumAddressType ;
/* Minimum expected size of Eep_LengthType. */
	uint32 EepMinimumLengthType ;
/* Size of smallest readable EEPROM data unit in bytes. */
	uint32 EepReadUnitSize ;
/* Number of erase cycles specified for the EEP device (usually given in the device data sheet). */
	uint32 EepSpecifiedEraseCycles ;
/* Implementation Type: Eep_LengthType. */
/* Total size of EEPROM in bytes. */
	uint32 EepTotalSize ;
/* Maximum time for writing one EEPROM data unit. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 EepWriteTime ;
/* Size of smallest writeable EEPROM data unit in bytes. */
	uint32 EepWriteUnitSize ;
} Eep_PublishedInformationType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* EEP_TYPES_H */
