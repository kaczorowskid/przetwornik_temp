/*
 * common.c
 *
 *  Created on: 22.04.2020
 *      Author: Damian
 */

#include <avr/io.h>
#include <util/delay.h>

#include "common.h"

void ster_init(void) {
	DDRD |= STER;
	PORTB &= ~STER;
}

void keys_init(void) {
	PORTB |= (KL1 | KL2 | KL3 | KL4);
}

void change_and_measure_thermocouple(void) {
	static uint8_t flag = 0;

	if(K1_PRESS) {
		_delay_ms(30);
		if(K1_PRESS) {
			flag = 0;
		}
	}

	if(K2_PRESS) {
		_delay_ms(30);
		if(K2_PRESS) {
			flag = 1;
		}
	}

	if(flag == 0) {
		STER_PORT &= ~STER;
		lcd_locate(0, 0);
		lcd_str("TERMOPARA TYPU J");
		lcd_locate(1, 0);
		lcd_int(measure(average(1)));
	}
	else if(flag == 1) {
		STER_PORT |= STER;
		lcd_locate(0, 0);
		lcd_str("TERMOPARA TYPU K");
		lcd_locate(1, 0);
		lcd_int(measure(average(0)));
	}
}

