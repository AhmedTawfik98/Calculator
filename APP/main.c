/*
 * NTI.c
 *
 * Created: 2023-10-30 3:34:31 PM
 * Author : Ahmed Tawfik
 */ 
#define F_CPU	16000000UL

#include <avr/io.h>
#include "BIT_MATH.h"
#include "std_types.h"
#include "dio.h"
#include "lcd.h"
#include "keypad.h"
#include <util/delay.h>

#define Error 88
u8 key =0;
u16 num1=0,num2=0;
char func =0;

u8 get_numberFromChar(u8 ascii);
u8 get_func(u8 funct);
void DispError(int numb) ;
void Disp_numOnLcd(u16 number);
void check_digitOrFunc(u8 key2);


int main(void)
{

	
	keypad_vidInit();
	lcd_vidInit();
	
	//lcd_vidGotoRowColumn(5,1);
	lcd_vidDisplyStr((u8*)"Calculator");
	_delay_ms(2000);
	lcd_vidSendCmd(0x01);
	//lcd_vidGotoRowColumn(0,0);
	while (1) 
    {
		//lcd_vidSendCmd(0x01);
		 while(keypad_bolIsPressed() == FALSE);
			key = keypad_u8GetKey();
			//lcd_vidSendCmd(0x01);
			lcd_vidDisplyChar(key);
			//num1 = num1 * 10 + get_numberFromChar(key);
			num1 = get_numberFromChar(key);
		
		//lcd_vidGotoRowColumn(0,1);
		//key = keypad_u8GetKey();
		
		if(num1 != Error)            // If correct input then proceed, num1==Error means wrong input
		{
			while(keypad_bolIsPressed() == FALSE);
			key = keypad_u8GetKey();
			lcd_vidDisplyChar(key);
			check_digitOrFunc(key);
			//lcd_vidGotoRowColumn(0,2);
			/*func = get_func(key);*/
			
			if(func!='e')                    //if correct input then proceed, func=='e' means wrong input
			{
				while(keypad_bolIsPressed() == FALSE);
				key = keypad_u8GetKey();	
				lcd_vidDisplyChar(key);
				//lcd_vidGotoRowColumn(0,3);
				num2 = get_numberFromChar(key);  //Get int from char value, it checks for wrong input as well
				if(num2!=Error)  				//if correct input then proceed, num2==Error means wrong input
				{
					while(keypad_bolIsPressed() == FALSE);
					key = keypad_u8GetKey();	//get equal sign
					lcd_vidDisplyChar(key);		//display the '=' pressed to LCD
					check_digitOrFunc(key);
					//lcd_vidGotoRowColumn(0,4);
					if(key == '=')    //if = is pressed then proceed
					{
						switch(func)    //switch on function
						{
							case '+':
							Disp_numOnLcd(num1+num2);
							while(keypad_bolIsPressed() == FALSE);
							key = keypad_u8GetKey();	//get any key to clear
							lcd_vidSendCmd(0x01); // Clear LCD screen
							num1=0;
							num2=0;
							break;
							case '-':
							if (num2>num1)
							{
								lcd_vidDisplyChar('-');
								num1=num2-num1;
							}
							else
							{
								num1=num1-num2;
							}
							Disp_numOnLcd(num1);
							while(keypad_bolIsPressed() == FALSE);
							key = keypad_u8GetKey();	//get any key to clear
							lcd_vidSendCmd(0x01); // Clear LCD screen
							num1=0;
							num2=0;
							break;
							case '*':
							Disp_numOnLcd(num1*num2);
							while(keypad_bolIsPressed() == FALSE);
							key = keypad_u8GetKey();	//get any key to clear
							lcd_vidSendCmd(0x01); // Clear LCD screen
							num1=0;
							num2=0;
							break;
							case '/':
							if (num2 == 0 || num2 == 0b0)
							{
								DispError(1);
								while(keypad_bolIsPressed() == FALSE);
								key = keypad_u8GetKey();	//get any key to clear
								lcd_vidSendCmd(0x01); // Clear LCD screen
								num1=0;
								num2=0;
							}
							else
							{
								Disp_numOnLcd(num1/num2);
								while(keypad_bolIsPressed() == FALSE);
								key = keypad_u8GetKey();	//get any key to clear
								lcd_vidSendCmd(0x01); // Clear LCD screen
								num1=0;
								num2=0;
							}
							break;
						}
					}
					else   //key other than '=' means wrong input
					{
						if(key == 'c')     //if clear screen 'c' is pressed then clear screen and reset
						{	lcd_vidSendCmd(0x01); // Clear LCD screen
						num1=0;
						num2=0;
						}
						else
						{
							DispError(0);
							while(keypad_bolIsPressed() == FALSE);
							key = keypad_u8GetKey();	//get any key to clear
							lcd_vidSendCmd(0x01); // Clear LCD screen
							num1=0;
							num2=0;
						}     //Display wrong input 
					}				
				}
				
			}
		} 
	}
}

u8 get_numberFromChar(u8 ascii){
	u16 result = 0;
	/*if ((ascii <'0') && (ascii >'9'))
	{
		result= Error;
	}
	else result = ascii - '0' ;
	*/

		switch(ascii)
		{
			case '0':
			result = 0;
			break;
			case '1':
			result = 1;
			break;
			case '2':
			result = 2;
			break;
			case '3':
			result = 3;
			break;
			case '4':
			result = 4;
			break;
			case '5':
			result = 5;
			break;
			case '6':
			result = 6;
			break;
			case '7':
			result = 7;
			break;
			case '8':
			result = 8;
			break;
			case '9':
			result = 9;
			break;
			case 'c':
			lcd_vidSendCmd(0x01);
			num1=0;
			num2=0;
			result = Error;
			break;  //this is used as a clear screen and then reset by setting error
			default:
			DispError(0);
			result = Error;
			break;       //it means wrong input
		}
	return result;
}


void check_digitOrFunc(u8 key2){
		if ((key2 >= '0') && (key2<='9'))
		{
			if (num2 == 0)
			{
				num1 = num1 * 10 + get_numberFromChar(key2);
				while(keypad_bolIsPressed() == FALSE);
				key = keypad_u8GetKey();
				lcd_vidDisplyChar(key);
				func = get_func(key);
			}
			else
			{
				num2 = num2 * 10 + get_numberFromChar(key2);
				while(keypad_bolIsPressed() == FALSE);
				key = keypad_u8GetKey();
				lcd_vidDisplyChar(key);
			}
		}
		else if (key2 == '=')
		{
			key = key2;
		}
		else if (key2 == 'c')
		{
			lcd_vidSendCmd(0x01); // Clear LCD screen
			num1=0;
			num2=0;
		}
		else if (key2 == '+' || key2 == '-' || key2 == '*' || key2 == '/')
		{
			if (num2 != 0)
			{
				DispError(0);
				_delay_ms(2000);
				lcd_vidSendCmd(0x01); // Clear LCD screen
				num1=0;
				num2=0;
			} 
			else
			{
				func = get_func(key2);		//check function is +,-,*,/
			}
		}
		else
		{
				// Do Nothing
		}
}



u8 get_func(u8 funct){
	
	if(funct=='c')                   //if 'c' then clear the LCD and reset
	{
		lcd_vidSendCmd(0x01);            //clear display
		num1=0;
		num2=0;
		return 'e';
	}
	if( (funct != '+') && (funct != '-' ) && (funct != '*') && (funct != '/') )  //if input is not from allowed functions then show error
	{
			DispError(1);
			while(keypad_bolIsPressed() == FALSE);
			key = keypad_u8GetKey();	//get any key to clear
			lcd_vidSendCmd(0x01); // Clear LCD screen
			num1=0;
			num2=0;
			return 'e';
	}
	return funct;
}


void DispError(int numb)           //displays different error messages
{
	u8 msg1[] = {"Wrong Input"};
	u8 msg2[] = {"Wrong Function"};
	lcd_vidSendCmd(0x01);              //clear display
	num1=0;
	num2=0;
	switch(numb)
	{
		case 0:
		lcd_vidDisplyStr(msg1);
		break;
		case 1:
		lcd_vidDisplyStr(msg2);
		break;
		default:
		//lcd_vidDisplyStr(msg1);
		break;
	}
}

void Disp_numOnLcd(u16 number)            //displays number on LCD
{
	u16 UnitDigit  = 0;  //It will contain unit digit of numb
	u16 TenthDigit = 0;  //It will contain 10th position digit of numb
	u16 HundDigit  = 0;
	u16 ThousDigit = 0;
	
//  	if(number < 0)    {
//  		number =(-1)*number;					// Make number positive
//  		lcd_vidDisplyChar('-');			// Display a negative sign on LCD
//  	}
	ThousDigit = (number/1000);                    // Find out Thousand Digit
	if( ThousDigit != 0)                    // If it is zero, then don't display
	{
		lcd_vidDisplyChar(ThousDigit+'0');    // Make Char of ThousandDigit and then display it on LCD
	}
	
	HundDigit = (number/100);                    // Find out Hundreds Digit
	if( HundDigit != 0)                    // If it is zero, then don't display
	{
		lcd_vidDisplyChar(HundDigit+'0');    // Make Char of Hundreds Digit and then display it on LCD
	}
	
	TenthDigit = (number/10);                    // Find out Tenth Digit
	if( TenthDigit != 0)                    // If it is zero, then don't display
	{
		lcd_vidDisplyChar(TenthDigit+'0');    // Make Char of TenthDigit and then display it on LCD
	}

	UnitDigit = number - TenthDigit*10  - HundDigit*100 - ThousDigit*1000;
	lcd_vidDisplyChar(UnitDigit+'0');    // Make Char of UnitDigit and then display it on LCD
}


