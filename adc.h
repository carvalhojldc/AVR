/*
 * adc.h
 *
 * Created: 02/04/2015 12:30:31
 */

// ADMUX -> REFS1 REFS0 ADLAR -- MUX3 MUX2 MUX1 MUX0
// ADCSRA -> ADEN ADSC ADATE ADIF ADPS2 ADPS1 ADPS0

#ifndef ADC_H_
#define ADC_H_

#include "core.h"

void adc_init(void);
// initialize adc

uint8_t adc_read(uint8_t );
// read adc value
/*
	select the corresponding channel 0~7
    ANDing with '7' will always keep the value
    of 'channel' between 0 and 7
*/

#endif // ADC_H_
