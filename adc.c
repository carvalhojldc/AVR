/*
 * adc.c
 *
 * Created: 02/04/2015 12:30:47
 */

#include "adc.h"

void adc_init(void) {
	ADMUX = (1 << REFS0) | (1 << ADLAR); // AVcc voltage reference
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // ADC Enable and prescaler of 2
	// F_ADC = F_CPU/prescaler = 16M/2 = 8MHz
}

uint8_t adc_read(uint8_t channel) {
	/* select the corresponding channel 0~7
	  ANDing with '7' will always keep the value
	  of 'channel' between 0 and 7 */
	channel &= 0b00000111;  // AND operation with 7
	ADMUX = (ADMUX & 0xF8) | channel;
	/*
	   (0b01000000 & 0b11111000) | 0b00000000 <0 entrada>
	   (ADMUX & 0b11111000) | 0b00000001 <1 entrada>
	*/

	// start single conversion
	// write '1' to ADSC
	ADCSRA |= (1 << ADSC);

	/*
		wait for conversion to complete
		ADSC becomes '0' again
		till then, run loop continuously
	*/
	while( ADCSRA & (1 << ADSC) );

	return ADCH;
}
