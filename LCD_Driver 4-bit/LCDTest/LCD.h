/*
 * LCD.h
 *
 * Created: 18/09/2008 02:12:23 ص
 *  Author: Salama El Rady
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_Config.h"
#define F_CPU 12000000UL
#include<util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h> // string manipulation routines



void vLcdCommand (unsigned char cmd);
void vLcdData (unsigned char data);
void vLcdPrint(char * str);
void vLcdInit ();
void vLcdGotoXY(unsigned char line, unsigned char position);
void vLcdClearScreen();
void vLcdDisplayNumber(uint16_t Number);
void vLCD_Integer(uint16_t data);



#endif /* LCD_H_ */