#include "../../avrthing.h"
#ifdef AVRTHING_USB

usbDev::usbDev() {
	
}

void runUSB(void)
{
	int len=sizeof(usbDevs)/sizeof(usbDev *);
	for(int i=0;i<len;i++)
		usbDevs[i]->USBTask();
	USB_USBTask();
}

/** Event handler for the library USB Connection event. */
void EVENT_USB_Device_Connect(void)
{
}

/** Event handler for the library USB Disconnection event. */
void EVENT_USB_Device_Disconnect(void)
{
}

/** Event handler for the library USB Configuration Changed event. */
void EVENT_USB_Device_ConfigurationChanged(void)
{
	int len=sizeof(usbDevs)/sizeof(usbDev *);
	for(int i=0;i<len;i++)
		usbDevs[i]->ConfigChanged();
	USB_Device_EnableSOFEvents();
}

/** Event handler for the library USB Control Request reception event. */
void EVENT_USB_Device_ControlRequest(void)
{
	int len=sizeof(usbDevs)/sizeof(usbDev *);
	for(int i=0;i<len;i++)
		usbDevs[i]->ControlRequest();
}

/** Event handler for the USB device Start Of Frame event. */
void EVENT_USB_Device_StartOfFrame(void)
{
	int len=sizeof(usbDevs)/sizeof(usbDev *);
	for(int i=0;i<len;i++)
		usbDevs[i]->StartOfFrame();
}

/** HID class driver callback function for the processing of HID reports from the host.
 *
 *  \param[in] HIDInterfaceInfo  Pointer to the HID class interface configuration structure being referenced
 *  \param[in] ReportID    Report ID of the received report from the host
 *  \param[in] ReportType  The type of report that the host has sent, either HID_REPORT_ITEM_Out or HID_REPORT_ITEM_Feature
 *  \param[in] ReportData  Pointer to a buffer where the received report has been stored
 *  \param[in] ReportSize  Size in bytes of the received HID report
 */
void CALLBACK_HID_Device_ProcessHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
                                          const uint8_t ReportID,
                                          const uint8_t ReportType,
                                          const void* ReportData,
                                          const uint16_t ReportSize)
{
	// Unused (but mandatory for the HID class driver) in this demo, since there are no Host->Device reports
}

#endif // AVRTHING_USB
