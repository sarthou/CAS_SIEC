/*----------------------------------------------------------------------------
 * Name:    CanDemo.c
 * Purpose: CAN example for MCBSTM32
 * Note(s): possible defines set in "options for target - C/C++ - Define"
 *            __USE_LCD   - enable Output on LCD
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2009-2013 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include "stm32f10x.h"                            /* STM32F10x Definitions    */
#include "LCD.h"                                  /* LCD function prototypes  */
#include "ADC.h"                                  /* LCD function prototypes  */
#include "CAN.h"                                  /* STM32 CAN adaption layer */
#include "CAN_Abstraction.h" /*Our Abstration*/
#include "system_time.h"
#include "CAN_Periodic.h"

char text[17];

unsigned int val_Tx = 0, val_Rx = 0;              /* Globals used for display */

data_paquet_t var1;
data_paquet_t var2;
data_paquet_t var3;

data_paquet_t rec1;
data_paquet_t rec2;
data_paquet_t rec3;

periode_t my_periode;

volatile uint32_t msTicks;                        /* counts 1ms timeTicks     */
/*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void) {
  msTicks++;                        /* increment counter necessary in Delay() */
	CanCallback(msTicks);
}

/*----------------------------------------------------------------------------
  delays number of tick Systicks (happens every 1 ms)
 *----------------------------------------------------------------------------*/
void Delay (uint32_t dlyTicks) {
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks);
}


/*----------------------------------------------------------------------------
  display transmit and receieve values
 *----------------------------------------------------------------------------*/
void val_display (void) {

#ifdef __USE_LCD
	sprintf(text, "Tx %02X : %02X : %02X", var1.stringMessage[0], var2.stringMessage[0], var3.stringMessage[0]);
	set_cursor (0, 0);
	lcd_print  (text); 
	
  sprintf(text, "Rx %02X : %02X : %02X", rec1.stringMessage[0], rec2.stringMessage[0], rec3.stringMessage[0]);
  set_cursor (0, 1);
  lcd_print  (text);                              /* print string to LCD      */
#endif

  //Delay (10);                                     /* dlay for 10ms            */
}

void init_my_can()
{
	subperiode_t sub1;
	{
		variable_paquet_t paquet1;
		paquet1.id = 1;
		paquet1.data = &var1;
		variable_paquet_t paquet2;
		paquet2.id = 3;
		paquet2.data = &var2;
		
		sub1.variables[0] = paquet2;
		sub1.variables[1] = paquet1;
		sub1.nb_variables = 2;
	}
	
	subperiode_t sub2;
	{
		variable_paquet_t paquet1;
		paquet1.id = 5;
		paquet1.data = &var3;
		variable_paquet_t paquet2;
		paquet2.id = 3;
		paquet2.data = &var2;
		
		sub2.variables[0] = paquet2;
		sub2.variables[1] = paquet1;
		sub2.nb_variables = 2;
	}
	my_periode.subperiodes[0] = sub1;
	my_periode.subperiodes[1] = sub2;
	my_periode.nb_subperiodes = 2;
	initCanPeriodic(200, &my_periode);
}


/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void)  {

  ADC_Init ();                                    /* initialize A/D converter */

  SysTick_Config(SystemCoreClock / 1000);         /* SysTick 1 msec IRQ       */
	
	var1.stringMessage[0] = 7;
	var2.stringMessage[0] = 9;
	var3.stringMessage[0] = 11;
	
	init_my_can();
	
#ifdef __USE_LCD
  lcd_init  ();                                   /* initialise LCD           */
  lcd_clear ();
  lcd_print ("MCBSTM32 CanDemo");
  set_cursor (0, 1);
  lcd_print ("  www.keil.com  ");
  Delay (4000);                                   /* Wait for initial display */

  lcd_clear ();
  //lcd_print ("CAN at 500kbit/s");
#endif

	canSubscribe(2, &rec1);
	canSubscribe(4, &rec2);
	canSubscribe(6, &rec3);
  canInit ();                                  /* initialize CAN interface */

  while (1) 
	{
		runCanPeriodic();
		//Delay(5);

		if(!receiveMessage()){
		}
		val_display (); 
			
  }
}
