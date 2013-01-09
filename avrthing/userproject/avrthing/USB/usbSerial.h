#include "macros/SerialMacros.h"
#define USB_CDC 1

#ifdef __GNUG__
class usbSerial : public usbDev {
	private:
	USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface;
	FILE USBSerialStream;

	public:
	usbSerial();
	usbSerial(int,int,int);
	void USBTask(void);
	void ConfigChanged(void);
	void ControlRequest(void);
	void StartOfFrame(void);
	void initUSBSerial();
};
#endif
