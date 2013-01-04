#include "main.h"
#include "USBMacros/timer.h"
#include "USBMacros/usbJoy.h"
#include "USBMacros/usbSerial.h"
#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Drivers/Peripheral/TWI.h>

void runUSB(void)
{
	Ser_USBTask();
	//Mouse_USBTask();
	JS_USBTask();
	USB_USBTask();
}

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

