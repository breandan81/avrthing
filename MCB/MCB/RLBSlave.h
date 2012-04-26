//This is the header file for the RLB receiver module.  This runs on rodlogic 
//peripheral boards, and controls slave receive and send operations.

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/twi.h>


ISR(TWI_vect)
{
	unsigned char status = TWSR;
/*
This routine handles all of the status codes relevant to slaves
*/
	switch(status)
	{
		case TW_MR_ARB_LOST:
		break;
		case TW_MR_SLA_ACK:
		break;
		case TW_MR_SLA_NACK:
		break;
		case TW_MR_DATA_ACK: 
		break;
		case TW_MR_DATA_NACK:
		break;
	}	
}
