/*************************
 * 
 * 
 * 
 * 
 * ***********************/
#include "Menu.h"
#include "Segment_Led_Display.h"
#include "Timer.h"

void Disp_Temp(int _temp)
{
	// int _P0 = _temp % 10;
	
	// int _P1 = _temp / 10 % 10;
	
	// int _P2 = _temp / 100 % 10;

	if (TimerCount == 0)
	{
		LED_Disp(_temp % 10, 2);
	}
	if (TimerCount ==5)
	{
		LED_Disp(_temp / 10 % 10, 1);
	}
	if (TimerCount == 10)
	{
		LED_Disp(_temp / 100 % 10, 0);
	}
}
void Disp_Menu_0(void)
{

}
void Disp_Menu_1(void)
{

}