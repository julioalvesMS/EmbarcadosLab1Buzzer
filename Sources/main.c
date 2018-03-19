/* ********************************************** */
/* File name:					main.c 											*/
/* File description:	Main file of the code. 			*/
/* 										Contains the initialization */
/* 										sequence and the main loop 	*/
/* Author name:      julioalvesMS 								*/
/* Creation date:    08mar2018 										*/
/* Revision date:    15mar2018 										*/
/* ********************************************** */

#include "fsl_device_registers.h"
#include "util.h"
#include "buzzer_hal.h"
#include "mcg_hal.h"

/* ******************************************************	*/
/* Method name:					setupPeripherals									*/
/* Method description:	Makes the necessaries setups and	*/
/* 											initializatios for a proper 		 	*/
/*											preparation of the peripherals		*/
/* Input params:				n/a									 							*/
/* Output params:				n/a																*/
/* ****************************************************** */
void setupPeripherals()
{
	/* Start clock */
	mcg_clockInit();

	/* Start buzzer */
	buzzer_init();
}

/* ******************************************************	*/
/* Method name:					playBuzzer1ms											*/
/* Method description:	Play the buzzer for 1 ms					*/
/* Input params:				n/a									 							*/
/* Output params:				n/a																*/
/* ****************************************************** */
void playBuzzer1ms()
{
	buzzer_setBuzz();
	util_genDelay500us();
	buzzer_clearBuzz();
	util_genDelay500us();
}

/* ******************************************************	*/
/* Method name:					main 															*/
/* Method description:	System main function. Contains 		*/
/*											all the code that will actually		*/
/*											run																*/
/* Input params:				n/a									 							*/
/* Output params:				n/a																*/
/* ****************************************************** */
int main(void)
{

	setupPeripherals();
	/*
	 * Main Loop
	 * Contains a counter (timer), wich will
	 * make the behaviour repeat every 100 ms
	 */
	for (int iTimer=0;;iTimer++) {
		/* Play buzzer for 10 ms */
		if(iTimer<10)
			playBuzzer1ms();
		/* Do nothing for 90 ms */
		else
			util_genDelay1ms();

		if(iTimer>=99)
			iTimer = 0;
	}
	/* Never leave main */
	return 0;
}
