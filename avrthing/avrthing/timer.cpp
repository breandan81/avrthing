#include "avrthing.h"
#include "timer.h"

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
	#ifdef USBSERIAL_H
	CDC_Device_ReceiveByte(&VirtualSerial_CDC_Interface);
        CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
        USB_USBTask();
	#endif

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
	return (halfMillis>> 1) + (overflows1 <<15) + (((long)overflows2) <<31);
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
void delayMillis(int interval)
{
	unsigned long start = millis();
	while(millis() - start < interval);
}
