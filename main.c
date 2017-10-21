/*
* spi_s.c
*
* Created: 11.07.2017 20:47:55
* Author : DiGun
*/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "spi.h"






int main (void)
{
//	DDRB &= ~((1<<2)|(1<<3)|(1<<5));   // SCK, MOSI and SS as inputs
//	DDRB |= (1<<4);                    // MISO as output
	spi_init_slave();
	_delay_ms(1);
	DDRD |= 0xFF;
	DDRC |= 3;

	sei();

	while(1)
	{
		_delay_ms(250);
		PORTC^=2;
	}
}

ISR (SPI_STC_vect)
{
	PORTC^=1;
	PORTD = SPDR;
	SPDR=PORTD;
	// do something with the received data
}