/******************
 * 
 * 
 * 
 * ***************/

unsigned char MainMenu_Flag, SubMenu_Flag, SpeMenu_Flag;
unsigned char OverTimeCount;
unsigned char Key_Set, Key_Up, Key_Down;	//按键变量;
unsigned char KeyTimeCount;					//按键计时变量;
unsigned char KtCount = 3000;				//按键超时时间;
void Key_Scan(void);
void Key_Server(void);
