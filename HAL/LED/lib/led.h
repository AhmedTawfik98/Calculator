/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  led.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef LED_H_
#define LED_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "led_types.h"
#include "led_cfg.h"
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
void led_init();
void led_on(led_id_t ledId);
void led_off(led_id_t ledId);
void led_toggle(led_id_t ledId);
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: led.h
 *********************************************************************************************************************/
