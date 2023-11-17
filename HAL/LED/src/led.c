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
#include "led.h"
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
* \Syntax          : void led_init(void)       
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                                                                        
* \Return value:   : None                               
*******************************************************************************/
void led_init(void)
{
	dio_vidConfigChannel(RED_LED_PORT, RED_LED_PIN, OUTPUT);
	dio_vidConfigChannel(GREEN_LED_PORT, GREEN_LED_PIN, OUTPUT);
	dio_vidConfigChannel(BLUE_LED_PORT, BLUE_LED_PIN, OUTPUT);
	dio_vidConfigChannel(YELLOW_LED_PORT, YELLOW_LED_PIN, OUTPUT);
}

/******************************************************************************
* \Syntax          : void led_on(led_id_t ledId)      
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ledId	-> led id                                                                        
* \Return value:   : None                               
*******************************************************************************/
void led_on(led_id_t ledId)
{
	switch (ledId)
	{
		case LED_RED:
			#if (RED_LED_CONNECTION == SOURCE)
				 dio_vidWriteChannel(RED_LED_PORT, RED_LED_PIN, STD_HIGH);
			#elif (RED_LED_CONNECTION == SINK)
				 dio_vidWriteChannel(RED_LED_PORT, RED_LED_PIN, STD_LOW);
			#else
				#error "You Must Define The LED Connection Type"
			#endif
		break;
		
		case LED_GREEN:
			#if (GREEN_LED_CONNECTION == SOURCE)
				 dio_vidWriteChannel(GREEN_LED_PORT, GREEN_LED_PIN, STD_HIGH);
			#elif (GREEN_LED_CONNECTION == SINK)
				 dio_vidWriteChannel(GREEN_LED_PORT, GREEN_LED_PIN, STD_LOW);
			#else
				#error "You Must Define The LED Connection Type"
			#endif
		break;
		
		case LED_BLUE:
			#if (BLUE_LED_CONNECTION == SOURCE)
				 dio_vidWriteChannel(BLUE_LED_PORT, BLUE_LED_PIN, STD_HIGH);
			#elif (BLUE_LED_CONNECTION == SINK)
				 dio_vidWriteChannel(BLUE_LED_PORT, BLUE_LED_PIN, STD_LOW);
			#else
				#error "You Must Define The LED Connection Type"
			#endif
		break;
		
		case LED_YELLOW:
			#if (YELLOW_LED_CONNECTION == SOURCE)
				 dio_vidWriteChannel(YELLOW_LED_PORT, YELLOW_LED_PIN, STD_HIGH);
			#elif (YELLOW_LED_CONNECTION == SINK)
				 dio_vidWriteChannel(YELLOW_LED_PORT, YELLOW_LED_PIN, STD_LOW);
			#else
				#error "You Must Define The LED Connection Type"
			#endif
		break;
	}
}


void led_off(led_id_t ledId)
{
switch (ledId)
{
	case LED_RED:
	#if (RED_LED_CONNECTION == SOURCE)
	dio_vidWriteChannel(RED_LED_PORT, RED_LED_PIN, STD_LOW);
	#elif (RED_LED_CONNECTION == SINK)
	dio_vidWriteChannel(RED_LED_PORT, RED_LED_PIN, STD_HIGH);
	#else
	#error "You Must Define The LED Connection Type"
	#endif
	break;
	
	case LED_GREEN:
	#if (GREEN_LED_CONNECTION == SOURCE)
	dio_vidWriteChannel(GREEN_LED_PORT, GREEN_LED_PIN, STD_LOW);
	#elif (GREEN_LED_CONNECTION == SINK)
	dio_vidWriteChannel(GREEN_LED_PORT, GREEN_LED_PIN, STD_HIGH);
	#else
	#error "You Must Define The LED Connection Type"
	#endif
	break;
	
	case LED_BLUE:
	#if (BLUE_LED_CONNECTION == SOURCE)
	dio_vidWriteChannel(BLUE_LED_PORT, BLUE_LED_PIN, STD_LOW);
	#elif (BLUE_LED_CONNECTION == SINK)
	dio_vidWriteChannel(BLUE_LED_PORT, BLUE_LED_PIN, STD_HIGH);
	#else
	#error "You Must Define The LED Connection Type"
	#endif
	break;
	
	case LED_YELLOW:
	#if (YELLOW_LED_CONNECTION == SOURCE)
	dio_vidWriteChannel(YELLOW_LED_PORT, YELLOW_LED_PIN, STD_LOW);
	#elif (YELLOW_LED_CONNECTION == SINK)
	dio_vidWriteChannel(YELLOW_LED_PORT, YELLOW_LED_PIN, STD_HIGH);
	#else
	#error "You Must Define The LED Connection Type"
	#endif
	break;
}
}

void led_toggle(led_id_t ledId)
{
	switch (ledId)
	{
		case LED_RED:
			 dio_vidFlipChannel(RED_LED_PORT, RED_LED_PIN);
		break;
		
		case LED_GREEN:
			 dio_vidFlipChannel(GREEN_LED_PORT, GREEN_LED_PIN);
		break;
		
		case LED_BLUE:
			 dio_vidFlipChannel(BLUE_LED_PORT, BLUE_LED_PIN);
		break;
		
		case LED_YELLOW:
			 dio_vidFlipChannel(YELLOW_LED_PORT, YELLOW_LED_PIN);
			break;
	}	
}

/**********************************************************************************************************************
 *  END OF FILE: led.c
 *********************************************************************************************************************/
