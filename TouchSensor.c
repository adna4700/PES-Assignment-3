/*
File name: Touch Sensor.c
​Description: Assinment 3 PES (Blinkenlights).
File​ ​Author​ ​Name: Aditi Vijay Nanaware
Tools​ ​used​ ​to​ ​process​ ​the​ ​code​: MCUExpresso IDE, GCC compiler
Referred Google for a few concepts clarification, Dean book (a part of the code), Deans github
*/

#include <stdio.h>
#include "board.h"
#include "TouchSensor.h"


/* This function is to initialize the RGB LEDS
 * returns void */
void Int_RGB()
{
	//Enable clock to Port B and Port D For LED blinking
	SIM->SCGC5 = (SIM->SCGC5)|(SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTD_MASK);

	//Make all LED pins GPIO
	PORTB->PCR[RED_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[RED_LED_PIN] |= PORT_PCR_MUX(1);

	PORTB->PCR[GREEN_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTB->PCR[GREEN_LED_PIN] |= PORT_PCR_MUX(1);

	PORTD->PCR[BLUE_LED_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[BLUE_LED_PIN] |=PORT_PCR_MUX(1);

	//Set all LED ports as output ports
	PTB->PDDR |= (1UL << (RED_LED_PIN)) | (1UL << (GREEN_LED_PIN));
	PTD->PDDR |= (1UL << (BLUE_LED_PIN));
}

/* This fucntion is to initialize the Touch Sensor
 * returns void*/
void Touch_Init()
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK; // enabling the clock

	TSI0->GENCS = TSI_GENCS_OUTRGF_MASK |  // Out of range flag, set to 1 to clear
	                                TSI_GENCS_MODE(0u) |  // Set at 0 for capacitive sensing.  Other settings are 4 and 8 for threshold detection, and 12 for noise detection
	                                TSI_GENCS_REFCHRG(0u) | // 0-7 for Reference charge
	                                TSI_GENCS_DVOLT(0u) | // 0-3 sets the Voltage range
	                                TSI_GENCS_EXTCHRG(0u) | //0-7 for External charge
	                                TSI_GENCS_PS(0u) | // 0-7 for electrode prescaler
	                                TSI_GENCS_NSCN(31u) | // 0-31 + 1 for number of scans per electrode
	                                TSI_GENCS_TSIEN_MASK | // TSI enable bit
	                                TSI_GENCS_STPE_MASK | // Enables TSI in low power mode
	                                TSI_GENCS_EOSF_MASK ; // End of scan flag, set to 1 to clear

TSI0->DATA = 	TSI_DATA_TSICH(10u); // selecting channel 10 for dcanning the capacitance

}

/* This function is to Scan the touch sensor capacitance
 * returns int which is the scan-OFFSET
 * the OFFSET is already calculated so teh sensor is calibarated
 */
int Touch_Scan_LH(void)
{
	unsigned int scan = 0;
	TSI0->DATA = 	TSI_DATA_TSICH(10u);
	TSI0->DATA |= TSI_DATA_SWTS_MASK; //software trigger to start the scan
	while (!(TSI0->GENCS & TSI_GENCS_EOSF_MASK )) // waiting for the scan to complete 32 times
	;
	scan = TOUCH_DATA;
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK ; //writing one to clear the end of scan flag
	return scan- TOUCH_OFFSET;
}



