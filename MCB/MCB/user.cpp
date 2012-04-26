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
	delayMillis(100);
	printf("hello %d\n\r", cur);
	cur++;
}
