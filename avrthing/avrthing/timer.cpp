#include "avrthing.h"
#include "timer.h"
#include <avr/interrupt.h>
#include <stdio.h>
//
unsigned short halfMillis=1;
unsigned short overflows1 = 0;
unsigned short overflows2 = 0;
//

void runTasks()//called by the timer interrupt put anything you need to run regularly here
{
	#ifdef USBSERIAL_H
	runUSB();
	#endif
}

void initRTC(void)
{

	TCCR1B |= _BV(WGM12); //set WGM12, will make OCR1A TOP for timer1	
	OCR1A = MHZ*500;//half a ms 
	
	TCCR1B |= _BV(CS10); //clock source no prescaling
	TIMSK1 |= _BV(OCIE1A);//output compare match interrupt enabled
	
	sei();
}

ISR(TIMER1_COMPA_vect)
{
	runTasks();	

	halfMillis++;
	if(!halfMillis)
	{
		overflows1++;
		if(!overflows1)
		{
			overflows2++;
		}
	} 
}


unsigned long millis()
{
	return (halfMillis>> 1) + (overflows1 <<15) + (((unsigned long)overflows2) <<31);
}

unsigned long seconds()
{
	long seconds = overflows1;
	seconds = ((seconds << 16) + halfMillis)/2000;
	long temp = overflows2;
	temp = temp << 16;
	temp /= 1000;
	temp = temp<<16;
	seconds += temp;
	return seconds;
}
void delayMillis(unsigned int interval)
{
	
	unsigned long start = millis();
	unsigned long current = millis();
//	printf("running delay millis for %d, %d\r\n", interval, start);
	
	while(current-start < interval)
	{	
		current = millis();//this would be way more efficient without doing anything in the loop itself but avr-gcc optimizes it out if there is nothing in here and gets stuck in an infinite loop
	}
}
