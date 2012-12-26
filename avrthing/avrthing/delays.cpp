extern "C"
{
#include "MCB.h"
}

void delayMillis(int interval)
{
	unsigned long start = millis();
	while(millis() - start < interval);
}
