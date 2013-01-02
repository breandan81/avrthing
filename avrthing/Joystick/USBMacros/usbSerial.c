#include <avr/io.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <string.h>
#include <stdio.h>

#include "Descriptors.h"

#include <LUFA/Version.h>
#include <LUFA/Drivers/USB/USB.h>

/** LUFA CDC Class driver interface configuration and state information. This structure is
 *  passed to all CDC Class driver functions, so that multiple instances of the same class
 *  within a device can be differentiated from one another.
 */
CREATE_CDC_DEVICE(Virtual_CDC_Interface, CDC_TX_EPNUM, CDC_RX_EPNUM, CDC_NOTIFICATION_EPNUM);

/** Standard file stream for the CDC interface when set up, so that the virtual CDC COM port can be
 *  used like any regular character stream in the C APIs
 */
static FILE USBSerialStream;

void Ser_USBTask(void)
{
	CDC_Device_ReceiveByte(&Virtual_CDC_Interface);
        CDC_Device_USBTask(&Virtual_CDC_Interface);
}

/** Main program entry point. This routine contains the overall program flow, including initial
 *  setup of all components and the main program loop.
 */
void initUSBSerial(void)
{
	/* Create a regular character stream for the interface so that it can be used with the stdio.h functions */
	CDC_Device_CreateBlockingStream(&Virtual_CDC_Interface, &USBSerialStream);

	stdout = &USBSerialStream;
	stdin = &USBSerialStream;
}

/** Event handler for the library USB Configuration Changed event. */
void Ser_ConfigChanged(void)
{
	bool ConfigSuccess = true;

	ConfigSuccess &= CDC_Device_ConfigureEndpoints(&Virtual_CDC_Interface);
}

/** Event handler for the library USB Control Request reception event. */
void Ser_ControlRequest(void)
{
	CDC_Device_ProcessControlRequest(&Virtual_CDC_Interface);
}


