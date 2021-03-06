/****************************************************************************
*  Copyright 2018 Gorgon Meducer (Email:embedded_zhuoran@hotmail.com)       *
*                                                                           *
*  Licensed under the Apache License, Version 2.0 (the "License");          *
*  you may not use this file except in compliance with the License.         *
*  You may obtain a copy of the License at                                  *
*                                                                           *
*     http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                           *
*  Unless required by applicable law or agreed to in writing, software      *
*  distributed under the License is distributed on an "AS IS" BASIS,        *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
*  See the License for the specific language governing permissions and      *
*  limitations under the License.                                           *
*                                                                           *
****************************************************************************/

#ifndef __DELEGATE_H__
#define __DELEGATE_H__

/*============================ INCLUDES ======================================*/
#include ".\ooc.h"
#include ".\app_type.h"
#include ".\error.h"

/*============================ MACROS ========================================*/
/*============================ MACROFIED FUNCTIONS ===========================*/
/*============================ TYPES =========================================*/

typedef fsm_rt_t DELEGATE_HANDLE_FUNC(void *pArg, void *pParam);


declare_class( DELEGATE_HANDLE )
//! \name general event handler
//! @{
extern_class( DELEGATE_HANDLE )
    DELEGATE_HANDLE_FUNC   *fnHandler;                                          //!< event handler
    void                   *pArg;                                               //!< Argument
    DELEGATE_HANDLE        *ptNext;                                             //!< next 
end_extern_class(DELEGATE_HANDLE)
//! @}

declare_class( DELEGATE )
//! \name event
//! @{
extern_class(DELEGATE)
    DELEGATE_HANDLE     *ptEvent;
    DELEGATE_HANDLE     *ptBlockedList;
    DELEGATE_HANDLE     **pptHandler;
end_extern_class(DELEGATE)
//! @}

/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/


/*! \brief initialize event 
 *! \param ptEvent target event
 *! \return the address of event item
 */
extern DELEGATE *delegate_init(DELEGATE *ptEvent);

/*! \brief initialize event handler item
 *! \param ptHandler the target event handler item
 *! \param fnRoutine event handler routine
 *! \param pArg handler extra arguments
 *! \return the address of event handler item
 */
extern DELEGATE_HANDLE *delegate_handler_init(
    DELEGATE_HANDLE *ptHandler, DELEGATE_HANDLE_FUNC *fnRoutine, void *pArg);

/*! \brief register event handler to specified event
 *! \param ptEvent target event
 *! \param ptHandler target event handler
 *! \return access result
 */
extern gsf_err_t register_delegate_handler(DELEGATE *ptEvent, DELEGATE_HANDLE *ptHandler);

/*! \brief unregister a specified event handler
 *! \param ptEvent target event
 *! \param ptHandler target event handler
 *! \return access result
 */
extern gsf_err_t unregister_delegate_handler( DELEGATE *ptEvent, DELEGATE_HANDLE *ptHandler);

/*! \brief raise target event
 *! \param ptEvent the target event
 *! \param pArg event argument
 *! \return access result
 */
extern fsm_rt_t invoke_delegate( DELEGATE *ptEvent, void *pParam);

#endif
/* EOF */
