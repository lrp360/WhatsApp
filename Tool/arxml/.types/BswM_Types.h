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
#ifndef BSWM_TYPES_H
#define BSWM_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* This parameter specifies the logical operator to be used in the logical expression. If the expression
 *  only consists of a single condition this parameter shall not be used.
 */
typedef enum
{
	BSWM_AND,
	BSWM_NAND,
	BSWM_OR,
	BSWM_XOR
} BswM_LogicalOperatorType ;

/* This container describes the logical expressions that can be used for the mode arbitration.
 *  The logical expressions are built of a set of arguments and a logical operator.
 */
typedef struct BswM_LogicalExpressionType_tag
{
	BswM_LogicalOperatorType BswMLogicalOperator ;
/* This is a choice reference either to a mode condition or a sub-expression. */
/* In case the BswMLogicalExpression.BswMLogicalOperator equals BSWM_NAND only two operands are
 *  supported.
 */
	uint8 BswMArgumentRefWhich;
	union
	{
/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMArbitration/BswMLogicalExpression */
		BswM_LogicalExpressionType* BswMLogicalExpression;
/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMArbitration/BswMModeCondition */
		BswM_ModeConditionType* BswMModeCondition;
	} BswMArgumentRef ;
} BswM_LogicalExpressionType ;

/* This container holds the parameters and references necessary to identify the mode type and the
 *  value that the mode request is compared to.
 */
typedef struct BswM_ConditionValueType_tag
{
} BswM_ConditionValueType ;

/* This parameter specifies what kind of comparison that is made for the evaluation of the mode
 *  condition.
 */
typedef enum
{
	BSWM_EQUALS,
	BSWM_EQUALS_NOT
} BswM_ConditionTypeType ;

/* This container describes the BswM mode conditions that can be used either by itself to form
 *  a rule or as a part of a logical expression.
 */
typedef struct BswM_ModeConditionType_tag
{
	BswM_ConditionValueType* BswMConditionValue ;
	BswM_ConditionTypeType BswMConditionType ;
/* This parameter references the mode request port that is used for the condition. */
/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMArbitration/BswMModeRequestPort */
	BswM_ModeRequestPortType* BswMConditionMode ;
} BswM_ModeConditionType ;

/* This container defines the initial mode value that is used by BswM for the corresponding mode
 *  request after initialization. This container is optional and shall only be used for Mode Requests
 *  that do not already have an initial value.
 */
typedef struct BswM_ModeInitValueType_tag
{
} BswM_ModeInitValueType ;

/* This choice container specifies the source of the mode request or state/mode indication. The
 *  requester of a mode can be both SW-C:s and other BSW Modules, such as the bus specific State
 *  Managers.
 */
typedef struct BswM_ModeRequestSourceType_tag
{
} BswM_ModeRequestSourceType ;

/* This parameter defines if the processing of the mode arbitration shall be done immediately when
 *  a mode request is received or if it shall be deferred to the processing of the main function
 *  of BswM.
 */
typedef enum
{
	BSWM_DEFERRED,
	BSWM_IMMEDIATE
} BswM_RequestProcessingType ;

/* Each instance of this container defines a mode request interface that is used to requests or
 *  indicate modes from/to the BswM. These interfaces are implemented as ports or as ordinary C-functions
 *  based upon if the request is made by an SW-C or a BSW module.
 */
typedef struct BswM_ModeRequestPortType_tag
{
/* If this container is not present the requested mode is undefined after initialization of BswM.
 *  The requested mode will remain undefined until the requester performs a request.
 */
	BswM_ModeInitValueType* BswMModeInitValue ;
	BswM_ModeRequestSourceType* BswMModeRequestSource ;
	BswM_RequestProcessingType BswMRequestProcessing ;
} BswM_ModeRequestPortType ;

/* This parameter is a part of the reset/initialization behavior of BswM. */
typedef enum
{
	BSWM_FALSE,
	BSWM_TRUE,
	BSWM_UNDEFINED
} BswM_RuleInitStateType ;

/* Each instance of this container describes a BswM arbitration rule. The rule either consists
 *  of a simple mode condition or a more complex logical expression. This container also references
 *  the action lists that shall be invoked when the rule is evaluated to True or False.
 */
typedef struct BswM_RuleType_tag
{
/* false: an Independent rule, i.e. to be evaluated each time applicable (both as standalone Rule
 *  driven by its own BswMModeRequestSource and when referenced by another Rule).
 * 
 *                                                         true: a Subordinated rule, to be evaluated
 *  ONLY as a result of being referenced in one or more Action Lists.
 */
/* This parameter defines for its related Rule if the Rule is an Independent rule or a Subordinate
 *  rule;
 */
	boolean BswMNestedExecutionOnly ;
/* Action lists are executed when the result of a rule evaluation have changed since the last evaluation.
 *  This parameter defines the "previous evaluation result" of a rule to be used after initialization
 *  of the BswM.
 * 
 *                                                         If this parameter is set to BSWM_UNDEFINED,
 *  the evaluation result is always treated as changed at the first evaluation of the rule after
 *  initialization.
 * 
 *                                                         If this parameter is set to BSWM_TRUE,
 *  the evaluation result is treated as changed if the rule is evaluated to false. 
 * 
 *                                                         If this parameter is set to BSWM_FALSE,
 *  the evaluation result is treated as changed if the rule is evaluated to true.
 */
	BswM_RuleInitStateType BswMRuleInitState ;
/* This choice reference either references the mode condition or the logical expression that is
 *  evaluated for each rule.
 */
/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMArbitration/BswMLogicalExpression */
	BswM_LogicalExpressionType* BswMRuleExpressionRef ;
/* This is a reference to the action list that shall be executed when the rule is evaluated to False */
/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMModeControl/BswMActionList */
	BswM_ActionListType* BswMRuleFalseActionList ;
/* This is a reference to the action list that shall be executed when the rule is evaluated to True */
/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMModeControl/BswMActionList */
	BswM_ActionListType* BswMRuleTrueActionList ;
} BswM_RuleType ;

/* This container includes all configuration sub-containers and parameters related to the mode
 *  arbitration functionality of the BswM.
 */
typedef struct BswM_ArbitrationType_tag
{
/* Each argument can either be a mode condition or a sub-expression to allow definition of more
 *  complex logical expressions.
 *                                                 There may be an unlimited number of arguments
 *  in each logical expression.
 *                                                 Note that the order of evaluation of the expressions
 *  is not defined.
 */
	BswM_LogicalExpressionType* BswMLogicalExpression ;
	BswM_ModeConditionType* BswMModeCondition ;
/* There are different types of mode requests:
 *                                                 1. Mode requests from the SW-C:s
 *                                                 2. Mode Requests from other BSW modules such
 *  as the DCM. 
 *                                                 3. State/mode indications from the RTE or other
 *  BSW modules such as the bus specific State Managers.
 * 
 *                                                 Note that the BswM treats all request and indications
 *  in the exact same way.
 */
	BswM_ModeRequestPortType* BswMModeRequestPort ;
	BswM_RuleType* BswMRule ;
} BswM_ArbitrationType ;

/* Collection of references to DataTypeMappingSet. */
typedef struct BswM_DataTypeMappingSetsType_tag
{
/* Reference to DataTypeMappingSet. */
	/*TODO:DATA-TYPE-MAPPING-SET*/void* BswMDataTypeMappingSetRef ;
} BswM_DataTypeMappingSetsType ;

/* Choice container including the available actions to be used in the action lists. */
typedef struct BswM_AvailableActionsType_tag
{
} BswM_AvailableActionsType ;

/* Each container of this type defines an action. These actions can be part of one or several action
 *  lists.
 */
typedef struct BswM_ActionType_tag
{
	BswM_AvailableActionsType* BswMAvailableActions ;
} BswM_ActionType ;

/* This container defines an item in an action list. */
typedef struct BswM_ActionListItemType_tag
{
/* This parameter defines if the execution of the action list shall be aborted if this specific
 *  action returns E_NOT_OK. Note that this is only applicable for actions that have E_NOT_OK as
 *  a possible return value.
 */
	boolean BswMAbortOnFail ;
/* This parameter defines the index of the action in the action list. It is used define in which
 *  order the actions shall be performed.
 */
	uint8 BswMActionListItemIndex ;
/* The action item can either be an atomic action or a reference to another action list or rule. */
	uint8 BswMActionListItemRefWhich;
	union
	{
/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMModeControl/BswMAction */
		BswM_ActionType* BswMAction;
/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMModeControl/BswMActionList */
		BswM_ActionListType* BswMActionList;
/* /AUTOSAR/EcucDefs/BswM/BswMConfig/BswMArbitration/BswMRule */
		BswM_RuleType* BswMRule;
	} BswMActionListItemRef ;
/* If the reference is given, the DEM event shall be reported failed if this specific action returns
 *  E_NOT_OK; it shall be reported passed if this specific action returns E_OK.
 */
/* /AUTOSAR/EcucDefs/Dem/DemConfigSet/DemEventParameter */
	Dem_EventParameterType* BswMReportFailToDemRef ;
} BswM_ActionListItemType ;

/* This parameter controls if the corresponding action list shall be executed every time the rule
 *  is evaluated or only when the result of the evaluation changes.
 */
typedef enum
{
	BSWM_CONDITION,
	BSWM_TRIGGER
} BswM_ActionListExecutionType ;

/* Each instance of this container defines an action list that is invoked based on the BswM Rules.
 *  An action list contains a list of numbered action items to be processed. An action list can
 *  also include other action lists.
 */
typedef struct BswM_ActionListType_tag
{
	BswM_ActionListItemType* BswMActionListItem ;
	BswM_ActionListExecutionType BswMActionListExecution ;
} BswM_ActionListType ;

/* This container specifies PPorts and/or providedModeDeclarationGroups, which the BswM has to
 *  create in its SWCD resp. BSWMD.
 */
typedef struct BswM_SwitchPortType_tag
{
/* Reference to the ModeSwitchInterface of this BswMModeSwitchPort. */
	/*TODO:MODE-SWITCH-INTERFACE*/void* BswMModeSwitchInterfaceRef ;
} BswM_SwitchPortType ;

/* This container includes all configuration sub-containers and parameters related to the mode
 *  control functionality of the BswM.
 */
typedef struct BswM_ModeControlType_tag
{
	BswM_ActionType* BswMAction ;
	BswM_ActionListType* BswMActionList ;
/* If the container is referenced by one or more BswMRteSwitchActions the BswM shall create a corresponding
 *  PPort in its Service Description.
 * 
 *                                                 If the container is referenced by a BswMSchMSwitch
 *  action the BswM shall create the corresponding ModeDeaclarationGroupPrototype as providedModeDeclarationGroup
 *  in it BSWMD.
 * 
 *                                                 If the container is referenced by BswMSchMSwitch
 *  AND BswmRteSwitchActions the a providedModeDeclarationGroup as well as a PPort shall be created.
 *  In the corresponding SwcBswMapping a synchronizedModeGroup has to be created. See also chapter
 *  4.4.7 in SWS_RTE.
 */
	BswM_SwitchPortType* BswMSwitchPort ;
} BswM_ModeControlType ;

/* Collection of header file names which shall be included by the BswM. */
typedef struct BswM_UserIncludeFilesType_tag
{
/* The value of this parameter shall be used as h-char-sequence or q-char-sequence according to
 *  ISO C90 section 6.10.2 "source file inclusion".
 * 
 *                                                 The parameter value MUST NOT represent a path,
 *  since ISO C90 does not specify how such a path is treated (i.e., this is implementation defined
 *  (and additionally depends on the operating system and the underlying file system)).
 */
/* Header file name which shall be included by the BswM. */
	char* BswMUserIncludeFile ;
} BswM_UserIncludeFilesType ;

/* This container contains the configuration parameters and sub containers of the AUTOSAR BswM
 *  module. This container is a MultipleConfigurationContainer, i.e. this container and its sub-containers
 *  exist once per configuration set.
 */
typedef struct BswM_ConfigType_tag
{
	BswM_ArbitrationType* BswMArbitration ;
	BswM_DataTypeMappingSetsType* BswMDataTypeMappingSets ;
	BswM_ModeControlType* BswMModeControl ;
} BswM_ConfigType ;

/* General configuration parameters of the Basic SW Mode Manager. */
typedef struct BswM_GeneralType_tag
{
	BswM_UserIncludeFilesType* BswMUserIncludeFiles ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable CanSM module related BswM API: */
	boolean BswMCanSMEnabled ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable ComM module related BswM API: */
	boolean BswMComMEnabled ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable Dcm module related BswM API: */
	boolean BswMDcmEnabled ;
/* true: Enabled
                                        false: Disabled */
/* Switches the Development Error Detection and Notification ON or OFF. */
	boolean BswMDevErrorDetect ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable EcuM module related BswM API: */
	boolean BswMEcuMEnabled ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable EthSM module related BswM API: */
	boolean BswMEthSMEnabled ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable FrSM module related BswM API: */
	boolean BswMFrSMEnabled ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable Generic Request related BswM API: */
	boolean BswMGenericRequestEnabled ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable LinSM module related BswM API: */
	boolean BswMLinSMEnabled ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable LinTP module related BswM API: */
	boolean BswMLinTPEnabled ;
/* The cycle time of the periodic main function of BswM. Defined in seconds . */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 BswMMainFunctionPeriod ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable NvM module related BswM API: */
	boolean BswMNvMEnabled ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable SchM module related BswM API: */
	boolean BswMSchMEnabled ;
/* true: Enabled
                                        false: Disabled */
/* Switches the possibility to read the version information with the service BswM_GetVersionInfo(). */
	boolean BswMVersionInfoApi ;
/* true: Enabled
                                        false: Disabled */
/* enable/disable WdgM module related BswM API: */
	boolean BswMWdgMEnabled ;
} BswM_GeneralType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* BSWM_TYPES_H */
