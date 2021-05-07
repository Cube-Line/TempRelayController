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

extern unsigned char Key_Set, Key_Up, Key_Down; //按键变量;
extern unsigned int KeyTimeCount;				 //按键计时变量;
extern unsigned char Key_Long_Set, Key_Long_Up, Key_Long_Down; //按键变量;

void Key_Scan(void);
void Key_Server(void);
