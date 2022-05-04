/*
 * ATMEGA32_REGISTERS.h
 *
 * Created: 28.01.2022 12:03:47
 *  Author: student
 */ 


#ifndef ATMEGA32_REGISTERS_H_
#define ATMEGA32_REGISTERS_H_

#include "STD.h"



/*************************************       DIO_PORTA     ***************************************/

#define DDRA  (*(volatile uint8*)(0x3A))
#define PORTA (*(volatile uint8*)(0x3B))
#define PINA  (*(volatile uint8*)(0x39))


/*************************************       DIO_PORTB     ***************************************/

#define DDRB  (*(volatile uint8*)(0x37))
#define PORTB (*(volatile uint8*)(0x38))
#define PINB  (*(volatile uint8*)(0x36))

/*************************************       DIO_PORTC     ***************************************/

#define DDRC  (*(volatile uint8*)(0x34))
#define PORTC (*(volatile uint8*)(0x35))
#define PINC  (*(volatile uint8*)(0x33))

/*************************************       DIO_PORTD     ***************************************/

#define DDRD  (*(volatile uint8*)(0x31))
#define PORTD (*(volatile uint8*)(0x32))
#define PIND  (*(volatile uint8*)(0x30))

/*************************************       TIMER 0     ***************************************/

#define TCCR0  (*(volatile uint8*)(0x53))
#define TCNT0  (*(volatile uint8*)(0x52))
#define TIMSK  (*(volatile uint8*)(0x59))
#define OCR0   (*(volatile uint8*)(0x5C))

/*************************************       TIMER 1     ***************************************/

#define TCCR1A  (*(volatile uint8*)(0x4F))
#define TCCR1B  (*(volatile uint8*)(0x4E))
#define OCR1A   (*(volatile uint16*)(0x4A))
#define ICR1    (*(volatile uint8*)(0x46))

/*************************************       TIMER 2     ***************************************/

#define TCCR2  (*(volatile uint8*)(0x45))
#define OCR2   (*(volatile uint8*)(0x43))

/*************************************       EXT INTERRUPT     ***************************************/
#define SREG    (*(volatile uint8*)(0x5F))
#define MCUCR   (*(volatile uint8*)(0x55))
#define MCUCSR  (*(volatile uint8*)(0x54))
#define GICR    (*(volatile uint8*)(0x5B))
#define GIFR    (*(volatile uint8*)(0x5A))

/*************************************       I2C     ***************************************/


#define TWCR  (*(volatile uint8*)(0x56))
#define TWDR  (*(volatile uint8*)(0x23))
#define TWAR  (*(volatile uint8*)(0x22))
#define TWBR  (*(volatile uint8*)(0x20))
#define TWSR  (*(volatile uint8*)(0x21))




#endif /* ATMEGA32_REGISTERS_H_ */