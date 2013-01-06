#include "main.h"

usbDev** usbDevs = new usbDev*[1];
usbMouse* mouse1 = new usbMouse(0);

/** Configures the board hardware and chip peripherals for the demo's functionality. */
void SetupHardware(void)
{
	/* Disable clock division */
	clock_prescale_set(clock_div_1);

	initRTC();
#ifdef USB_CDC
	initUSBSerial();
#endif
	sei();

#ifdef USB_MOUSE
	//usbMouse *mouse1 = new usbMouse(0);
//	usbMouse *mouse2 = new usbMouse(6);
//	usbDevs[0]=mouse1;
//	usbDevs[1]=*mouse2;
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

