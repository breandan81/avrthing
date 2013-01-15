#include "main.h"

usbDev** usbDevs = new usbDev*[2];

/** Configures the board hardware and chip peripherals for the demo's functionality. */
void SetupHardware(void)
{
	/* Disable clock division */
	clock_prescale_set(clock_div_1);

	initRTC();
	sei();

#ifdef AVRTHING_USB
#ifdef USB_JOY
	usbJoy *joy = new usbJoy();
	usbDevs[0]=joy;
#endif
#ifdef USB_MOUSE
	usbMouse *mouse = new usbMouse();
	usbDevs[0]=mouse;
#endif
#ifdef USB_CDC
	usbSerial *serial = new usbSerial();
	usbDevs[1]=serial;
	serial->initUSBSerial();
#endif
	USB_Init();
#endif
}

int main(void)
{
	SetupHardware();

	char buf[10];
	scanf("%s",buf);
	printf("%d/%d = %d\r\n",sizeof(usbDevs),sizeof(usbDev *),sizeof(usbDevs)/sizeof(usbDev *));

	for (;;)
	{
		printf("%d/%d = %d\r\n",sizeof(usbDevs),sizeof(usbDev *),sizeof(usbDevs)/sizeof(usbDev *));
		printf("testoutput: %lu\t%s\r\n", millis(),buf);
	}
}

