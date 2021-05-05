/******************
 * 
 * 
 * 
 * ***************/
#define KtCount 3000  //按键超时时间;
#define OtCount 10000 //菜单超时时间;
#define EJTime 20	  //按键消抖延时;
sbit K_Set = P1^2;  //设置;
sbit K_Up = P1^1;	  //按键上;
sbit K_Down = P1^0; //按键下;

unsigned char MainMenu_Flag, SubMenu_Flag, SpeMenu_Flag;
unsigned char OverTimeCount;
unsigned char Key_Set, Key_Up, Key_Down; //按键变量;
unsigned char KeyTimeCount;				 //按键计时变量;
unsigned char FirstPushSetFlag;
unsigned char KeyTimer;

void Key_Scan(void);
void Key_Server(void);
