#include "avrthing.h"
#include "USBMacros/Joystick.h"
#include "USBMacros/usbSerial.h"
#include <LUFA/Drivers/USB/USB.h>

void runUSB()
{
	JS_USBTask();
	Ser_USBTask();
	USB_USBTask();
}

/** Configures the board hardware and chip peripherals for the demo's functionality. */
void SetupHardware(void)
{
	/* Disable clock division */
	clock_prescale_set(clock_div_1);

	initUSBSerial();
	USB_Init();
}

int main(void)
{
	SetupHardware();
	initRTC();

	for (;;) {
		runUSB();
		printf("test %lu",millis());
	}
}

