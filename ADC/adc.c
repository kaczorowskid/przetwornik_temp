/*
 * adc.c
 *
 *  Created on: 10.01.2020
 *      Author: Damian
 */


#include <avr/io.h>
#include "adc.h"

void adc_init(void){
	ADMUX |= (1<<REFS0)|(1<<REFS1);
	ADCSRA |= (1<<ADEN);
}

uint16_t adc_measure(uint8_t mux){
	ADMUX |= (ADMUX & 0xF8) | mux;
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));

	return ADCW;
}

uint16_t average(uint8_t mux){
	static uint32_t sr = 0;
	static uint16_t temp = 0;
	static uint8_t kfil = 70;

	temp = adc_measure(mux);

	sr = kfil * sr;
	sr=sr+temp;
	sr=sr/(kfil+1);

	return sr;
}

uint16_t thermocouple_measure(uint16_t average) {
	float temp = 0;
	temp = (((average * 4.88) - 0.0027) / 10.0 );

	return temp;
}

uint16_t pt100_measure(uint16_t average) {
	float temp = 0;

}
