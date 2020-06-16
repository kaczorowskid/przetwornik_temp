/*
 * main.c
 *
 *  Created on: 22.04.2020
 *      Author: Damian
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "ADC/adc.h"
#include "LCD/lcd44780.h"
#include "PWM/pwm.h"
#include "MODBUS/yaMBSiavr.h"

#include "common.h"

#define clientAddress 0x01


uint8_t flag;
uint16_t temp;

volatile uint16_t writeRegister[4];

void modbusGet(void);

int main(void) {

	adc_init();
	ster_init();
	keys_init();
	pwm_timer_init();

	lcd_init();
	lcd_cls();

	modbusSetAddress(clientAddress);
	modbusInit();

	sei();

	while(1) {
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

			temp = pt_100_and_thermocouple_measure(average(1));

			lcd_locate(0, 0);
			lcd_str("TERMOPARA TYPU J");
			lcd_locate(1, 0);
			lcd_int(temp);
			writeRegister[0] = temp;
			OCR2A = change_pwm_to_voltage(500, temp);
			break;

		case 1:
			PK1_OFF;
			PK2_OFF;
			PK3_ON;

			temp = pt_100_and_thermocouple_measure(average(0));

			lcd_locate(0, 0);
			lcd_str("TERMOPARA TYPU K");
			lcd_locate(1, 0);
			lcd_int(temp);
			writeRegister[0] = temp;
			OCR2A = change_pwm_to_voltage(500, temp);
			break;

		case 2:
			PK1_OFF;
			PK2_ON;
			PK3_OFF;

			temp = ni_100_measure(average(3));

			lcd_locate(0, 0);
			lcd_str(" CZUJNIK NI100  ");
			lcd_locate(1, 0);
			lcd_int(temp);
			writeRegister[0] = temp;
			OCR2A = change_pwm_to_voltage(180, temp);
			break;

		case 3:
			PK1_ON;
			PK2_ON;
			PK3_ON;

			temp = pt_100_and_thermocouple_measure(average(0));

			lcd_locate(0, 0);
			lcd_str(" CZUJNIK PT100  ");
			lcd_locate(1, 0);
			lcd_int(temp);
			writeRegister[0] = temp;
			OCR2A = change_pwm_to_voltage(500, temp);
			break;
		}
	}
}


void modbusGet(void) {
	if(modbusGetBusState() & (1<<ReceiveCompleted)){
		switch(rxbuffer[1]) {
		case fcPresetMultipleRegisters:
			modbusExchangeRegisters(writeRegister, 0, 4);
			break;
		}
	}
}

void timer0_init(void) {
	TCCR0B |= (1<<WGM01);

}



