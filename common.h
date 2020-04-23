/*
 * common.h
 *
 *  Created on: 22.04.2020
 *      Author: Damian
 */

#ifndef COMMON_H_
#define COMMON_H_

#define K_TYPE 1<<PC0
#define J_TYPE 1<<PC1
#define PT100 1<<PC2
#define NI100 1<<PC3

#define STER 1<<PB1
#define STER_PORT PORTB

#define KL1 1<<PB2
#define KL2 1<<PB3
#define KL3 1<<PB4
#define KL4 1<<PB5
#define KEY_PIN PINB

#define K1_PRESS (!(KEY_PIN & KL1))
#define K2_PRESS (!(KEY_PIN & KL2))
#define K3_PRESS (!(KEY_PIN & KL3))
#define K4_PRESS (!(KEY_PIN & KL4))


void ster_init(void);
void keys_init(void);
void change_and_measure_thermocouple(void);

#endif /* COMMON_H_ */
