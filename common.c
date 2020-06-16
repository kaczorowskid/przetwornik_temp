/*
 * common.c
 *
 *  Created on: 22.04.2020
 *      Author: Damian
 */

#include <avr/io.h>

#include "common.h"

void ster_init(void) {
	PK_DIR |= PK1 | PK2 | PK3;
	PK_PORT &= ~(PK1 | PK2 | PK3);
}

void keys_init(void) {
	KEY_PORT |= KL1;
}

