/*
 * LCDTest.c
 *
 * Created: 18/09/2008 12:38:12 ص
 *  Author: Salama El Rady
 */ 




#include "LCD.h"




int main(void)
{
	uint16_t x =1230 ;
	uint16_t y =4500 ;
	vLcdInit ();
	vLcdPrint("ALLAH AKBER");
	//vLcdDisplayNumber(x);
	vLCD_Integer(y);
	
    while(1);
    
}