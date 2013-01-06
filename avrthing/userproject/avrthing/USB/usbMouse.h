#include "macros/MouseMacros.h"
#define USB_MOUSE 1

#ifdef __GNUG__
class usbMouse : public usbDev {
	private:
	uint8_t PrevMouseHIDReportBuffer[sizeof(USB_MouseReport_Data_t)];
	USB_ClassInfo_HID_Device_t Mouse_HID_Interface;

	public:
	usbMouse();
	usbMouse(int);
	void ConfigChanged(void);
	void ControlRequest(void);
	void StartOfFrame(void);
	void USBTask(void);
	bool CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
						uint8_t* const ReportID,
						const uint8_t ReportType,
						void* ReportData,
						uint16_t* const ReportSize);
};

extern "C" bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
				uint8_t* const ReportID, const uint8_t ReportType,
				void* ReportData, uint16_t* const ReportSize);

#endif
