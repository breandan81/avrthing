#include "../../avrthing.h"
//#include "usbSerial.h"

#ifdef AVRTHING_USB

static FILE USBSerialStream;

usbSerial::usbSerial() {
	VirtualSerial_CDC_Interface.Config.ControlInterfaceNumber         = 0;
	VirtualSerial_CDC_Interface.Config.DataINEndpointNumber           = CDC_TX_EPNUM;
	VirtualSerial_CDC_Interface.Config.DataINEndpointSize             = CDC_TXRX_EPSIZE;
	VirtualSerial_CDC_Interface.Config.DataINEndpointDoubleBank       = false;
	VirtualSerial_CDC_Interface.Config.DataOUTEndpointNumber          = CDC_RX_EPNUM;
	VirtualSerial_CDC_Interface.Config.DataOUTEndpointSize            = CDC_TXRX_EPSIZE;
	VirtualSerial_CDC_Interface.Config.DataOUTEndpointDoubleBank      = false;
	VirtualSerial_CDC_Interface.Config.NotificationEndpointNumber     = CDC_NOTIFICATION_EPNUM;
	VirtualSerial_CDC_Interface.Config.NotificationEndpointSize       = CDC_NOTIFICATION_EPSIZE;
	VirtualSerial_CDC_Interface.Config.NotificationEndpointDoubleBank = false;
}

usbSerial::usbSerial(int tx, int rx, int notification) {
	VirtualSerial_CDC_Interface.Config.ControlInterfaceNumber         = 0;
	VirtualSerial_CDC_Interface.Config.DataINEndpointNumber           = tx;
	VirtualSerial_CDC_Interface.Config.DataINEndpointSize             = CDC_TXRX_EPSIZE;
	VirtualSerial_CDC_Interface.Config.DataINEndpointDoubleBank       = false;
	VirtualSerial_CDC_Interface.Config.DataOUTEndpointNumber          = rx;
	VirtualSerial_CDC_Interface.Config.DataOUTEndpointSize            = CDC_TXRX_EPSIZE;
	VirtualSerial_CDC_Interface.Config.DataOUTEndpointDoubleBank      = false;
	VirtualSerial_CDC_Interface.Config.NotificationEndpointNumber     = notification;
	VirtualSerial_CDC_Interface.Config.NotificationEndpointSize       = CDC_NOTIFICATION_EPSIZE;
	VirtualSerial_CDC_Interface.Config.NotificationEndpointDoubleBank = false;
}

/** Event handler for the library USB Configuration Changed event. */
void usbSerial::ConfigChanged(void)
{
	bool ConfigSuccess = true;
	ConfigSuccess &= CDC_Device_ConfigureEndpoints(&VirtualSerial_CDC_Interface);
}

/** Event handler for the library USB Control Request reception event. */
void usbSerial::ControlRequest(void)
{
	CDC_Device_ProcessControlRequest(&VirtualSerial_CDC_Interface);
}

void usbSerial::StartOfFrame(void) {
}

void usbSerial::USBTask(void) {
	CDC_Device_ReceiveByte(&VirtualSerial_CDC_Interface);
	CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
}

void usbSerial::initUSBSerial(void)
{
	CDC_Device_CreateBlockingStream(&VirtualSerial_CDC_Interface, &USBSerialStream);

	stdout = &USBSerialStream;
	stdin = &USBSerialStream;
}

#endif
