/*
 * pwm.c
 *
 *  Created on: 15.06.2020
 *      Author: Administrator
 */

#include <avr/io.h>

#include "pwm.h"

void pwm_timer_init(void){
	TCCR2A |= (1<<WGM20 | 1<<WGM21);
	TCCR2B |= (1<<WGM22); 	//FAST PWM
	TCCR2A |= (1<<COM2A1);	//OC2
	TCCR2B |= (1<<CS20);
}

uint8_t change_pwm_to_voltage(uint16_t max, uint8_t current_value) {
	return ((current_value / max) * 255);
}
