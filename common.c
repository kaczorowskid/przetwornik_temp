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
	PK_DIR |= PK1 | PK2 | PK3;
	PK_PORT &= ~(PK1 | PK2 | PK3);
}

void keys_init(void) {
	KEY_PORT |= KL1;
}

void change_and_measure_thermosensors(void) {
	static uint8_t flag = 0;

	if(K1_PRESS) {
		_delay_ms(30);
		if(K1_PRESS) {
			flag++;
		}
	}

	if(flag > 3) flag = 0;

	switch(flag) {

	case 0:
		PK1_OFF;
		PK2_OFF;
		PK3_OFF;
		lcd_locate(0, 0);
		lcd_str("TERMOPARA TYPU J");
		lcd_locate(1, 0);
		lcd_int(pt_100_and_thermocouple_measure(average(1)));
		break;

	case 1:
		PK1_OFF;
		PK2_OFF;
		PK3_ON;
		lcd_locate(0, 0);
		lcd_str("TERMOPARA TYPU K");
		lcd_locate(1, 0);
		lcd_int(pt_100_and_thermocouple_measure(average(0)));
		break;

	case 2:
		PK1_OFF;
		PK2_ON;
		PK3_OFF;
		lcd_locate(0, 0);
		lcd_str(" CZUJNIK NI100  ");
		lcd_locate(1, 0);
		lcd_int(ni_100_measure(average(3)));
		break;

	case 3:
		PK1_ON;
		PK2_ON;
		PK3_ON;
		lcd_locate(0, 0);
		lcd_str(" CZUJNIK PT100  ");
		lcd_locate(1, 0);
		lcd_int(pt_100_and_thermocouple_measure(average(2)));
		break;
	}
}

