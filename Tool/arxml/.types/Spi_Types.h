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
#ifndef SPI_TYPES_H
#define SPI_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* Buffer usage with EB/IB channel. */
typedef enum
{
	SPI_CHANNELTYPE_EB,
	SPI_CHANNELTYPE_IB
} Spi_ChannelTypeType ;

/* This parameter defines the first starting bit for transmission. */
typedef enum
{
	SPI_TRANSFERSTART_LSB,
	SPI_TRANSFERSTART_MSB
} Spi_TransferStartType ;

/* All data needed to configure one SPI-channel */
typedef struct Spi_ChannelType_tag
{
/* SPI Channel ID, used as parameter in SPI API functions. */
	uint8 SpiChannelId ;
	Spi_ChannelTypeType SpiChannelType ;
/* This parameter is the width of a transmitted data unit. */
	uint8 SpiDataWidth ;
/* The default data to be transmitted when (for internal buffer or external buffer) the pointer
 *  passed to Spi_WriteIB (for internal buffer) or to Spi_SetupEB (for external buffer) is NULL.
 */
	uint32 SpiDefaultData ;
/* This parameter contains the maximum size (in bytes) of data buffers in case of EB Channels and
 *  only.
 */
	uint16 SpiEbMaxLength ;
/* This parameter contains the maximum number of data buffers in case of IB Channels and only. */
	uint16 SpiIbNBuffers ;
	Spi_TransferStartType SpiTransferStart ;
} Spi_ChannelType ;

/* Container for the references to DemEventParameter elements which shall be invoked using the
 *  API Dem_ReportErrorStatus API in case the corresponding error occurs. The EventId is taken
 *  from the referenced DemEventParameter's DemEventId value. The standardized errors are provided
 *  in the container and can be extended by vendor specific error references.
 */
typedef struct Spi_DemEventParameterRefsType_tag
{
/* Reference to the DemEventParameter which shall be issued when a hardware error was detected.
 *  If the reference is not configured the error shall not be reported.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* SPI_E_HARDWARE_ERROR ;
} Spi_DemEventParameterRefsType ;

/* This parameter defines the active polarity of Chip Select. */
typedef enum
{
	SPI_CSPOLARITY_HIGH,
	SPI_CSPOLARITY_LOW
} Spi_CsPolarityType ;

/* When the Chip select handling is enabled (see SpiEnableCs), then this parameter specifies if
 *  the chip select is handled automatically by Peripheral HW engine or via general purpose IO
 *  by Spi driver.
 */
typedef enum
{
	SPI_CSSELECTION_CS_VIA_GPIO,
	SPI_CSSELECTION_CS_VIA_PERIPHERAL_ENGINE
} Spi_CsSelectionType ;

/* This parameter defines the SPI data shift edge. */
typedef enum
{
	SPI_DATASHIFTEDGE_LEADING,
	SPI_DATASHIFTEDGE_TRAILING
} Spi_DataShiftEdgeType ;

/* This parameter is the symbolic name to identify the HW SPI Hardware */
typedef enum
{
	SPI_HWUNIT_CSIB0,
	SPI_HWUNIT_CSIB1,
	SPI_HWUNIT_CSIB2,
	SPI_HWUNIT_CSIB3
} Spi_HwUnitType ;

/* This parameter defines the SPI shift clock idle level. */
typedef enum
{
	SPI_SHIFTCLOCKIDLELEVEL_HIGH,
	SPI_SHIFTCLOCKIDLELEVEL_LOW
} Spi_ShiftClockIdleLevelType ;

/* The communication settings of an external device. Closely linked to SpiJob. */
typedef struct Spi_ExternalDeviceType_tag
{
/* using a range of values, from the point of view of configuration tools,
 *                                                 from Hz up to MHz.
 */
/* This parameter is the communication baudrate - This parameter allows */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 SpiBaudrate ;
/* This parameter is the symbolic name to identify the Chip Select (CS) allocated to this Job. */
	char* SpiCsIdentifier ;
	Spi_CsPolarityType SpiCsPolarity ;
	Spi_CsSelectionType SpiCsSelection ;
	Spi_DataShiftEdgeType SpiDataShiftEdge ;
/* This parameter enables or not the Chip Select handling functions. If this parameter is enabled
 *  then parameter SpiCsSelection further details the type of chip selection.
 */
	boolean SpiEnableCs ;
/* microcontroller peripheral allocated to this Job. */
	Spi_HwUnitType SpiHwUnit ;
	Spi_ShiftClockIdleLevelType SpiShiftClockIdleLevel ;
/* The real configuration-value used in software BSW-SPI is calculated out of this by the generator-tools
 */
/* Timing between clock and chip select (in seconds) - This parameter allows to use a range of
 *  values from 0 up to 0.0001 seconds.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 SpiTimeClk2Cs ;
} Spi_ExternalDeviceType ;

/* References to SPI channels and their order within the Job. */
typedef struct Spi_ChannelListType_tag
{
/* This parameter specifies the order of Channels within the Job. */
	uint8 SpiChannelIndex ;
/* A job reference to a SPI channel. */
/* /AUTOSAR/EcucDefs/Spi/SpiDriver/SpiChannel */
	Spi_ChannelType* SpiChannelAssignment ;
} Spi_ChannelListType ;

/* If SpiHwUnitSynchronous is set to "SYNCHRONOUS", the SpiJob uses its containing SpiDriver in
 *  a synchronous manner. If it is set to "ASYNCHRONOUS", it uses the driver in an asynchronous
 *  way. If the parameter is not set, the SpiChannel uses the driver also in an asynchronous way.
 */
typedef enum
{
	SPI_HWUNITSYNCHRONOUS_ASYNCHRONOUS,
	SPI_HWUNITSYNCHRONOUS_SYNCHRONOUS
} Spi_HwUnitSynchronousType ;

/* This parameter is a reference to a notification function. */
/* TODO: 
 * typedef void (*Spi_JobEndNotificationType)(void);
 */

/* All data needed to configure one SPI-Job, amongst others the connection between the internal
 *  SPI unit and the special settings for an external device is done.
 */
typedef struct Spi_JobType_tag
{
	Spi_ChannelListType* SpiChannelList ;
	Spi_HwUnitSynchronousType SpiHwUnitSynchronous ;
	Spi_JobEndNotificationType SpiJobEndNotification ;
/* SPI Job ID, used as parameter in SPI API functions. */
	uint16 SpiJobId ;
/* Priority set accordingly to SPI093: 0, lowest, 3, highest priority */
	uint8 SpiJobPriority ;
/* Reference to the external device used by this job */
/* /AUTOSAR/EcucDefs/Spi/SpiDriver/SpiExternalDevice */
	Spi_ExternalDeviceType* SpiDeviceAssignment ;
} Spi_JobType ;

/* This parameter is a reference to a notification function. */
/* TODO: 
 * typedef void (*Spi_SeqEndNotificationType)(void);
 */

/* All data needed to configure one SPI-sequence */
typedef struct Spi_SequenceType_tag
{
/* This parameter allows or not this Sequence to be suspended by another one. */
	boolean SpiInterruptibleSequence ;
	Spi_SeqEndNotificationType SpiSeqEndNotification ;
/* SPI Sequence ID, used as parameter in SPI API functions. */
	uint8 SpiSequenceId ;
/* A sequence references several jobs, which are executed during a communication sequence */
/* /AUTOSAR/EcucDefs/Spi/SpiDriver/SpiJob */
	Spi_JobType* SpiJobAssignment ;
} Spi_SequenceType ;

/* Configuration of one instance (if multiplicity is 1, it is the sole configuration) of an SPI
 *  driver.
 */
typedef struct Spi_DriverType_tag
{
	Spi_ChannelType* SpiChannel ;
	Spi_DemEventParameterRefsType* SpiDemEventParameterRefs ;
	Spi_ExternalDeviceType* SpiExternalDevice ;
	Spi_JobType* SpiJob ;
	Spi_SequenceType* SpiSequence ;
/* This parameter contains the number of Channels configured. It will be gathered by tools during
 *  the configuration stage.
 */
	uint8 SpiMaxChannel ;
/* Total number of Jobs configured. */
	uint16 SpiMaxJob ;
/* Total number of Sequences configured. */
	uint8 SpiMaxSequence ;
} Spi_DriverType ;

/* General configuration settings for SPI-Handler */
typedef struct Spi_GeneralType_tag
{
/* Switches the Spi_Cancel function ON or OFF. */
	boolean SpiCancelApi ;
/* delivered.
 * 
 *                                         IB = 0; 
 *                                         EB = 1;  
 *                                         IB/EB = 2;
 */
/* Selects the SPI Handler/Driver Channel Buffers usage allowed and */
	uint8 SpiChannelBuffersAllowed ;
/* Switches the Development Error Detection and Notification ON or OFF. */
	boolean SpiDevErrorDetect ;
/* Switches the Spi_GetHWUnitStatus function ON or OFF. */
	boolean SpiHwStatusApi ;
/* Switches the Interruptible Sequences handling functionality ON or OFF. */
	boolean SpiInterruptibleSeqAllowed ;
/* available and delivered. */
/* Selects the SPI Handler/Driver level of scalable functionality that is */
	uint8 SpiLevelDelivered ;
/* Specifies whether concurrent Spi_SyncTransmit() calls for different sequences shall be configurable.
 */
	boolean SpiSupportConcurrentSyncTransmit ;
/* Switches the Spi_GetVersionInfo function ON or OFF. */
	boolean SpiVersionInfoApi ;
} Spi_GeneralType ;

/* Container holding all SPI specific published information parameters */
typedef struct Spi_PublishedInformationType_tag
{
/* Number of different SPI hardware microcontroller peripherals (units/busses) available and handled
 *  by this SPI Handler/Driver module.
 */
	uint64 SpiMaxHwUnit ;
} Spi_PublishedInformationType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* SPI_TYPES_H */
