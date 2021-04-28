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
	if (MainMenu_Flag != 99) //MainMenu_Flag==99表明处于二级菜单，默认进入一级菜单刷新显示当前温度;
		switch (MainMenu_Flag)
		{
		case 0:			   //显示主画面，即当前温度值;
			Disp_Temp_Default(); //显示:Main_Temp;
			if (KeyTimeCount >= KtCount)
			{
				MainMenu_Flag = 1;
				KeyTimeCount = 0;
				Key_Set = 0;
			}
			if (Key_Up == 1)
			{
				SubMenu_Flag = 1; //进入温度设置画面;
				KeyTimeCount = 0;
				Key_Up = 0;
			}
			if (Key_Down == 1)
			{
				SubMenu_Flag = 1;
				KeyTimeCount = 0;
				Key_Down = 0;
			}
			break;
		case 1:						   //P0,工作模式选择,C:制冷,H:制热(default)
			Disp_Run_Mode();			   //显示:P00
			if (OverTimeCount >= OtCount) //超时退出菜单;
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
				MainMenu_Flag = 99;
				SubMenu_Flag = 1;
				KeyTimeCount = 0;
				Key_Set = 0;
			}
			if (Key_Up == 1)
			{
				SubMenu_Flag += 1; //向上翻页;
				KeyTimeCount = 0;
				Key_Up = 0;
			}
			if (Key_Down == 1)
			{
				SubMenu_Flag -= 1; //向上翻页;
				KeyTimeCount = 0;
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
	else
		switch (SubMenu_Flag)
		{
		case 0:						   //调节温控点;
			Disp_Set_Temp();			   //显示温度设定值;
			if (OverTimeCount >= OtCount) //超时退出菜单不保存;
			{
				MainMenu_Flag = 0;
				SubMenu_Flag = 0;
			}
			if (KeyTimeCount >= KtCount) //长按保存并退出菜单;
			{
				//保存设定值;
				MainMenu_Flag = 0;
				KeyTimeCount = 0;
				Key_Set = 0;
			}
			if (Key_Set == 1) //短按无操作;
			{
				KeyTimeCount = 0;
				Key_Set = 0;
			}
			if (Key_Up == 1)
			{
				Set_Temp += 1; //设定温度+0.1摄氏度,此处使用整数处理;
				KeyTimeCount = 0;
				Key_Up = 0;
			}
			if (Key_Down == 1)
			{
				Set_Temp += 1; //设定温度+0.1摄氏度,此处使用整数处理;
				KeyTimeCount = 0;
				Key_Down = 0;
			}
			/* code */
			break;
		case 1:						   //调整模式;
			Disp_Set_Run_Mode();				   //显示运行模式C/H;
			if (OverTimeCount > OtCount)	   //超时退出菜单不保存;
			{
				MainMenu_Flag = 0;
				SubMenu_Flag = 0;
			}
			if (KeyTimeCount >= KtCount) //长按保存并退出菜单;
			{
				//保存设定值;
				MainMenu_Flag = 0;
				KeyTimeCount = 0;
				Key_Set = 0;
			}
			if (Key_Set == 1) //短按不保存并返回上级菜单;
			{
				MainMenu_Flag = 1;
				KeyTimeCount = 0;
				Key_Set = 0;
			}
			if (Key_Up == 1)
			{
				Set_Mode(); //改变运行模式;
				KeyTimeCount = 0;
				Key_Up = 0;
			}
			if (Key_Down == 1)
			{
				Set_Mode(); //改变运行模式;
				KeyTimeCount = 0;
				Key_Down = 0;
			}
			break;
		case 2:						   //调整回差;
			Disp_Return_Heating();  //显示回差数值(范围0.1~15℃);
			if (OverTimeCount > OtCount) //超时退出菜单不保存;
			{
				MainMenu_Flag = 0;
				SubMenu_Flag = 0;
			}
			if (KeyTimeCount >= KtCount) //长按保存并退出菜单;
			{
				//保存设定值;
				MainMenu_Flag = 0;
				KeyTimeCount = 0;
				Key_Set = 0;
			}
			if (Key_Set == 1) //短按不保存并返回上级菜单;
			{
				MainMenu_Flag = 2;
				KeyTimeCount = 0;
				Key_Set = 0;
			}
			if (Key_Up == 1)
			{
				Set_Return_Heating(); //改变回差值;
				KeyTimeCount = 0;
				Key_Up = 0;
			}
			if (Key_Down == 1)
			{
				Set_Return_Heating(); //改变回差值;
				KeyTimeCount = 0;
				Key_Down = 0;
			}
			break;
		case 3: //调整绝对最大温度点;
			break;
		case 4: //调整绝对最低温度点;
			break;
		case 5: //修正温度(温度补偿);
			break;
		case 6: //延时启动;
			break;
		case 7: //高温报警;
			break;

		default:
			break;
		}
}