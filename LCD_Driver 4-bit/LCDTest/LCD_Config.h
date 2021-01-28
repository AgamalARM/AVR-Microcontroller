/*
 * LCD_Config.h
 *
 * Created: 18/09/2008 01:59:19 ص
 *  Author: Salama El Rady
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include <avr/io.h>
 
#define LCD_EN              3
#define LCD_EN_DIR          DDRB
#define LCD_EN_CTRL         PORTB  

#define LCD_RW              2
#define LCD_RW_DIR          DDRB
#define LCD_RW_CTRL         PORTB 

#define LCD_RS              1
#define LCD_RS_DIR          DDRB
#define LCD_RS_CTRL         PORTB

#define LCD_DATA_DIR        DDRA
#define LCD_DATA_PORT       PORTA







#endif /* LCD_CONFIG_H_ */