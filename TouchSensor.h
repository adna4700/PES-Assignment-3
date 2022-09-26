/*
 * TouchSensor.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Lenovo
 */

#ifndef TOUCHSENSOR_H_
#define TOUCHSENSOR_H_

#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

#define MASK(x) (1UL << (x))     // Mask defined to shidt bit 1 to required position
#define TOUCH_OFFSET  605  // offset value to be subtracted
#define TOUCH_DATA (TSI0->DATA & 0xFFFF)//macro for extracting the count from data register
//Pins for LED ports
#define RED_LED_PIN (18)
#define GREEN_LED_PIN (19)
#define BLUE_LED_PIN (1)

void Touch_Init();
int Touch_Scan_LH(void);
void Int_RGB();


#endif /* TOUCHSENSOR_H_ */
