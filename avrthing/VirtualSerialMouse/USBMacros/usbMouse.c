#include "usbMouse.h"
#include <LUFA/Drivers/USB/USB.h>

/** Buffer to hold the previously generated Mouse HID report, for comparison purposes inside the HID class driver. */
static uint8_t PrevMouseHIDReportBuffer[sizeof(USB_MouseReport_Data_t)];

/** LUFA HID Class driver interface configuration and state information. This structure is
 *  passed to all HID Class driver functions, so that multiple instances of the same class
 *  within a device can be differentiated from one another.
 */
USB_ClassInfo_HID_Device_t Mouse_HID_Interface =
	{
		.Config =
			{
				.InterfaceNumber                = 2,

				.ReportINEndpointNumber         = MOUSE_EPNUM,
				.ReportINEndpointSize           = MOUSE_EPSIZE,
				.ReportINEndpointDoubleBank     = false,

				.PrevReportINBuffer             = PrevMouseHIDReportBuffer,
				.PrevReportINBufferSize         = sizeof(PrevMouseHIDReportBuffer),
			},
	};


/** Event handler for the library USB Configuration Changed event. */
void Mouse_ConfigChanged(void)
{
	bool ConfigSuccess = true;
	ConfigSuccess &= HID_Device_ConfigureEndpoints(&Mouse_HID_Interface);
}

/** Event handler for the library USB Control Request reception event. */
void Mouse_ControlRequest(void)
{
	HID_Device_ProcessControlRequest(&Mouse_HID_Interface);
}

/** Event handler for the USB device Start Of Frame event. */
void Mouse_StartOfFrame(void)
{
	HID_Device_MillisecondElapsed(&Mouse_HID_Interface);
}

bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                         uint8_t* const ReportID,
                                         const uint8_t ReportType,
                                         void* ReportData,
                                         uint16_t* const ReportSize)
{
	USB_MouseReport_Data_t* MouseReport = (USB_MouseReport_Data_t*)ReportData;

	MouseReport->Y = -1;
	MouseReport->X = -1;

	*ReportSize = sizeof(USB_MouseReport_Data_t);
	return true;
}

void Mouse_USBTask(void) {
	HID_Device_USBTask(&Mouse_HID_Interface);
}
