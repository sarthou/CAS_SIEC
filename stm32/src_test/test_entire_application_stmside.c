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

data_paquet_t transPosSteeringWheel;
data_paquet_t transPosWheels;
data_paquet_t transUSFrontBack;
data_paquet_t transUSLeft;
data_paquet_t transUSRight;

data_paquet_t recMotorsOrder;
data_paquet_t recSteeringWheelOrder;

data_paquet_t transBattery;

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
void val_display_ () {

#ifdef __USE_LCD
	//sprintf(text, "Tx %s", varACCO.stringMessage);
	set_cursor (0, 0);
	lcd_print  (text); 
	
  set_cursor (0, 1);
  lcd_print  (text);                              /* print string to LCD      */
#endif
}

void init_my_can()
{
	subperiode_t sub1;
	{
		variable_paquet_t paquet1;
		paquet1.id = 0;
		paquet1.data = &transUSFrontBack;
		
		variable_paquet_t paquet2;
		paquet2.id = 1;
		paquet2.data = &transUSLeft;
		
		variable_paquet_t paquet3;
		paquet3.id = 2;
		paquet3.data = &transUSRight;
		
		variable_paquet_t paquet4;
		paquet4.id = 257;
		paquet4.data=&transPosSteeringWheel;
		
		
		sub1.variables[0] = paquet1;
		sub1.variables[1] = paquet2;
		sub1.variables[2] = paquet3;
		sub1.variables[3] = paquet4;
		sub1.nb_variables = 4;	
	}
	
	subperiode_t sub2;
	{
		variable_paquet_t paquet1;
		paquet1.id = 0;
		paquet1.data = &transUSFrontBack;
		
		variable_paquet_t paquet2;
		paquet2.id = 1;
		paquet2.data = &transUSLeft;
		
		variable_paquet_t paquet3;
		paquet3.id = 2;
		paquet3.data = &transUSRight;
		
		variable_paquet_t paquet4;
		paquet4.id = 256;
		paquet4.data=&transPosWheels;
		
		
		sub2.variables[0] = paquet1;
		sub2.variables[1] = paquet2;
		sub2.variables[2] = paquet3;
		sub2.variables[3] = paquet4;
		sub2.nb_variables = 4;	
	}
	
	my_periode.subperiodes[0] = sub1;
	my_periode.subperiodes[1] = sub2;
	my_periode.nb_subperiodes = 2;
	initCanPeriodic(50, &my_periode);
}


/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void)  {

  ADC_Init ();                                    /* initialize A/D converter */

  SysTick_Config(SystemCoreClock / 1000);         /* SysTick 1 msec IRQ       */
	
	//Set value of variables contained in subperiod
	transPosSteeringWheel.byteMessage[0]=45;

	transPosWheels.floatMessage[0]=2.563;
	transPosWheels.floatMessage[1]=3.69;
	
	transUSFrontBack.floatMessage[0]=10.23;
	transUSFrontBack.floatMessage[1]=11.63;
	
	transUSLeft.floatMessage[0]=22.3;
	transUSLeft.floatMessage[1]=25.6;
	
	transUSRight.floatMessage[0]=0.36;
	transUSRight.floatMessage[1]=1.25;

	transBattery.intMessage[0]=15000;
	
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

	canSubscribe(16, &recMotorsOrder);
	canSubscribe(17, &recSteeringWheelOrder);
  canInit ();                                  /* initialize CAN interface */

  while (1) 
	{
		runCanPeriodic();
		//Delay(5);
		
		if(msTicks%10000==0){
			sendMessage(512, transBattery);
		}
		
		if(!receiveMessage()){
			//val_display_(); 
		}
  }
}
