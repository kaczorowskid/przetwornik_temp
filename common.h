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

#define KL1 1<<PB2
#define KEY_PORT PORTB
#define KEY_PIN PINB

#define K1_PRESS (!(KEY_PIN & KL1))

#define PK1 1<<PB1
#define PK2 1<<PB3
#define PK3 1<<PB4

#define PK_DIR DDRB
#define PK_PORT PORTB

#define PK1_ON PK_PORT |= PK1
#define PK2_ON PK_PORT |= PK2
#define PK3_ON PK_PORT |= PK3

#define PK1_OFF PK_PORT &= ~PK1
#define PK2_OFF PK_PORT &= ~PK2
#define PK3_OFF PK_PORT &= ~PK3



void ster_init(void);
void keys_init(void);


#endif /* COMMON_H_ */
