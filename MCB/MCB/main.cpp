#include "user.h"

extern "C" 
{
#include "MCB.h"
}

 

int main(void)
{
        initMCB();

	setup();	

	for (;;)
	{
		loop();
	}
}
