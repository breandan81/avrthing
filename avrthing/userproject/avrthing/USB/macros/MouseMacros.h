#define MOUSE_CONFIG \
	USB_Descriptor_Interface_t	HID_Interface; \
	USB_HID_Descriptor_HID_t	HID_MouseHID; \
	USB_Descriptor_Endpoint_t	HID_ReportINEndpoint;

#define MOUSE_REPORT(A, B, C, D, E, F) \
const USB_Descriptor_HIDReport_Datatype_t PROGMEM MouseReport[] = \
{ \
	HID_DESCRIPTOR_MOUSE(A, B, C, D, E, F) \
};

#define MOUSE_REPORT_DEFAULT MOUSE_REPORT(-1, 1, -1, 1, 3, false)

#define MOUSE_CONFIG_DESC \
	.HID_Interface = \
		{ \
			.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface}, \
 \
			.InterfaceNumber        = 2, \
			.AlternateSetting       = 0, \
 \
			.TotalEndpoints         = 1, \
 \
			.Class                  = HID_CSCP_HIDClass, \
			.SubClass               = HID_CSCP_BootSubclass, \
			.Protocol               = HID_CSCP_MouseBootProtocol, \
 \
			.InterfaceStrIndex      = NO_DESCRIPTOR \
		}, \
 \
	.HID_MouseHID = \
		{ \
			.Header                 = {.Size = sizeof(USB_HID_Descriptor_HID_t), .Type = HID_DTYPE_HID}, \
 \
			.HIDSpec                = VERSION_BCD(01.11), \
			.CountryCode            = 0x00, \
			.TotalReportDescriptors = 1, \
			.HIDReportType          = HID_DTYPE_Report, \
			.HIDReportLength        = sizeof(MouseReport) \
		}, \
 \
	.HID_ReportINEndpoint = \
		{ \
			.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint}, \
 \
			.EndpointAddress        = (ENDPOINT_DIR_IN | MOUSE_EPNUM), \
			.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA), \
			.EndpointSize           = MOUSE_EPSIZE, \
			.PollingIntervalMS      = 0x01 \
		} 

#define GETDESCRIPTOR_CALLBACK_MOUSE \
		case HID_DTYPE_HID: \
			Address = &ConfigurationDescriptor.HID_MouseHID; \
			Size    = sizeof(USB_HID_Descriptor_HID_t); \
			break; \
		case HID_DTYPE_Report: \
			Address = &MouseReport; \
			Size    = sizeof(MouseReport); \
			break;
