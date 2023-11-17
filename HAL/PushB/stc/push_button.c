/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  led.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "button.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void button_init(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                        
* \Return value:   : None                               
*******************************************************************************/
void button_vidinit(void)
{
	dio_vidConfigChannel(BUTTON1_PORT, BUTTON1_PIN, INPUT);
	dio_vidConfigChannel(BUTTON2_PORT, BUTTON2_PIN, INPUT);
	dio_vidConfigChannel(BUTTON3_PORT, BUTTON3_PIN, INPUT);
	dio_vidConfigChannel(BUTTON4_PORT, BUTTON4_PIN, INPUT);
}

/******************************************************************************
* \Syntax          : button_status_t button_getStatus(button_id_t buttonId)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ledId	-> led id                                                                        
* \Return value:   : None                               
*******************************************************************************/
button_status_t button_enuGetStatus(button_id_t buttonId)
{
	button_status_t buttonStatus = RELEASED;
	switch (buttonId)
	{
		case BUTTON1:
			#if (BUTTON1_CONNECTION == PULL_UP)
				 if (dio_dioLevelReadChannel(BUTTON1_PORT, BUTTON1_PIN) == STD_LOW)
				 {
					buttonStatus = PRESSED;
				 }
				 else
				 {
					buttonStatus = RELEASED;
				 }
			#elif (BUTTON1_CONNECTION == PULL_DOWEN)
				if (dio_dioLevelReadChannel(BUTTON1_PORT, BUTTON1_PIN) == STD_HIGH)
				 {
					buttonStatus = PRESSED;
				 }
				 else
				 {
					buttonStatus = RELEASED;
				 }
			#else
				#error "You Must Define The BUTTON Connection Type"
			#endif
		break;
		
		case BUTTON2:
			#if (BUTTON2_CONNECTION == PULL_UP)
				 if (dio_dioLevelReadChannel(BUTTON2_PORT, BUTTON2_PIN) == STD_LOW)
				 {
					buttonStatus = PRESSED;
				 }
				 else
				 {
					buttonStatus = RELEASED;
				 }
			#elif (BUTTON2_CONNECTION == PULL_DOWEN)
				if (dio_dioLevelReadChannel(BUTTON2_PORT, BUTTON2_PIN) == STD_HIGH)
				 {
					buttonStatus = PRESSED;
				 }
				 else
				 {
					buttonStatus = RELEASED;
				 }
			#else
				#error "You Must Define The BUTTON Connection Type"
			#endif		
			break;
		
		case BUTTON3:
			#if (BUTTON3_CONNECTION == PULL_UP)
				 if (dio_dioLevelReadChannel(BUTTON3_PORT, BUTTON3_PIN) == STD_LOW)
				 {
					buttonStatus = PRESSED;
				 }
				 else
				 {
					buttonStatus = RELEASED;
				 }
			#elif (BUTTON3_CONNECTION == PULL_DOWEN)
				if (dio_dioLevelReadChannel(BUTTON3_PORT, BUTTON3_PIN) == STD_HIGH)
				 {
					buttonStatus = PRESSED;
				 }
				 else
				 {
					buttonStatus = RELEASED;
				 }
			#else
				#error "You Must Define The BUTTON Connection Type"
			#endif		
			break;
		
		case BUTTON4:
			#if (BUTTON4_CONNECTION == PULL_UP)
				 if (dio_dioLevelReadChannel(BUTTON4_PORT, BUTTON4_PIN) == STD_LOW)
				 {
					buttonStatus = PRESSED;
				 }
				 else
				 {
					buttonStatus = RELEASED;
				 }
			#elif (BUTTON4_CONNECTION == PULL_DOWEN)
				if (dio_dioLevelReadChannel(BUTTON4_PORT, BUTTON4_PIN) == STD_HIGH)
				 {
					buttonStatus = PRESSED;
				 }
				 else
				 {
					buttonStatus = RELEASED;
				 }
			#else
				#error "You Must Define The BUTTON Connection Type"
			#endif		
			break;
	}
	return buttonStatus;
}

/**********************************************************************************************************************
 *  END OF FILE: led.c
 *********************************************************************************************************************/
