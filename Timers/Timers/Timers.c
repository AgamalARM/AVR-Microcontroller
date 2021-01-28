/*
 * Timers.c
 *
 * Created: 18/09/2008 01:08:42 ص
 *  Author: Salama El Rady
 */ 


#include <avr/io.h>

int main(void)
{
	uint16_t counter = 0;
	DDRD = 0b11100000 ;
	// toggle three leds every 100 ms
	   // timer configuration
	    //for 1 ms
		//timer mode : Normal
		TCCR0 &=~ (1U << WGM00);
		TCCR0 &=~ (1U << WGM01); 
	   // counts : 125
	   // timer start counts from 256-125
	   TCNT0 = -125 ;
	   // prescaler : /8 >> In AVR: prescaler make enable of timer so that it is the Last Step
	   TCCR0 &=~ (1U << CS00);
	   TCCR0 |=  (1U << CS01);
	   TCCR0 &=~ (1U << CS02);
	
    while(1)
    {
        //check on timer overflow flag
		if ((TIFR & (1U << TOV0)) == (1U << TOV0))
		{
			// reset timer counts to 256-125
			TCNT0 = -125 ;
			//clear timer overflow flag
			TIFR |= (1U << TOV0);
			counter++ ;
			//check if counter == 100
			if (counter == 100)
			{
				//reset counter
				counter = 0;
				//toggle the leds
				PORTD ^= 0xFF ;
				
			}
			
		}
		  
    }
}