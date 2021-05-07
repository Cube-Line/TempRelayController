#include "N76E003.h"
// #include "SFR_Macro.h"
#include "Function_define.h"
#include "Common.h"
// #include "Delay.h"
#include "Segment_Led_Display.h"

unsigned char code LedChar[] = {
	0xc0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
	0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
unsigned char code LedCom[] = {0x01, 0x02, 0x04};

void LED_Disp(int NUM, unsigned char Bit)
{

	P06 = ~LedChar[NUM] & 0x01;
	P17 = ~(LedChar[NUM] >> 1) & 0x01;
	P01 = ~(LedChar[NUM] >> 2) & 0x01;
	P04 = ~(LedChar[NUM] >> 3) & 0x01;
	P02 = ~(LedChar[NUM] >> 4) & 0x01;
	P30 = ~(LedChar[NUM] >> 5) & 0x01;
	P00 = ~(LedChar[NUM] >> 6) & 0x01;
	P03 = ~(LedChar[NUM] >> 7) & 0x01;
	P05 = ~LedCom[Bit] & 0x01;
	P14 = ~LedCom[Bit] >> 1 & 0x01;
	P13 = ~LedCom[Bit] >> 2 & 0x01;
}

void LED_Close(void)
{
	P06 = 0;
	P17 = 0;
	P01 = 0;
	P04 = 0;
	P02 = 0;
	P30 = 0;
	P00 = 0;
	P03 = 0;
	P05 = 1;
	P14 = 1;
	P13 = 1;
}