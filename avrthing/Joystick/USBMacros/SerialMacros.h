#define SERIAL_CONFIG \
	USB_Descriptor_Interface_Association_t   CDC_IAD; \
	USB_Descriptor_Interface_t               CDC_CCI_Interface; \
	USB_CDC_Descriptor_FunctionalHeader_t    CDC_Functional_Header; \
	USB_CDC_Descriptor_FunctionalACM_t       CDC_Functional_ACM; \
	USB_CDC_Descriptor_FunctionalUnion_t     CDC_Functional_Union; \
	USB_Descriptor_Endpoint_t                CDC_NotificationEndpoint; \
 \
	USB_Descriptor_Interface_t               CDC_DCI_Interface; \
	USB_Descriptor_Endpoint_t                CDC_DataOutEndpoint; \
	USB_Descriptor_Endpoint_t                CDC_DataInEndpoint;

#define CDC_NOTIFICATION_EPNUM         2
#define CDC_TX_EPNUM                   3
#define CDC_RX_EPNUM                   4
#define CDC_NOTIFICATION_EPSIZE        8
#define CDC_TXRX_EPSIZE                16

#define CDC_CONFIG_DEFAULT \
	.CDC_IAD = \
		{ \
			.Header                 = {.Size = sizeof(USB_Descriptor_Interface_Association_t), .Type = DTYPE_InterfaceAssociation}, \
 \
			.FirstInterfaceIndex    = 0, \
			.TotalInterfaces        = 2, \
 \
			.Class                  = CDC_CSCP_CDCClass, \
			.SubClass               = CDC_CSCP_ACMSubclass, \
			.Protocol               = CDC_CSCP_ATCommandProtocol, \
 \
			.IADStrIndex            = NO_DESCRIPTOR \
		}, \
 \
	.CDC_CCI_Interface = \
		{ \
			.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface}, \
 \
			.InterfaceNumber        = 0, \
			.AlternateSetting       = 0, \
 \
			.TotalEndpoints         = 1, \
 \
			.Class                  = CDC_CSCP_CDCClass, \
			.SubClass               = CDC_CSCP_ACMSubclass, \
			.Protocol               = CDC_CSCP_ATCommandProtocol, \
 \
			.InterfaceStrIndex      = NO_DESCRIPTOR \
		}, \
 \
	.CDC_Functional_Header = \
		{ \
			.Header                 = {.Size = sizeof(USB_CDC_Descriptor_FunctionalHeader_t), .Type = DTYPE_CSInterface}, \
			.Subtype                = CDC_DSUBTYPE_CSInterface_Header, \
 \
			.CDCSpecification       = VERSION_BCD(01.10), \
		}, \
 \
	.CDC_Functional_ACM = \
		{ \
			.Header                 = {.Size = sizeof(USB_CDC_Descriptor_FunctionalACM_t), .Type = DTYPE_CSInterface}, \
			.Subtype                = CDC_DSUBTYPE_CSInterface_ACM, \
 \
			.Capabilities           = 0x06, \
		}, \
 \
	.CDC_Functional_Union = \
		{ \
			.Header                 = {.Size = sizeof(USB_CDC_Descriptor_FunctionalUnion_t), .Type = DTYPE_CSInterface}, \
			.Subtype                = CDC_DSUBTYPE_CSInterface_Union, \
 \
			.MasterInterfaceNumber  = 0, \
			.SlaveInterfaceNumber   = 1, \
		}, \
 \
	.CDC_NotificationEndpoint = \
		{ \
			.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint}, \
 \
			.EndpointAddress        = (ENDPOINT_DIR_IN | CDC_NOTIFICATION_EPNUM), \
			.Attributes             = (EP_TYPE_INTERRUPT | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA), \
			.EndpointSize           = CDC_NOTIFICATION_EPSIZE, \
			.PollingIntervalMS      = 0xFF \
		}, \
 \
	.CDC_DCI_Interface = \
		{ \
			.Header                 = {.Size = sizeof(USB_Descriptor_Interface_t), .Type = DTYPE_Interface}, \
 \
			.InterfaceNumber        = 1, \
			.AlternateSetting       = 0, \
 \
			.TotalEndpoints         = 2, \
 \
			.Class                  = CDC_CSCP_CDCDataClass, \
			.SubClass               = CDC_CSCP_NoDataSubclass, \
			.Protocol               = CDC_CSCP_NoDataProtocol, \
 \
			.InterfaceStrIndex      = NO_DESCRIPTOR \
		}, \
 \
	.CDC_DataOutEndpoint = \
		{ \
			.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint}, \
 \
			.EndpointAddress        = (ENDPOINT_DIR_OUT | CDC_RX_EPNUM), \
			.Attributes             = (EP_TYPE_BULK | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA), \
			.EndpointSize           = CDC_TXRX_EPSIZE, \
			.PollingIntervalMS      = 0x01 \
		}, \
 \
	.CDC_DataInEndpoint = \
		{ \
			.Header                 = {.Size = sizeof(USB_Descriptor_Endpoint_t), .Type = DTYPE_Endpoint}, \
 \
			.EndpointAddress        = (ENDPOINT_DIR_IN | CDC_TX_EPNUM), \
			.Attributes             = (EP_TYPE_BULK | ENDPOINT_ATTR_NO_SYNC | ENDPOINT_USAGE_DATA), \
			.EndpointSize           = CDC_TXRX_EPSIZE, \
			.PollingIntervalMS      = 0x01 \
		}

#define CREATE_CDC_DEVICE(A, TX, RX, NOTIFICATION) \
USB_ClassInfo_CDC_Device_t A = \
	{ \
		.Config = \
			{ \
				.ControlInterfaceNumber         = 0, \
 \
				.DataINEndpointNumber           = TX, \
				.DataINEndpointSize             = CDC_TXRX_EPSIZE, \
				.DataINEndpointDoubleBank       = false, \
 \
				.DataOUTEndpointNumber          = RX, \
				.DataOUTEndpointSize            = CDC_TXRX_EPSIZE, \
				.DataOUTEndpointDoubleBank      = false, \
 \
				.NotificationEndpointNumber     = NOTIFICATION, \
				.NotificationEndpointSize       = CDC_NOTIFICATION_EPSIZE, \
				.NotificationEndpointDoubleBank = false, \
			}, \
	}
