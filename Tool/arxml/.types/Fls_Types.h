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
#ifndef FLS_TYPES_H
#define FLS_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* Container for the references to DemEventParameter elements which shall be invoked using the
 *  Dem_ReportErrorStatus API in case the corresponding error occurs. The EventId is taken from
 *  the referenced DemEventParameter's DemEventId value. The standardized errors are provided in
 *  the container and can be extended by vendor specific error references.
 */
typedef struct Fls_DemEventParameterRefsType_tag
{
/* Reference to the DemEventParameter which shall be issued when the error "Flash compare failed
 *  (HW)" has occurred.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* FLS_E_COMPARE_FAILED ;
/* Reference to the DemEventParameter which shall be issued when the error "Flash erase failed
 *  (HW)" has occurred.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* FLS_E_ERASE_FAILED ;
/* Reference to the DemEventParameter which shall be issued when the error "Flash read failed (HW)"
 *  has occurred.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* FLS_E_READ_FAILED ;
/* Reference to the DemEventParameter which shall be issued when the error "Expected hardware ID
 *  not matched" has occurred.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* FLS_E_UNEXPECTED_FLASH_ID ;
/* Reference to the DemEventParameter which shall be issued when the error "Flash write failed
 *  (HW)" has occurred.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* FLS_E_WRITE_FAILED ;
} Fls_DemEventParameterRefsType ;

/* This container is present for external Flash drivers only. Internal Flash drivers do not use
 *  the parameter listed in this container, hence its multiplicity is 0 for internal drivers.
 */
typedef struct Fls_ExternalDriverType_tag
{
/* Reference to SPI sequence (required for external Flash drivers). */
/* /AUTOSAR/EcucDefs/Spi/SpiDriver/SpiSequence */
	Spi_SequenceType* FlsSpiReference ;
} Fls_ExternalDriverType ;

/* Configuration description of a flashable sector */
typedef struct Fls_SectorType_tag
{
/* FlsPageSize. The parameter FlsSectorStartAddress denotes the start address of the first sector. */
/* Number of continuous sectors with identical values for FlsSectorSize and */
	uint16 FlsNumberOfSectors ;
/* Implementation Type: Fls_LengthType. */
/* Size of one page of this sector. */
	uint32 FlsPageSize ;
/* Implementation Type: Fls_LengthType. */
/* Size of this sector. */
	uint32 FlsSectorSize ;
/* Implementation Type: Fls_AddressType. */
/* Start address of this sector. */
	uint32 FlsSectorStartaddress ;
} Fls_SectorType ;

/* List of flashable sectors and pages. */
typedef struct Fls_SectorListType_tag
{
	Fls_SectorType* FlsSector ;
} Fls_SectorListType ;

/* This parameter is the default FLS device mode after initialization. */
typedef enum
{
	FLS_DEFAULTMODE_MEMIF_MODE_FAST,
	FLS_DEFAULTMODE_MEMIF_MODE_SLOW
} Fls_DefaultModeType ;

/* Mapped to the job end notification routine provided by some upper layer module, typically the
 *  Fee module.
 */
/* TODO: 
 * typedef void (*Fls_JobEndNotificationType)(void);
 */

/* Mapped to the job error notification routine provided by some upper layer module, typically
 *  the Fee module.
 */
/* TODO: 
 * typedef void (*Fls_JobErrorNotificationType)(void);
 */

/* Container for runtime configuration parameters of the flash driver. */
typedef struct Fls_ConfigSetType_tag
{
	Fls_DemEventParameterRefsType* FlsDemEventParameterRefs ;
	Fls_ExternalDriverType* FlsExternalDriver ;
	Fls_SectorListType* FlsSectorList ;
/* Used as function pointer to access the erase flash access code. */
/* Address offset in RAM to which the erase flash access code shall be loaded. */
	uint32 FlsAcErase ;
/* Used as function pointer to access the write flash access code. */
/* Address offset in RAM to which the write flash access code shall be loaded. */
	uint32 FlsAcWrite ;
/* Cycle time of calls of the flash driver's main function (in seconds). */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FlsCallCycle ;
/* Implementation Type: MemIf_ModeType. */
	Fls_DefaultModeType FlsDefaultMode ;
	Fls_JobEndNotificationType FlsJobEndNotification ;
	Fls_JobErrorNotificationType FlsJobErrorNotification ;
/* The maximum number of bytes to read or compare in one cycle of the flash driver's job processing
 *  function in fast mode.
 */
	uint32 FlsMaxReadFastMode ;
/* The maximum number of bytes to read or compare in one cycle of the flash driver's job processing
 *  function in normal mode.
 */
	uint32 FlsMaxReadNormalMode ;
/* The maximum number of bytes to write in one cycle of the flash driver's job processing function
 *  in fast mode.
 */
	uint32 FlsMaxWriteFastMode ;
/* The maximum number of bytes to write in one cycle of the flash driver's job processing function
 *  in normal mode.
 */
	uint32 FlsMaxWriteNormalMode ;
/* Erase/write protection settings. Only relevant if supported by hardware. */
	uint32 FlsProtection ;
} Fls_ConfigSetType ;

/* Container for general parameters of the flash driver. These parameters are always pre-compile. */
typedef struct Fls_GeneralType_tag
{
/* true:	Flash access code loaded on job start / unloaded on job end  
 *                                         	or error.
 *                                         false:	Flash access code not loaded to / unloaded from
 *  RAM at all.
 */
/* The flash driver shall load the flash access code to RAM whenever an erase or write job is started
 *  and unload (overwrite) it after that job has been finished or canceled.
 */
	boolean FlsAcLoadOnJobStart ;
/* FLS169_Conf: This parameter defines the lower boundary for read / write / erase and compare jobs. */
/* The flash memory start address (see also FLS208 and FLS209). */
	uint32 FlsBaseAddress ;
/* true:	API supported / function provided.
 *                                         false:	API not supported / function not provided
 */
/* Compile switch to enable and disable the Fls_Cancel function. */
	boolean FlsCancelApi ;
/* true:	API supported / function provided.
 *                                         false:	API not supported / function not provided
 */
/* Compile switch to enable and disable the Fls_Compare function. */
	boolean FlsCompareApi ;
/* true:	Development error detection enabled.
 *                                         false:	Development error detection disabled.
 */
/* Pre-processor switch to enable and disable development error detection (see FLS077). */
	boolean FlsDevErrorDetect ;
/* Index of the driver, used by FEE. */
	uint8 FlsDriverIndex ;
/* true:	API supported / function provided.
 *                                         false:	API not supported / function not provided
 */
/* Compile switch to enable and disable the Fls_GetJobResult function. */
	boolean FlsGetJobResultApi ;
/* true:	API supported / function provided.
 *                                         false:	API not supported / function not provided
 */
/* Compile switch to enable and disable the Fls_GetStatus function. */
	boolean FlsGetStatusApi ;
/* true:	API supported / function provided.
 *                                         false:	API not supported / function not provided
 */
/* Compile switch to enable and disable the Fls_SetMode function. */
	boolean FlsSetModeApi ;
/* FLS170_Conf: This parameter in conjunction with FLS_BASE_ADDRESS defines the upper boundary
 *  for read / write / erase and compare jobs.
 */
/* The total amount of flash memory in bytes (see also FLS208 and FLS209). */
	uint32 FlsTotalSize ;
/* true:	Job processing triggered by interrupt (hardware controlled).
 *                                         false:	Job processing not triggered by interrupt (software
 *  controlled)
 */
/* Job processing triggered by hardware interrupt. */
	boolean FlsUseInterrupts ;
/* true:	Version info API enabled.
 *                                         false:	Version info API disabled.
 */
/* Pre-processor switch to enable / disable the API to read out the modules version information. */
	boolean FlsVersionInfoApi ;
} Fls_GeneralType ;

/* Additional published parameters not covered by CommonPublishedInformation container. */
typedef struct Fls_PublishedInformationType_tag
{
/* Only relevant if the erase flash access code is not position independent. If this information
 *  is not provided it is assumed that the erase flash access code is position independent and
 *  that therefore the RAM position can be freely configured.
 */
/* Position in RAM, to which the erase flash access code has to be loaded. */
	uint32 FlsAcLocationErase ;
/* Only relevant if the write flash access code is not position independent. If this information
 *  is not provided it is assumed that the write flash access code is position independent and
 *  that therefore the RAM position can be freely configured.
 */
/* Position in RAM, to which the write flash access code has to be loaded. */
	uint32 FlsAcLocationWrite ;
/* Number of bytes in RAM needed for the erase flash access code. */
	uint32 FlsAcSizeErase ;
/* Number of bytes in RAM needed for the write flash access code. */
	uint32 FlsAcSizeWrite ;
/* Maximum time to erase one complete flash sector. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FlsEraseTime ;
/* The contents of an erased flash memory cell. */
	uint32 FlsErasedValue ;
/* Only relevant for external flash drivers. */
/* Unique identifier of the hardware device that is expected by this driver (the device for which
 *  this driver has been implemented).
 */
	char* FlsExpectedHwId ;
/* FLS198: If the number of specified erase cycles depends on the operating environment (temperature,
 *  voltage, ...) during reprogramming of the flash device, the minimum number for which a data
 *  retention of at least 15 years over the temperature range from -40C .. +125C can be guaranteed
 *  shall be given.
 * 
 *                                         Note: If there are different numbers of specified erase
 *  cycles for different flash sectors of the device this parameter has to be extended to a parameter
 *  list (similar to the sector list above).
 */
/* Number of erase cycles specified for the flash device (usually given in the device data sheet). */
	uint32 FlsSpecifiedEraseCycles ;
/* Maximum time to program one complete flash page. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 FlsWriteTime ;
} Fls_PublishedInformationType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* FLS_TYPES_H */
