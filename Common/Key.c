/******************
 * 
 * 
 * 
 * ***************/
#include "Key.h"
#include "Menu.h"
void Key_Scan(void)
{
}

void Key_Service(void)
{
	switch (MainMenu_Flag)
	{
	case 0:			   //显示主画面，即当前温度值;
		Disp_Menu_0(); //显示:Main_Temp;
		if (KeyTimeCount >= KtCount)
		{
			MainMenu_Flag = 1;
			KeyTimeCount = 0;
			Key_Set = 0;
		}
		if (Key_Up == 1)
		{
			SubMenu_Flag = 1; //进入温度设置画面;
			Key_Up = 0;
		}
		if (Key_Down == 1)
		{
			SubMenu_Flag = 1;
			Key_Down = 0;
		}
		break;
	case 1:						   //P0,工作模式选择,C:制冷,H:制热(default)
		Disp_Menu_1();			   //显示:P00
		if (OverTimeCount > 10000) //超时退出菜单;
		{
			MainMenu_Flag = 0;
			SubMenu_Flag = 0;
		}
		if (KeyTimeCount >= KtCount) //长按退出菜单;
		{
			MainMenu_Flag = 0;
			KeyTimeCount = 0;
			Key_Set = 0;
		}
		if (Key_Set == 1) //短按进入子菜单;
		{
			MainMenu_Flag = 0;
			SubMenu_Flag = 2;
			Key_Set = 0;
		}
		if (Key_Up == 1)
		{
			SubMenu_Flag += 1; //向上翻页;
			Key_Up = 0;
		}
		if (Key_Down == 1)
		{
			SubMenu_Flag -= 1; //向上翻页;
			Key_Down = 0;
		}
		break;
	case 2: //P1:温度回差
		break;
	case 3: //P2,绝对最大温度;
		break;
	case 4: //P3,绝对最小温度;
		break;
	case 5: //P4,温度补偿,补偿ADC误差;
		break;
	case 6: //P5,延时启动;
		break;
	case 7: //P6,高温报警;
		break;
	case 8:	 //预留菜单1;
	case 9:	 //预留菜单2;
	case 10: //预留菜单3;
		break;
	case 20: //特殊菜单1，测量超量程(下限)或传感器开路;
		break;
	case 21: //特殊菜单2,测量超量程(上限)或传感器短路;
		break;
	}
}