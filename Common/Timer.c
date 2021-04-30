


#include "Timer.h"

void Timer_init(void)
{
	RH3 = RELOAD_VALUE_H;
	RHL = RELOAD_VALUE_L;

	set_ET3;
	set_EA;
	set_TR3;
}

void	Timer3(void)	interrupt	16	//定时器3中断
{
	Key_Scan(); //按键扫描;
	Disp_Menu_0(); //数码管刷屏;
	TimerCount++;
	if(TimerCount==50)
	{
		//1s定时处理;
		Blink();//
		TimerCount = 0; //计数器清零;
	}
}