/*
File name: Blinkenlights.c
​Description: Assinment 3 PES (Blinkenlights).
File​ ​Author​ ​Name: Aditi Vijay Nanaware
Tools​ ​used​ ​to​ ​process​ ​the​ ​code​: MCUExpresso IDE, GCC compiler
Referred Google for a few concepts clarification, Dean book (a part of the code)
*/


#include "Blinkenlights_test.h"
#include <stdio.h>
#include "board.h"


void KL25Z_RGB_Flasher(void)
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

			 PTB->PCOR = (1UL << (RED_LED_PIN));	   // Turns ON RED LED
			 PTB->PSOR = (1UL << (GREEN_LED_PIN));	   //Turns OFF GREEN LED
			 PTD->PSOR = (1UL << (BLUE_LED_PIN));	   //Turns OFF BLUE LED
			 Call_Delay(25);
			 PTB->PSOR = (1UL << (RED_LED_PIN));    // Turns OFF RED LED
			 Call_Delay(5);

			 PTB->PCOR = (1UL << (GREEN_LED_PIN));  //Turns ON GREEN LED
			 PTD->PSOR = (1UL << (BLUE_LED_PIN));	   //Turns OFF BLUE LED
			 PTB->PSOR = (1UL << (RED_LED_PIN));    // Turns OFF RED LED
			 Call_Delay(25);
			 PTB->PSOR = (1UL << (GREEN_LED_PIN));  // Turns OFF GREEN LED
			 Call_Delay(5);

			 PTD->PCOR = (1UL << (BLUE_LED_PIN));   //TURNS ON BLUE LED
			 PTB->PSOR = (1UL << (GREEN_LED_PIN));  // Turns OFF GREEN LED
			 PTB->PSOR = (1UL << (RED_LED_PIN));    // Turns OFF RED LED
			 Call_Delay(25);
			 PTD->PSOR = (1UL << (BLUE_LED_PIN));   //Turns OFF BLUE LED
			 Call_Delay(5);

			 PTB->PCOR = (1UL << (RED_LED_PIN));	// Turns ON RED LED
			 PTB->PCOR = (1UL << (GREEN_LED_PIN));  //Turns ON GREEN LED
			 PTD->PCOR = (1UL << (BLUE_LED_PIN));   //TURNS ON BLUE LED
			 /* Thus WHITE LED TURNS ON (white looks like light pink on my board
			  * tried to test via switching ON & OFF RGBs, turns out white == light pink )*/
			 Call_Delay(5);
			 PTB->PSOR = (1UL << (RED_LED_PIN));    // Turns OFF RED LED
			 PTB->PSOR = (1UL << (GREEN_LED_PIN));  // Turns OFF GREEN LED
			 PTD->PSOR = (1UL << (BLUE_LED_PIN));   //Turns OFF BLUE LED
			 Call_Delay(5);

			 while(1)
			 	{
			 			 /* 500 ms OFF and 500ms ON */
			 			 PTB->PCOR = (1UL << (RED_LED_PIN));	// Turns ON RED LED
			 			 PTB->PCOR = (1UL << (GREEN_LED_PIN));  //Turns ON GREEN LED
			 			 PTD->PCOR = (1UL << (BLUE_LED_PIN));   //TURNS ON BLUE LED
			 			 Call_Delay(25);
			 			 PTB->PSOR = (1UL << (RED_LED_PIN));    // Turns OFF RED LED
			 			 PTB->PSOR = (1UL << (GREEN_LED_PIN));  // Turns OFF GREEN LED
			 			 PTD->PSOR = (1UL << (BLUE_LED_PIN));   //Turns OFF BLUE LED
			 			 Call_Delay(25);

			 			 /* 1000 ms OFF and 500ms ON */
			 			 PTB->PCOR = (1UL << (RED_LED_PIN));	// Turns ON RED LED
			 			 PTB->PCOR = (1UL << (GREEN_LED_PIN));  //Turns ON GREEN LED
			 			 PTD->PCOR = (1UL << (BLUE_LED_PIN));   //TURNS ON BLUE LED
			 			 Call_Delay(50);
			 			 PTB->PSOR = (1UL << (RED_LED_PIN));    // Turns OFF RED LED
			 			 PTB->PSOR = (1UL << (GREEN_LED_PIN));  // Turns OFF GREEN LED
			 			 PTD->PSOR = (1UL << (BLUE_LED_PIN));   //Turns OFF BLUE LED
			 			 Call_Delay(25);

			 			 /* 2000 ms OFF and 500ms ON */
			 			 PTB->PCOR = (1UL << (RED_LED_PIN));	// Turns ON RED LED
			 			 PTB->PCOR = (1UL << (GREEN_LED_PIN));  //Turns ON GREEN LED
			 			 PTD->PCOR = (1UL << (BLUE_LED_PIN));   //TURNS ON BLUE LED
			 			 Call_Delay(100);
			 			 PTB->PSOR = (1UL << (RED_LED_PIN));    // Turns OFF RED LED
			 			 PTB->PSOR = (1UL << (GREEN_LED_PIN));  // Turns OFF GREEN LED
			 			 PTD->PSOR = (1UL << (BLUE_LED_PIN));   //Turns OFF BLUE LED
			 			 Call_Delay(25);

			 			 /* 3000 ms OFF and 500ms ON */
			 			 PTB->PCOR = (1UL << (RED_LED_PIN));	// Turns ON RED LED
			 			 PTB->PCOR = (1UL << (GREEN_LED_PIN));  //Turns ON GREEN LED
			 			 PTD->PCOR = (1UL << (BLUE_LED_PIN));   //TURNS ON BLUE LED
			 			 Call_Delay(150);
			 			 PTB->PSOR = (1UL << (RED_LED_PIN));    // Turns OFF RED LED
			 			 PTB->PSOR = (1UL << (GREEN_LED_PIN));  // Turns OFF GREEN LED
			 			 PTD->PSOR = (1UL << (BLUE_LED_PIN));   //Turns OFF BLUE LED
			 			 Call_Delay(25);
			 	}
}

/* Defining a delay fucntion for delay
 * Returns void
 * volatile unsigned int time_del: is the iteration count the delay  */
void Delay(volatile unsigned int time_del)
{
	while(time_del--)
	{
		;
	}
}
/* Defining a delay call funcytion for iterating the delay function for required ms
 * Returns void
 * volatile unsigned int ntimes: is the iteration count for which the delay function is called  */
void Call_Delay(volatile unsigned int ntimes)
{
	while(ntimes--)
	{
		Delay(D_COUNT); // this is the calculated value fro the required delay
	}
}
