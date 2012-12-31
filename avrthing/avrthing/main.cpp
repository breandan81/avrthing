#include "avrthing.h"
#include <stdio.h>

int main(void)
{
	char buf[10];

	initUSBSerial();
	initRTC();

//	delayMillis(10);

//	scanf("%s", buf);
	while(true)
	{
//		scanf("%s", buf);
		printf("hello world %lu\n\r", millis());
		delayMillis(100);
	}	

	return 0;
}
