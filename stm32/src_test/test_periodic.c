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
#include "CAN_Application.h"

char text[17];

unsigned int val_Tx = 0, val_Rx = 0;              /* Globals used for display */

volatile uint32_t msTicks;                        /* counts 1ms timeTicks     */
/*----------------------------------------------------------------------------
  SysTick_Handler
 *----------------------------------------------------------------------------*/
void SysTick_Handler(void) {
  msTicks++;                        /* increment counter necessary in Delay() */
	CAN_Callback(msTicks);
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
  sprintf(text, "Tx:0x%02X, Rx:0x%02X", val_Tx, val_Rx);
  set_cursor (0, 1);
  lcd_print  (text);                              /* print string to LCD      */
#endif

  Delay (10);                                     /* dlay for 10ms            */
}

data_paquet var1;
data_paquet var2;
data_paquet var3;

periode_t my_periode;

void init_my_can()
{
	subperiode_t sub1;
	{
		variable_paquet_t paquet1;
		paquet1.id = 3;
		paquet1.data = &var1;
		variable_paquet_t paquet2;
		paquet2.id = 2;
		paquet2.data = &var2;
		
		sub1.variables[0] = paquet1;
		sub1.variables[1] = paquet2;
		sub1.nb_variables = 2;
	}
	
	subperiode_t sub2;
	{
		variable_paquet_t paquet1;
		paquet1.id = 3;
		paquet1.data = &var3;
		variable_paquet_t paquet2;
		paquet2.id = 2;
		paquet2.data = &var2;
		
		sub2.variables[0] = paquet1;
		sub2.variables[1] = paquet2;
		sub2.nb_variables = 2;
	}
	my_periode.subperiodes[0] = sub1;
	my_periode.subperiodes[1] = sub2;
	my_periode.nb_subperiodes = 2;
	init_CAN_periodic(1000, &my_periode);
}


/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void)  {

  ADC_Init ();                                    /* initialize A/D converter */

  SysTick_Config(SystemCoreClock / 1000);         /* SysTick 1 msec IRQ       */
	
	var1.stringMessage[0] = 1;
	var2.stringMessage[0] = 2;
	var3.stringMessage[0] = 7;
	
	init_my_can();
	
#ifdef __USE_LCD
  lcd_init  ();                                   /* initialise LCD           */
  lcd_clear ();
  lcd_print ("MCBSTM32 CanDemo");
  set_cursor (0, 1);
  lcd_print ("  www.keil.com  ");
  Delay (4000);                                   /* Wait for initial display */

  lcd_clear ();
  lcd_print ("CAN at 500kbit/s");
#endif

	int ids[] = {25};
  can_Init (ids, 1);                                  /* initialize CAN interface */

  while (1) {
    ADC_StartCnv();                               /* start A/D conversion     */
    //val_Tx = ((ADC_GetCnv() >> 4) & 0xFF);        /* use upper 8 bits of ADC  */
    ADC_StopCnv();                                /* stop A/D conversion      */

		//sendMessageChar(3, val_Tx);
		
		val_display (); 
    Delay (10);                                   /* delay for 10ms           */

		can_paquet paquet;
		if(!receiveMessage(&paquet))
		{
			val_Rx = paquet.data.stringMessage[0];
		}
		
    val_display ();                               /* display TX and RX values */
  }
}
