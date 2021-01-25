/*
 * main.c
 *
 *  Created on: Jan 25, 2021
 *      Author: Ahmed Gamal
 *      LED_Animation and Buzzer
 */
#include "STD_TYPES.h"
#include <util/delay.h>

#define  DDRD        *( (u8  * ) 0x31)
#define  PORTD      *( (u8  * ) 0x32)

int main(void){

	DDRD   = 0xFF;
	PORTD = 0x80;


	while(1){
		_delay_ms(1000);
		PORTD = PORTD >> 1 ;

		if (PORTD == 0x08)
		    PORTD = 0x80;

	}

	return 0;
}
