#include "RLBMaster.h"

//MY CONSTANTS
#define CLEAR 0
#define SENDING 1
#define RECEIVING 2

//FROM DATASHEET
#define START 0x08
#define MT_SLA_ACK 0x18
#define MR_SLA_ACK 0x40
#define MT_DATA_ACK 0X28
#define MR_DATA_ACK 0X50



int RLBBegin(char slave, char receive)
{
//first we have to send a start condition
//I'm not going to set TWEN here, because it should already be enabled,
//Instead I'll check for TWEN
	if(TWCR & _BV(TWEN))
	{
	TWCR |= _BV(TWINT) | _BV(TWSTA);
	}
//wait for twint to be set again, this indicates start condition was sent
// (set is logic 0, I hate that)

	while(!(TWCR & _BV(TWINT)));
//now we have to check the status register
	if((TWSR & 0xF8) != START)
	{
		return -1;
	}
//now we can send the slave address 
	TWDR = slave << 1 | (receive?1:0);//last bit is high if receiving
	TWCR |= _BV(TWINT);
//wait for it again 
	while(!(TWCR & _BV(TWINT)));
//check the status
	if((TWSR & 0xF8) != (receive?MR_SLA_ACK:MT_SLA_ACK))
	{
		return -1;
	}
return 0;
}
int RLBsendByte(char me)
{
	TWDR = me;
	TWCR |= _BV(TWINT);
	//and wait for it
	while(!(TWCR & _BV(TWINT)));
	//check status
	if((TWSR & 0xF8) != MT_DATA_ACK)
	{
		return -1;
	}
	return 0;
}
int RLBrcvByte()
{
	if(TWCR & _BV(TWINT))
	{
		return -2;	
	}
	if(TWSR & 0xf8 != MR_DATA_ACK)
	{
		return -1;
	}
	return (int)TWDR;
}

int RLBstop()
{
	TWCR |= _BV(TWINT) | _BV(TWSTO);
}

void RLBinit()
{
	TWBR = 48*8/MHZ;
}
