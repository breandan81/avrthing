#include "pinsPrivate.h"
#include "pins.h"

int digitalWrite(char pin, char val)
{
	if(pin > maxPin)
		return -1;

	int *port = ports[pinMappings[pin]>>8];
	if(port == NULL)
		return -1;
	
	if(val)
	{
		*port |= 1<< (pinMappings[pin] & 0xFF);
	}
	else
	{
		*port &= 1 << ~((pinMappings[pin] & 0xFF);	
	}
	return 0;
}
int digitalRead(char pin)
{
	if(pin > maxPin)
		return -1;
	if(pinMappings[pin]>>8 == 0)
		return -1;

	return 1&(inputs[pinMappings[pin]>>8] >> (pinMappings[pin]&0xFF));
	
}
int setDirection(char pin, char val)
{
	if(pin > maxPin)
		return -1;
	if(pinMappings[pin] >> 8 == 0)
		return -1;
	if(val)
	{
		ddrs[pinMappings[pin]>>8] |= 1 << (pinMappings[pin]&0xFF); 
	}
	else
	{
		ddrs[pinMappings[pin]>>8] &= ~(1<< (pinMappings[pin]&0xFF));
	}

}
