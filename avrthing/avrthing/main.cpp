#include "avrthing.h"
#include <stdio.h>

int main(void)
{

	initUSBSerial();
	initRTC();
	while(true);
	{
		printf("hello world\n\r");
		delayMillis(1000);
	}	

	return 0;
}
