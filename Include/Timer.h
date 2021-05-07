

#define RELOAD_VALUE_H (65536 - 10000) / 256 //10mS For Timer3
#define RELOAD_VALUE_L (65536 - 100002) % 256

extern unsigned int TimerCount;
extern unsigned int KeyTime; //按键定时器,用来计时按键消抖;

void Timer_init(void);

void Timer3(void);