#include "main.h"

usbDev** usbDevs = new usbDev*[2];

/** Configures the board hardware and chip peripherals for the demo's functionality. */
void SetupHardware(void)
{
	/* Disable clock division */
	clock_prescale_set(clock_div_1);

	initRTC();
	sei();

#ifdef USB_MOUSE
	usbMouse *mouse1 = new usbMouse();
	usbSerial *serial = new usbSerial();
	usbDevs[0]=mouse1;
	usbDevs[1]=serial;
	serial->initUSBSerial();
#endif

#ifdef AVRTHING_USB
	USB_Init();
#endif
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

