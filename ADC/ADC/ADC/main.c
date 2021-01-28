/*
 * ADC.c
 *
 * Created: 9/27/2019 8:56:49 PM
 * Author : Gamal
 */ 

#include <avr/io.h>
#include <avr/interrupt.h> 
#include "LCD.h"

uint16_t adc_reading = 0;
int main(void)
{
	DDRD = 0xFF;
    // take input from ADC0 and display it on LCD
	// initialize the LCD
	vLcdInit();
	//initialize ADC
	    //resolution : 10-bit
		//CH :ADC0
		ADMUX = 0x00;
		//reference : AVCC
		ADMUX |= (1U << REFS0);
		ADMUX &=~ (1U << REFS1);
		//polling or interrupt : interrupt
		   //enable Global interrupt
		   sei();
		   //enable ADC interrupt mask
		   ADCSRA |= (1U << ADIE);
		//prescaler: 64 >>0b110 "clock = 187500 Hz"
		ADCSRA &=~ (1U << ADPS0);
		ADCSRA |= (1U << ADPS1); 
		ADCSRA |= (1U << ADPS2);
		//enable the module ADC
		ADCSRA |= (1U << ADEN);
		//trigger mode : single conversion
		ADCSRA |= (1U << ADSC); // start Conversion.
		
    while (1) 
    {
		if (adc_reading >= 500)
		{
			PORTD |= (1<<6); // LED ON
		} 
		else
		{
			PORTD &=~ (1<<6); //LED OFF
		}
		//ADCSRA |=(1<<ADSC); // start Conversion.
		_delay_ms(20);
    }
}

/***********************ADC ISR*******************************************/

ISR(ADC_vect)
{
	
	//read the ADC value
	adc_reading = ADCL;
	adc_reading |= (uint16_t)(ADCH << 8);

	
	//display on the LCD
	   vLcdGotoXY (0,0);
	  //vLcdDisplayNumber(adc_reading);
	   sendValueToLcd(adc_reading);
	  // sendStringToLcd("Temp = ");
	  
	  ADCSRA |= (1U << ADSC); // To repeat reading from ADC
	
}



