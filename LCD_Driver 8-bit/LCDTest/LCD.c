/*
 * LCD.c
 *
 * Created: 18/09/2008 02:19:33 ص
 *  Author: Salama El Rady
 */ 

#include "LCD.h"
#include<util/delay.h>

void vLcdInit ()
{
  //set data port as output
	LCD_DATA_DIR = 0xFF;           
  //set control port as output
	LCD_EN_DIR   |= 1U << LCD_EN;  
	LCD_RW_DIR   |= 1U << LCD_RW;
	LCD_RS_DIR   |= 1U << LCD_RS;
  // Reset EN = 0
    LCD_EN_CTRL  &=~ (1U << LCD_EN) ;  
  // wait for init
  _delay_us(2000);   
  vLcdCommand(0x38);
  vLcdCommand(0x0E);
  vLcdCommand(0x01);
  _delay_us(2000);
  vLcdCommand(0x06);
	
}
void vLcdCommand (unsigned char cmd)
{
   // send command to data port
	LCD_DATA_PORT = cmd;
   // reset RS=0 to select command mode
    LCD_RS_CTRL &=~ (1U << LCD_RS);
   // reset RW=0 to select write
   LCD_RW_CTRL &=~ (1U << LCD_RW);
   // set   EN=1 to Received command from low to high (latch)
   LCD_RS_CTRL |= (1U << LCD_EN);	
   _delay_ms(40);
   // reset   EN=0 to Execute command from high to low 
   LCD_RS_CTRL &=~ (1U << LCD_EN);
   _delay_ms(100);
}

void vLcdData (unsigned char data)
{
	
	 // send data to data port
	 LCD_DATA_PORT = data;
	 // set RS=1 to select data mode
	 LCD_RS_CTRL |= (1U << LCD_RS);
	 // reset RW=0 to select write
	 LCD_RW_CTRL &=~ (1U << LCD_RW);
	 // set   EN=1 to Received command from low to high (latch)
	 LCD_RS_CTRL |= (1U << LCD_EN);
	 _delay_ms(40);
	 // reset   EN=0 to Execute command from high to low
	 LCD_RS_CTRL &=~ (1U << LCD_EN);
	 _delay_ms(100);
}

void vLcdPrint(char * str)
{
	unsigned char i = 0;
	while (str[i] != 0)
	{
		vLcdData(str[i]);
		i++;
	}
}