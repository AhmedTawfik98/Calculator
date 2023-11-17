/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  button.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef BUTTON_H_
#define BUTTON_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "button_types.h"
#include "button_cfg.h"
#include "dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void button_init(void);
button_status_t button_getStatus(button_id_t buttonId);

#endif  /* BUTTON_H */

/**********************************************************************************************************************
 *  END OF FILE: button.h
 *********************************************************************************************************************/
