#include "../../avrthing.h"
#ifdef USB_JOY

usbJoy::usbJoy() {
	Joystick_HID_Interface.Config.InterfaceNumber              = 2;
	Joystick_HID_Interface.Config.ReportINEndpointNumber       = JOYSTICK_EPNUM;
	Joystick_HID_Interface.Config.ReportINEndpointSize         = JOYSTICK_EPSIZE;
	Joystick_HID_Interface.Config.ReportINEndpointDoubleBank   = false;
	Joystick_HID_Interface.Config.PrevReportINBuffer           = PrevJoystickHIDReportBuffer;
	Joystick_HID_Interface.Config.PrevReportINBufferSize       = sizeof(PrevJoystickHIDReportBuffer);
}

void usbJoy::USBTask(void)
{
	HID_Device_USBTask(&Joystick_HID_Interface); 
}

void usbJoy::ConfigChanged(void)
{
	bool ConfigSuccess = true;
	ConfigSuccess &= HID_Device_ConfigureEndpoints(&Joystick_HID_Interface);
	USB_Device_EnableSOFEvents();
}

void usbJoy::ControlRequest(void)
{
	HID_Device_ProcessControlRequest(&Joystick_HID_Interface);
}

void usbJoy::StartOfFrame(void)
{
	HID_Device_MillisecondElapsed(&Joystick_HID_Interface);
}

uint8_t *usbJoy::getPrevReport(void)
{
	return PrevJoystickHIDReportBuffer;
}

extern "C" bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
					uint8_t* const ReportID, const uint8_t ReportType,
					void* ReportData, uint16_t* const ReportSize)
{
	USB_JoystickReport_Data_t* JoystickReport = (USB_JoystickReport_Data_t*)ReportData;

	JoystickReport->Y =  (millis()/10) % 200 - 100;
	JoystickReport->X =  (millis()/10) % 200 - 100;
	JoystickReport->Button = 0;
//	printf("test: %d\r\n",millis());

	*ReportSize = sizeof(USB_JoystickReport_Data_t);
	return true;
}
#endif
