#include "user.h"
#include "digitalIO.h"
#include "ringBuffer.h"
#include "delays.h"

ringBuffer me(8);
int cur = 0;
void  setup()
{
	
}
void loop()
{
	delayMillis(1000);

	printf("pushing 0 through 10 into an 8 byte buffer, should bork it \n\r");
	for(int i = 0; i < 11; i++)
	{
		me.push(i);
	}
	printf("popping it all out\n\r");
	for(int i = 0; i < 11; i++)
	{
		printf("popped %d \n\r", me.pop());
	}
	
}
