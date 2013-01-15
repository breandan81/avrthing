#ifndef TIMER_H
#define TIMER_H
void initRTC(void);
void runTasks(void);
unsigned long millis(void);
unsigned long seconds(void);
void delayMillis(unsigned int interval);
#endif
