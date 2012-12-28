#include "avrthing.h"

extern "C" 
{
	void initUSBSerial(void);
}

int main(void)
{

	initUSBSerial();
	while(true);
	return 0;
}
