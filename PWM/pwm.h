/*
 * pwm.h
 *
 *  Created on: 15.06.2020
 *      Author: Administrator
 */

#ifndef PWM_PWM_H_
#define PWM_PWM_H_

void pwm_timer_init(void);
uint8_t change_pwm_to_voltage(uint16_t max, uint8_t current_value);


#endif /* PWM_PWM_H_ */
