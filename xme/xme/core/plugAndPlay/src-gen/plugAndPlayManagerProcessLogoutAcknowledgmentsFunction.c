/*
 * Copyright (c) 2011-2014, fortiss GmbH.
 * Licensed under the Apache License, Version 2.0.
 *
 * Use, modification and distribution are subject to the terms specified
 * in the accompanying license file LICENSE.txt located at the root directory
 * of this software distribution. A copy is available at
 * http://chromosome.fortiss.org/.
 *
 * This file is part of CHROMOSOME.
 *
 * $Id: plugAndPlayManagerProcessLogoutAcknowledgmentsFunction.c 7837 2014-03-14 12:33:13Z wiesmueller $
 */

/**
 * \file
 *         Source file for function pnpManagerProcessLogoutAcknowledgments in component pnpManager.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerProcessLogoutAcknowledgmentsFunction.h"

#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerProcessLogoutAcknowledgmentsFunctionWrapper.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerComponent.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerComponentWrapper.h"
#include "xme/core/plugAndPlay/include-gen/pnpManagerManifest.h"

#include "xme/core/logUtils.h"

#include "xme/hal/include/mem.h"

// PROTECTED REGION ID(XME_CORE_PNP_PNPMANAGERPROCESSLOGOUTACKNOWLEDGMENTSFUNCTION_C_INCLUDES) ENABLED START
#include "xme/core/plugAndPlay/include/plugAndPlayManager.h"
// PROTECTED REGION END

/******************************************************************************/
/***   Definitions                                                          ***/
/******************************************************************************/

// PROTECTED REGION ID(XME_CORE_PNP_PNPMANAGERPROCESSLOGOUTACKNOWLEDGMENTSFUNCTION_C_DEFINITIONS) ENABLED START

// PROTECTED REGION END

/******************************************************************************/
/***   Variables                                                            ***/
/******************************************************************************/
/**
 * \brief  Variable holding the value of the optional output port 'outLogoutNotification'.
 *
 * \details If necessary initialize this in the init function.
 *          The value of this variable will be written to the port at the end of
 *          the step function.
 */
static xme_core_topic_pnp_logoutNotification_t
portOutLogoutNotificationData;

// PROTECTED REGION ID(XME_CORE_PNP_PNPMANAGERPROCESSLOGOUTACKNOWLEDGMENTSFUNCTION_C_VARIABLES) ENABLED START

// PROTECTED REGION END

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/

// PROTECTED REGION ID(XME_CORE_PNP_PNPMANAGERPROCESSLOGOUTACKNOWLEDGMENTSFUNCTION_C_PROTOTYPES) ENABLED START

// PROTECTED REGION END

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
xme_status_t
xme_core_pnp_pnpManagerProcessLogoutAcknowledgmentsFunction_init
(
    xme_core_pnp_pnpManagerComponent_config_t* const componentConfig
)
{
    // PROTECTED REGION ID(XME_CORE_PNP_PNPMANAGERPROCESSLOGOUTACKNOWLEDGMENTSFUNCTION_INITIALIZE_C) ENABLED START

    // Nothing to do

    XME_UNUSED_PARAMETER(componentConfig);

    return XME_STATUS_SUCCESS;

    // PROTECTED REGION END
}

void
xme_core_pnp_pnpManagerProcessLogoutAcknowledgmentsFunction_step
(
    xme_core_pnp_pnpManagerComponent_config_t* const componentConfig
)
{
    xme_status_t status[1];
    
    xme_core_topic_pnp_logoutAcknowledgment_t portInLogoutAcknowledgmentData; // Required port.
    xme_core_topic_pnp_logoutNotification_t* portOutLogoutNotificationDataPtr = &portOutLogoutNotificationData;
    
    (void)xme_hal_mem_set(&portInLogoutAcknowledgmentData, 0u, sizeof(xme_core_topic_pnp_logoutAcknowledgment_t));
    
    status[0] = xme_core_pnp_pnpManagerComponentWrapper_readPortInLogoutAcknowledgment(&portInLogoutAcknowledgmentData);
    
    {
        // PROTECTED REGION ID(XME_CORE_PNP_PNPMANAGERPROCESSLOGOUTACKNOWLEDGMENTSFUNCTION_STEP_C) ENABLED START

        XME_UNUSED_PARAMETER(componentConfig);

        if (XME_STATUS_SUCCESS == status[0])
        {
            status[0] = xme_core_pnp_pnpManager_deregisterNode(portInLogoutAcknowledgmentData.nodeId);
            if (XME_STATUS_SUCCESS != status[0])
            {
                XME_LOG
                (
                    XME_LOG_WARNING,
                    "[PnPManager] Deregisteration of node %d from pnpManager was not successful (code %d)!\n",
                    portOutLogoutNotificationData.nodeId, status[0]
                );
            }
            portOutLogoutNotificationData.nodeId = portInLogoutAcknowledgmentData.nodeId;
        }
        else
        {
            portOutLogoutNotificationDataPtr = NULL;
        }

        // PROTECTED REGION END
    }
    
    status[0] = xme_core_pnp_pnpManagerComponentWrapper_writePortOutLogoutNotification(portOutLogoutNotificationDataPtr);
    
    {
        // PROTECTED REGION ID(XME_CORE_PNP_PNPMANAGERPROCESSLOGOUTACKNOWLEDGMENTSFUNCTION_STEP_2_C) ENABLED START

        // TODO: Check return values of writePort calls here

        // PROTECTED REGION END
    }
}

void
xme_core_pnp_pnpManagerProcessLogoutAcknowledgmentsFunction_fini
(
    xme_core_pnp_pnpManagerComponent_config_t* const componentConfig
)
{
    // PROTECTED REGION ID(XME_CORE_PNP_PNPMANAGERPROCESSLOGOUTACKNOWLEDGMENTSFUNCTION_TERMINATE_C) ENABLED START

    // Nothing to do

    XME_UNUSED_PARAMETER(componentConfig);

    // PROTECTED REGION END
}

// PROTECTED REGION ID(XME_CORE_PNP_PNPMANAGERPROCESSLOGOUTACKNOWLEDGMENTSFUNCTION_IMPLEMENTATION_C) ENABLED START

// PROTECTED REGION END
