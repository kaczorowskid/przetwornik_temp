/*
 * adc.h
 *
 *  Created on: 10.01.2020
 *      Author: Damian
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_


void adc_init(void);
uint16_t adc_measure(uint8_t mux);
uint32_t average(uint8_t mux);
uint16_t pt_100_and_thermocouple_measure(uint16_t average);

#endif /* ADC_ADC_H_ */
