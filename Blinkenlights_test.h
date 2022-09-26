/*
 * Blinkenlights_test.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Lenovo
 */
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#ifndef BLINKENLIGHTS_TEST_H_
#define BLINKENLIGHTS_TEST_H_
#define D_COUNT 100000
/* Define pins for LEDS  */
#define RED_LED_PIN (18)
#define GREEN_LED_PIN (19)
#define BLUE_LED_PIN (1)

void Delay_test(volatile unsigned int time_del);
void KL25Z_RGB_Flasher(void);
void Call_Delay(volatile unsigned int ntimes);

#endif /* BLINKENLIGHTS_TEST_H_ */
