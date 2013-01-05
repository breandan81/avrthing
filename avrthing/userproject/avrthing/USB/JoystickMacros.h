#include "Descriptors.h"

	/* Use the HID class driver's standard Joystick report.
	 *   Number of Axis: 2 (X/Y)
	 *   Min X/Y Axis values: -100
	 *   Max X/Y Axis values:  100
	 *   Min physical X/Y Axis values (used to determine resolution): -1
	 *   Max physical X/Y Axis values (used to determine resolution):  1
	 *   Buttons: 2
	 */

#define JOYSTICK_REPORT(A, B, C, D, E, F) \
const USB_Descriptor_HIDReport_Datatype_t PROGMEM JoystickReport[] = \
{ \
	HID_DESCRIPTOR_JOYSTICK(A, B, C, D, E, F) \
};
#define JOYSTICK_REPORT_DEFAULT JOYSTICK_REPORT(2, -100, 100, -1, 1, 2)

#define JOYSTICK_CONFIG \
	USB_Descriptor_Interface_t            HID_Interface; \
	USB_HID_Descriptor_HID_t              HID_JoystickHID; \
        USB_Descriptor_Endpoint_t             HID_ReportINEndpoint;

#define HID_JS_CONFIG_DEFAULT \
.HID_Interface = \
	{ \
		.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface}, \
 \
		.InterfaceNumber        = 0x00, \
		.AlternateSetting       = 0x00, \
 \
		.TotalEndpoints         = 1, \
 \
		.Class                  = HID_CSCP_HIDClass, \
		.SubClass               = HID_CSCP_NonBootSubclass, \
		.Protocol               = HID_CSCP_NonBootProtocol, \
 \
		.InterfaceStrIndex      = NO_DESCRIPTOR \
	}, \
 \
.HID_JoystickHID = \
	{ \
		.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID}, \
 \
		.HIDSpec                = VERSION_BCD(01.11), \
		.CountryCode            = 0x00, \
		.TotalReportDescriptors = 1, \
		.HIDReportType          = HID_DTYPE_Report, \
		.HIDReportLength        = sizeof(JoystickReport) \
	}, \
 \
.HID_ReportINEndpoint = \
	{ \
		.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint}, \
 \
		.EndpointAddress        = (ENDPOINT_DIR_IN | JOYSTICK_EPNUM), \
		.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA), \
		.EndpointSize           = JOYSTICK_EPSIZE, \
		.PollingIntervalMS      = 0x01 \
	}


#define GETDESCRIPTOR_CALLBACK_HID_JS \
		case HID_DTYPE_HID: \
			Address = &ConfigurationDescriptor.HID_JoystickHID; \
			Size    = sizeof(USB_HID_Descriptor_HID_t); \
			break; \
		case HID_DTYPE_Report: \
			Address = &JoystickReport; \
			Size    = sizeof(JoystickReport); \
			break;
