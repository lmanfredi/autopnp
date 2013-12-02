/*
 * Copyright (c) 2011-2013, fortiss GmbH.
 * Licensed under the Apache License, Version 2.0.
 *
 * Use, modification and distribution are subject to the terms specified
 * in the accompanying license file LICENSE.txt located at the root directory
 * of this software distribution. A copy is available at
 * http://chromosome.fortiss.org/.
 *
 * This file is part of CHROMOSOME.
 *
 * $Id: plugAndPlayManagerComponentWrapper.h 4893 2013-08-30 16:20:57Z wiesmueller $
 */

/**
 * \file
 *         Component wrapper - implements interface of a component
 *              to the data handler
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

#ifndef XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_H
#define XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_H

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/executionManager/include/executionManagerDataStructures.h"

// PROTECTED REGION ID(XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_H_INCLUDES) ENABLED START

#include "xme/core/topicData.h"

// PROTECTED REGION END

/******************************************************************************/
/***   Type definitions                                                     ***/
/******************************************************************************/
XME_EXTERN_C_BEGIN

/**
 * \enum   xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t
 *
 * \brief  Defines internal port ids of component 'pnpManager'.
 *
 * \details These can be used when calling the xme_core_pnp_pnpManagerComponentWrapper_receivePort function.
 *
 * \see    xme_core_pnp_pnpManagerComponentWrapper_receivePort
 */
typedef enum
{
    XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_INCOMPONENTINSTANCEMANIFEST = 0, ///< Port 'inComponentInstanceManifest'
    XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_INPNPLOGINREQUEST = 1, ///< Port 'inPnPLoginRequest'
    XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_OUTRUNTIMEGRAPH = 2, ///< Port 'outRuntimeGraph'
    XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_OUTPNPLOGINRESPONSE = 3 ///< Port 'outPnPLoginResponse'
} xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t;

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/
/**
 * \brief  Associate an internal port number with the corresponding port handle.
 *         For the ids of the individual ports, see the definition of xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t.
 *
 * \param  dataPacketId Port handle from the dataHandler.
 * \param  componentInternalPortId Component internal port number of the above port.
 * 
 * \retval XME_STATUS_SUCCESS if no problems occurred.
 * \retval XME_STATUS_INVALID_PARAMETER if componentInternalPortId is unknown.
 */
xme_status_t
xme_core_pnp_pnpManagerComponentWrapper_receivePort
(
    xme_core_dataManager_dataPacketId_t dataPacketId,
    xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t componentInternalPortId
);

/**
 * \brief  This function is called by the function wrapper after the step
 *         function has been called. It signals to the middleware that all
 *         input ports have been read.
 */
void
xme_core_pnp_pnpManagerComponentWrapper_completeReadOperations(void);

/**
 * \brief  This function is called by the function wrapper after the step
 *         function has been called. It signals to the middleware that all
 *         write operations on ports that actually have been written to 
 *         in the step function (via the functions in this component wrapper)
 *         are now completed.
 */
void
xme_core_pnp_pnpManagerComponentWrapper_completeWriteOperations(void);

/**
 * \brief  Read data from port inComponentInstanceManifest.
 *
 * \details Port description:
 *            The component instance manifest contains all the information about a joining node with the declaration of all components that this node wants to start and connect to CHROMOSOME network. 
 *
 * \param  data User provided storage, to which the data is copied.
 *
 * \retval XME_STATUS_SUCCESS if operation was successful.
 */
xme_status_t
xme_core_pnp_pnpManagerComponentWrapper_readPortInComponentInstanceManifest
(
    xme_core_topic_pnp_componentInstanceManifest_t* data
);

/**
 * \brief  Read data from port inPnPLoginRequest.
 *
 * \details Port description:
 *            This subscription listens to login manager requests for node registration. 
 *
 * \param  data User provided storage, to which the data is copied.
 *
 * \retval XME_STATUS_SUCCESS if operation was successful.
 */
xme_status_t
xme_core_pnp_pnpManagerComponentWrapper_readPortInPnPLoginRequest
(
    xme_core_topic_login_pnpLoginRequest_t* data
);

/**
 * \brief  Write data to port outRuntimeGraph.
 *
 * \details Port description:
 *          The runtime graph out is the runtime graph produced by the plug and play manager. 
 *          This graph contains the required physical networking information required for configuring a node using the plug and play infrastructure.
 *
 * \param  data User provided storage, from which the data is copied.
 *              When NULL no data will be written to the port (this
 *              is also treated as  success).
 *
 * \retval XME_STATUS_SUCCESS if operation was successful.
 */
xme_status_t
xme_core_pnp_pnpManagerComponentWrapper_writePortOutRuntimeGraph
(
    xme_core_topic_pnpManager_runtime_graph_model_t* data
);

/**
 * \brief  Write data to port outPnPLoginResponse.
 *
 * \details Port description:
 *          This publication exposes the data needed to connect remote nodes to the plug and play manager. 
 *
 * \param  data User provided storage, from which the data is copied.
 *              When NULL no data will be written to the port (this
 *              is also treated as  success).
 *
 * \retval XME_STATUS_SUCCESS if operation was successful.
 */
xme_status_t
xme_core_pnp_pnpManagerComponentWrapper_writePortOutPnPLoginResponse
(
    xme_core_topic_login_pnpLoginResponse_t* data
);


XME_EXTERN_C_END

#endif // #ifndef XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_H