/*
 * main.c
 *
 *  Created on: 22.04.2020
 *      Author: Damian
 */
#include <avr/io.h>

#include "ADC/adc.h"
#include "LCD/lcd44780.h"
#include "common.h"

int main(void) {

	adc_init();
	ster_init();
	keys_init();

	lcd_init();
	lcd_cls();

	while(1) {
		change_and_measure_thermosensors();
	}

}

