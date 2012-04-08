/*
Head file for RTC.c the RODLOGIC real time clock and scheduling file.  

RTC.c keeps a real time clock, and runs the USB task every 500 us, it uses timer 1, timer1 cannot be used for anything else when using the standard MCB code distro.
*/

#ifndef RTC_H
#define RTC_H
//constants:

#define MHZ 16 //change this if using a different clock speed obviously

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/interrupt.h>
//prototypes

void initRTC(void);


int micros(void );
int millis(void );
int seconds(void );
int minutes(void );
int hours(void );
#endif
