extern "C" 
{
	#include "MCB.h"	
}

#include "RLB.h"




void initI2C(char address)
{
	TWAR = address<<1|1;
	TWBR = 16; //has to be at least 10, no point in slowing it down more than this
	TWCR |= _BV(TWEA) | _BV(TWEN);
}
void initI2C()
{
	TWBR = 16; //not gonna answer to anything cuz I'm a master so all I need to do is set bitrate
	TWCR |= _BV(TWEN);
}

int sendCommand(RLBMessage me)
{
	if(sBytesLeft != 0)
		return -1; //Bus is busy

	else
		{
			send = me;
			sBytesLeft = 6;
			TWCR |= _BV(TWINT) | _BV(TWSTA);
		}
		
}
