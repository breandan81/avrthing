#include "main.h"


/** Configures the board hardware and chip peripherals for the demo's functionality. */
void SetupHardware(void)
{
	/* Disable clock division */
	clock_prescale_set(clock_div_1);

	initRTC();
	initUSBSerial();
	sei();
	USB_Init();
}

int main(void)
{
	SetupHardware();

	for (;;)
	{
		if(millis()%1000<20)
			printf("test %lu\r\n",millis());
	}
}

