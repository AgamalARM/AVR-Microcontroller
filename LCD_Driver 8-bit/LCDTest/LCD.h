/*
 * LCD.h
 *
 * Created: 18/09/2008 02:12:23 ص
 *  Author: Salama El Rady
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "LCD_Config.h"

void vLcdCommand (unsigned char cmd);
void vLcdData (unsigned char data);
void vLcdInit ();
void vLcdPrint(char * str);



#endif /* LCD_H_ */