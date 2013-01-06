#include "../../avrthing.h"
#ifdef USB_MOUSE

usbMouse::usbMouse() {
	Mouse_HID_Interface.Config.InterfaceNumber=2;
	Mouse_HID_Interface.Config.ReportINEndpointNumber         = MOUSE_EPNUM;
	Mouse_HID_Interface.Config.ReportINEndpointSize           = MOUSE_EPSIZE;
	Mouse_HID_Interface.Config.ReportINEndpointDoubleBank     = false;
	Mouse_HID_Interface.Config.PrevReportINBuffer             = PrevMouseHIDReportBuffer;
	Mouse_HID_Interface.Config.PrevReportINBufferSize         = sizeof(USB_MouseReport_Data_t);
	
}

usbMouse::usbMouse(int endpoint) {
	Mouse_HID_Interface.Config.InterfaceNumber=2;
	Mouse_HID_Interface.Config.ReportINEndpointNumber         = endpoint;
	Mouse_HID_Interface.Config.ReportINEndpointSize           = MOUSE_EPSIZE;
	Mouse_HID_Interface.Config.ReportINEndpointDoubleBank     = false;
	Mouse_HID_Interface.Config.PrevReportINBuffer             = PrevMouseHIDReportBuffer;
	Mouse_HID_Interface.Config.PrevReportINBufferSize         = sizeof(USB_MouseReport_Data_t);
	
}

/** Event handler for the library USB Configuration Changed event. */
void usbMouse::ConfigChanged(void)
{
	bool ConfigSuccess = true;
	ConfigSuccess &= HID_Device_ConfigureEndpoints(&Mouse_HID_Interface);
}

/** Event handler for the library USB Control Request reception event. */
void usbMouse::ControlRequest(void)
{
	HID_Device_ProcessControlRequest(&Mouse_HID_Interface);
}

/** Event handler for the USB device Start Of Frame event. */
void usbMouse::StartOfFrame(void)
{
	HID_Device_MillisecondElapsed(&Mouse_HID_Interface);
}

void usbMouse::USBTask(void)
{
	HID_Device_USBTask(&Mouse_HID_Interface);
}

bool usbMouse::CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
				uint8_t* const ReportID, const uint8_t ReportType,
				void* ReportData, uint16_t* const ReportSize)
{
	USB_MouseReport_Data_t* MouseReport = (USB_MouseReport_Data_t*)ReportData;

	MouseReport->Y = -1;
	MouseReport->X = -1;
	MouseReport->Button=0;

	*ReportSize = sizeof(USB_MouseReport_Data_t);
	return true;
}

extern "C" bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
				uint8_t* const ReportID, const uint8_t ReportType,
				void* ReportData, uint16_t* const ReportSize)
{
	USB_MouseReport_Data_t* MouseReport = (USB_MouseReport_Data_t*)ReportData;

	MouseReport->Y = -1;
	MouseReport->X = -1;
	MouseReport->Button=0;

	*ReportSize = sizeof(USB_MouseReport_Data_t);
	return true;
}

#endif
