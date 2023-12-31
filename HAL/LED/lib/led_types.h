/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  led_types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef LED_TYPES_H_
#define LED_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define RED  DIO_PIN7
#define GREEN  DIO_PIN5
#define BLUE  DIO_PIN4
#define YELLOW  DIO_PIN3
   
#define STATE SOURCE		/*	LED have TWO states "Source or SINK" */

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	LED_RED,
	LED_GREEN,
	LED_BLUE,
	LED_YELLOW
}led_id_t;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: led.h
 *********************************************************************************************************************/
