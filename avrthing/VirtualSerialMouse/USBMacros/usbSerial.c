#include "usbSerial.h"

/** LUFA CDC Class driver interface configuration and state information. This structure is
 *  passed to all CDC Class driver functions, so that multiple instances of the same class
 *  within a device can be differentiated from one another.
 */
USB_ClassInfo_CDC_Device_t VirtualSerial_CDC_Interface =
	{
		.Config =
			{
				.ControlInterfaceNumber         = 0,

				.DataINEndpointNumber           = CDC_TX_EPNUM,
				.DataINEndpointSize             = CDC_TXRX_EPSIZE,
				.DataINEndpointDoubleBank       = false,

				.DataOUTEndpointNumber          = CDC_RX_EPNUM,
				.DataOUTEndpointSize            = CDC_TXRX_EPSIZE,
				.DataOUTEndpointDoubleBank      = false,

				.NotificationEndpointNumber     = CDC_NOTIFICATION_EPNUM,
				.NotificationEndpointSize       = CDC_NOTIFICATION_EPSIZE,
				.NotificationEndpointDoubleBank = false,
			},
	};

/** Checks for changes in the position of the board joystick, sending strings to the host upon each change. */
void sendTest(void)
{
	char*       ReportString  = NULL;

	ReportString="Test.\r\n";

	if (ReportString != NULL)
	{
		CDC_Device_SendString(&VirtualSerial_CDC_Interface, ReportString);
	}
}

/** Event handler for the library USB Configuration Changed event. */
void Ser_ConfigChanged(void)
{
	bool ConfigSuccess = true;

	ConfigSuccess &= CDC_Device_ConfigureEndpoints(&VirtualSerial_CDC_Interface);
}

/** Event handler for the library USB Control Request reception event. */
void Ser_ControlRequest(void)
{
	CDC_Device_ProcessControlRequest(&VirtualSerial_CDC_Interface);
}

void Ser_USBTask(void) {
//	sendTest();
	CDC_Device_ReceiveByte(&VirtualSerial_CDC_Interface);
	CDC_Device_USBTask(&VirtualSerial_CDC_Interface);
}

static FILE USBSerialStream;

void initUSBSerial(void)
{
	CDC_Device_CreateBlockingStream(&VirtualSerial_CDC_Interface, &USBSerialStream);

	stdout = &USBSerialStream;
	stdin = &USBSerialStream;
}

