/*
 * LCD.c
 *
 * Created: 18/09/2008 02:19:33 ص
 *  Author: Salama El Rady
 */ 


#include <avr/io.h>
#include "LCD.h"


void vLcdCommand (unsigned char cmd)
{
	unsigned char high_nibble , low_nibble ;
	high_nibble = (cmd>>4);
	low_nibble = (cmd & 0x0f);
   // send command to data port
	LCD_DATA_PORT = high_nibble << 4 ; //send high nibble to D4-D7
   // reset RS=0 to select command mode
    LCD_RS_CTRL &=~ (1U << LCD_RS);
   // reset RW=0 to select write
   LCD_RW_CTRL &=~ (1U << LCD_RW);
   // set   EN=1 to Received command from low to high (latch)
   LCD_EN_CTRL |= (1U << LCD_EN);	
   _delay_ms(20);
   // reset   EN=0 to Execute command from high to low 
   LCD_EN_CTRL &=~ (1U << LCD_EN);
    _delay_ms(20);
   
   LCD_DATA_PORT = low_nibble << 4 ; //send Low nibble to D4-D7
   // set   EN=1 to Received command from low to high (latch)
   LCD_EN_CTRL |= (1U << LCD_EN);
   _delay_ms(20);
   // reset   EN=0 to Execute command from high to low
   LCD_EN_CTRL &=~ (1U << LCD_EN);
    _delay_ms(20);
   
}

void vLcdData (unsigned char data)
{
	unsigned char high_nibble , low_nibble ;
	high_nibble = (data>>4);
	low_nibble = (data & 0x0f);
	
	 // send DATA to data port
	 LCD_DATA_PORT = high_nibble << 4 ; //send high nibble to D4-D7
	 // reset RS=1 to select DATA mode
	 LCD_RS_CTRL |= (1U << LCD_RS);
	 // reset RW=0 to select write
	 LCD_RW_CTRL &=~ (1U << LCD_RW);
	 // set   EN=1 to Received command from low to high (latch)
	 LCD_EN_CTRL |= (1U << LCD_EN);
	  _delay_ms(20);
	 // reset   EN=0 to Execute command from high to low
	 LCD_EN_CTRL &=~ (1U << LCD_EN);
	  _delay_ms(20);
	 
	 LCD_DATA_PORT = low_nibble << 4 ; //send Low nibble to D4-D7
	 // set   EN=1 to Received command from low to high (latch)
	 LCD_EN_CTRL |= (1U << LCD_EN);
	  _delay_ms(20);
	 // reset   EN=0 to Execute command from high to low
	 LCD_EN_CTRL &=~ (1U << LCD_EN);
	  _delay_ms(20);
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

void vLcdInit ()
{
	_delay_ms(20);
	//set data port as output
	LCD_DATA_DIR = 0xFF;
	//set control port as output
	LCD_EN_DIR   |= 1U << LCD_EN;
	LCD_RW_DIR   |= 1U << LCD_RW;
	LCD_RS_DIR   |= 1U << LCD_RS;
	// Reset EN = 0
	LCD_EN_CTRL  &=~ (1U << LCD_EN) ;
	// wait for init
	 _delay_ms(50);
	 vLcdCommand(0x33);
	 vLcdCommand(0x32);
	vLcdCommand(0x28);
	vLcdCommand(0x0E);
	vLcdCommand(0x01);
	 _delay_ms(50);
	vLcdCommand(0x06);
	_delay_ms(50);
	
}
void vLcdGotoXY(unsigned char line, unsigned char position)
{
	if (line == 0)
	{
		if (position < 16 && position >= 0)
		     vLcdCommand(0x80 + position);
	}
	else if (line == 1)
	{
		if (position < 16 && position >= 0)
		     vLcdCommand(0xc0 + position);
	}
}
void vLcdClearScreen()
{
	vLcdCommand(0x01);
}

void vLcdDisplayNumber(uint16_t Number)
{
	char str[7];
	sprintf(str,"%d",Number); // Adjust the formatting to your liking
	vLcdPrint(str);
	
}

void vLCD_Integer(uint16_t data)
// displays the integer value of DATA at current LCD cursor position
{
	char str[16] = "";// save enough space for result
	itoa(data,str,10);//convert to ascii
	vLcdPrint(str);// display in on LCD
}

void sendStringToLcd(unsigned char * str){
	
	for(int i = 0; str[i] != '\0' ; i++){
		vLcdData (str[i]);
	}
}

void sendValueToLcd(uint16_t num){
	unsigned char arr[20];
	itoa(num,arr,10);
	sendStringToLcd(arr);
}