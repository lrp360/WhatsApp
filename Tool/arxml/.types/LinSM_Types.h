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
#ifndef LINSM_TYPES_H
#define LINSM_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* The schedule references to a schedule that is located in the LinIf configuration. Moreover,
 *  the PDU groups are located in the COM configuration. Note that there are two references to
 *  PDU groups. The simple reason is that a PDU group is only allowed to contain one direction
 *  (TX or RX).
 */
typedef struct LinSM_ScheduleType_tag
{
/* This index parameter can be used by the BswM as a  SymbolicNameReference target. The LinSM just
 *  forwards the request from the BswM to LinIf. Note that the value of the LinSMScheduleIndex
 *  shall be the same as the value from the LinIf.
 */
	uint8 LinSMScheduleIndex ;
/* Reference to a schedule table in the LinIf configuration */
/* /AUTOSAR/EcucDefs/LinIf/LinIfGlobalConfig/LinIfChannel/LinIfScheduleTable */
	LinIf_ScheduleTableType* LinSMScheduleIndexRef ;
} LinSM_ScheduleType ;

/* Describes each LIN channel the LinSM is connected to. */
typedef struct LinSM_ChannelType_tag
{
	LinSM_ScheduleType* LinSMSchedule ;
/* Timeout in seconds for the goto sleep and wakeup calls to LinIf. The timeout must be longer
 *  than a goto-sleep command on the bus (i.e. it is bit rate dependent).
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 LinSMConfirmationTimeout ;
/* Some LIN clusters does not need sleep, they will just shut off. This parameter will affect the
 *  behavior to achieve the no communication state.
 */
	boolean LinSMSleepSupport ;
/* Selects STANDBY (true) or SLEEP (false) transceiver mode when entering LINSM_NO_COM. */
	boolean LinSMTransceiverPassiveMode ;
/* Unique handle to identify one certain LIN network. Reference to one of the network handles configured
 *  in the ComM.
 */
/* /AUTOSAR/EcucDefs/ComM/ComMConfigSet/ComMChannel */
	ComM_ChannelType* LinSMComMNetworkHandleRef ;
} LinSM_ChannelType ;

/* This container describes one of multiple configuration sets of LinSm. */
typedef struct LinSM_ConfigSetType_tag
{
	LinSM_ChannelType* LinSMChannel ;
} LinSM_ConfigSetType ;

/* This container contains general parameters of LIN State Manager module. */
typedef struct LinSM_GeneralType_tag
{
/* Switches the Development Error Detection and Notification ON or OFF. */
	boolean LinSMDevErrorDetect ;
/* Fixed period that the MainFunction shall be called. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 LinSMMainProcessingPeriod ;
/* Switches the LinSM_GetVersionInfo function ON or OFF. */
	boolean LinSMVersionInfoApi ;
} LinSM_GeneralType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* LINSM_TYPES_H */
