/*
 * LCDTest.c
 *
 * Created: 18/09/2008 12:38:12 ص
 *  Author: Salama El Rady
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include<util/delay.h>

int main(void)
{
	vLcdInit ();
	//vLcdData('A');
		vLcdPrint("ALLAH AKBER");
    while(1)
    {
		
		
        //TODO:: Please write your application code 
    }
}