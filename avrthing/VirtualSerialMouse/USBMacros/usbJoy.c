#include "usbJoy.h"
#include "timer.h"
#include <LUFA/Drivers/USB/USB.h>

static uint8_t PrevJoystickHIDReportBuffer[sizeof(USB_JoystickReport_Data_t)];

USB_ClassInfo_HID_Device_t Joystick_HID_Interface =
	{
		.Config =
			{
				.InterfaceNumber              = 0,

				.ReportINEndpointNumber       = JOYSTICK_EPNUM,
				.ReportINEndpointSize         = JOYSTICK_EPSIZE,
				.ReportINEndpointDoubleBank   = false,

				.PrevReportINBuffer           = PrevJoystickHIDReportBuffer,
				.PrevReportINBufferSize       = sizeof(PrevJoystickHIDReportBuffer),
			},
	};

void JS_USBTask(void)
{
	HID_Device_USBTask(&Joystick_HID_Interface); 
}

void JS_ConfigChanged(void)
{
	bool ConfigSuccess = true;
	ConfigSuccess &= HID_Device_ConfigureEndpoints(&Joystick_HID_Interface);
	USB_Device_EnableSOFEvents();
}

void JS_ControlRequest(void)
{
	HID_Device_ProcessControlRequest(&Joystick_HID_Interface);
}

void JS_StartOfFrame(void)
{
	HID_Device_MillisecondElapsed(&Joystick_HID_Interface);
}

bool printflag;

bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                         uint8_t* const ReportID,
                                         const uint8_t ReportType,
                                         void* ReportData,
                                         uint16_t* const ReportSize)
{
	USB_JoystickReport_Data_t* JoystickReport = (USB_JoystickReport_Data_t*)ReportData;

	JoystickReport->Y =  (millis()/10) % 200 - 100;
	JoystickReport->X =  (millis()/10) % 200 - 100;
	if(millis()%100==0)
		if(printflag)
			printf("X: %d\tY: %d\tmillis(): %lu\r\n",JoystickReport->X,JoystickReport->X,millis());
		else
			printflag==false;
	else
		printflag=true;

	*ReportSize = sizeof(USB_JoystickReport_Data_t);
	return false;
}

