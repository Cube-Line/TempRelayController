/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2017 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Jan/21/2017
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: N76E003 GPIO demo code
//***********************************************************************************************************
#include "N76E003.h"
#include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
#include "Delay.h"
#include "Segment_Led_Display.h"

//*****************  The Following is in define in Fucntion_define.h  ***************************
//****** Always include Function_define.h call the define you want, detail see main(void) *******
//***********************************************************************************************

/*------------------------------------------------
The main C function.  Program execution starts
here after stack initialization.
------------------------------------------------*/

// char COL[] = {P06, P17, P01, P04, P02, P30, P00, P03};
// char ROW[] = {P05, P14, P13};
uint8_t _num = 0;
void main(void)
{
	//	unsigned char temp;
	Set_All_GPIO_Quasi_Mode; // Define in Function_define.h
	// Set_ALL_GPIO_PushPull_Mode;
	while (1)
	{
		// clr_GPIO1;
		// Tiny board GPIO1 LED define
		// P05 = 0;
		// P1 = 0X18;
		// P3 = 0X00;
		//		Timer0_Delay1ms(30);
		//		P06 = 0x01;
		//		set_GPIO1;
		// for (j = 0; j <= 2; j++)
		// 	for (i = 0; i <= 15; i++)
		// 	{
		// 		P06 = ~LedChar[i] & 0x01;
		// 		P17 = ~(LedChar[i] >> 1) & 0x01;
		// 		P01 = ~(LedChar[i] >> 2) & 0x01;
		// 		P04 = ~(LedChar[i] >> 3) & 0x01;
		// 		P02 = ~(LedChar[i] >> 4) & 0x01;
		// 		P30 = ~(LedChar[i] >> 5) & 0x01;
		// 		P00 = ~(LedChar[i] >> 6) & 0x01;
		// 		P03 = ~(LedChar[i] >> 7) & 0x01;
		// 		P05 = ~LedCom[j] & 0x01;
		// 		P14 = ~LedCom[j] >> 1 & 0x01;
		// 		P13 = ~LedCom[j] >> 2 & 0x01;
		// 		Timer0_Delay1ms(200);
		// P0 = 0X00;
		// P1 = 0X00;
		// P3 = 0X00;
		// P05 = 0x01;
		// P14 = 0x01;
		// P13 = 0x01;
		// Timer0_Delay1ms(100);
		// }
		for (_num = 0; _num <= 15; _num++)
		{
			LED_Disp(_num, 0);
			Timer0_Delay1ms(1000);
		}
		// LED_Close();
		// Timer0_Delay1ms(1000);
	}
	//#endif
}
