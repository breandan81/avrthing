/*
Main file for RTC.c handles RTC using timer1
*/

#include "RTC.h"
#include "stdio.h"

unsigned int halfMillis = 0;

void initRTC()
{

	TCCR1B |= _BV(WGM12); //set WGM12, will make OCR1A TOP for timer1	
	OCR1A = MHZ*500;//half a ms 
	
	TCCR1B |= _BV(CS10); //clock source no prescaling
	TIMSK1 |= _BV(OCIE1A);//output compare match interrupt enabled
	
	sei();
}

ISR(TIMER1_COMPA_vect)
{
   halfMillis++; 
}

int millis()
{
	return halfMillis >> 1;
}
