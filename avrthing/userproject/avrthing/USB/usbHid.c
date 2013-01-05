#include "../../avrthing.h"
//#include "usbHid.h"

#ifdef AVRTHING_USB
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

#endif
