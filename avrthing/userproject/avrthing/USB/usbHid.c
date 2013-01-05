#include "usb.h"
#include "../timer.h"
#include <LUFA/Drivers/USB/USB.h>

// Just a sketch, an idea...
bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                         uint8_t* const ReportID,
                                         const uint8_t ReportType,
                                         void* ReportData,
                                         uint16_t* const ReportSize)
{
	for(i=0; i<numHID; i++)
		if(HIDDevs[i]->InterfaceInfo == HIDInterfaceInfo)
			return HIDDevs[i]->CreateHIDReport(ReportData,ReportSize);

	return false;
}

