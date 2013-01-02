#define CONFIG_BEGIN \
typedef struct \
{ \
	USB_Descriptor_Configuration_Header_t Config;
#define CONFIG_END \
} USB_Descriptor_Configuration_t;

#define JOYSTICK_CONFIG \
	USB_Descriptor_Interface_t            HID_Interface; \
	USB_HID_Descriptor_HID_t              HID_JoystickHID; \
        USB_Descriptor_Endpoint_t             HID_ReportINEndpoint;

#define DEVICE_DESC(A, B, C, D, E, F) \
const USB_Descriptor_Device_t PROGMEM DeviceDescriptor = \
{ \
	.Header                 = {.Size = sizeof(USB_Descriptor_Device_t), .Type = DTYPE_Device}, \
 \
	.USBSpecification       = VERSION_BCD(01.10), \
	.Class                  = A, \
	.SubClass               = B, \
	.Protocol               = C, \
 \
	.Endpoint0Size          = FIXED_CONTROL_ENDPOINT_SIZE, \
 \
	.VendorID               = D, \
	.ProductID              = E, \
	.ReleaseNumber          = VERSION_BCD(F), \
 \
	.ManufacturerStrIndex   = 0x01, \
	.ProductStrIndex        = 0x02, \
	.SerialNumStrIndex      = NO_DESCRIPTOR, \
 \
	.NumberOfConfigurations = FIXED_NUM_CONFIGURATIONS \
}; \

#define DEVICE_DESC_DEFAULT DEVICE_DESC(USB_CSCP_NoDeviceClass, USB_CSCP_NoDeviceSubclass, USB_CSCP_NoDeviceProtocol, 0x03EB, 0x2043, 00.01)

#define CONFIG_DESC_BEGIN(A, B, C) \
const USB_Descriptor_Configuration_t PROGMEM ConfigurationDescriptor = \
{ \
	.Config = \
		{ \
			.Header                 = {.Size = sizeof(USB_Descriptor_Configuration_Header_t), .Type = DTYPE_Configuration}, \
 \
			.TotalConfigurationSize = sizeof(USB_Descriptor_Configuration_t), \
			.TotalInterfaces        = A, \
 \
			.ConfigurationNumber    = B, \
			.ConfigurationStrIndex  = NO_DESCRIPTOR, \
 \
			.ConfigAttributes       = (USB_CONFIG_ATTR_RESERVED | USB_CONFIG_ATTR_SELFPOWERED), \
 \
			.MaxPowerConsumption    = USB_CONFIG_POWER_MA(C) \
		}, \

#define CONFIG_DESC_END };

#define LANGUAGE(A, B) \
const USB_Descriptor_String_t PROGMEM LanguageString = \
{ \
	.Header                 = {.Size = USB_STRING_LEN(B), .Type = DTYPE_String}, \
	.UnicodeString          = {A} \
};

#define LANG_DEFAULT LANGUAGE(LANGUAGE_ID_ENG, 1)


#define MANUFACTURER(A, B) \
const USB_Descriptor_String_t PROGMEM ManufacturerString = \
{ \
	.Header                 = {.Size = USB_STRING_LEN(B), .Type = DTYPE_String}, \
	.UnicodeString          = A \
};

#define PRODUCT(A, B) \
const USB_Descriptor_String_t PROGMEM ProductString = \
{ \
	.Header                 = {.Size = USB_STRING_LEN(B), .Type = DTYPE_String}, \
	.UnicodeString          = A \
};

#define GETDESCRIPTOR_CALLBACK_BEGIN \
uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue, \
                                    const uint8_t wIndex, \
                                    const void** const DescriptorAddress) \
{ \
	const uint8_t  DescriptorType   = (wValue >> 8); \
	const uint8_t  DescriptorNumber = (wValue & 0xFF); \
 \
	const void* Address = NULL; \
	uint16_t    Size    = NO_DESCRIPTOR; \
 \
	switch (DescriptorType) \
	{ \
		case DTYPE_Device: \
			Address = &DeviceDescriptor; \
			Size    = sizeof(USB_Descriptor_Device_t); \
			break; \
		case DTYPE_Configuration: \
			Address = &ConfigurationDescriptor; \
			Size    = sizeof(USB_Descriptor_Configuration_t); \
			break; \
		case DTYPE_String: \
			switch (DescriptorNumber) \
			{ \
				case 0x00: \
					Address = &LanguageString; \
					Size    = pgm_read_byte(&LanguageString.Header.Size); \
					break; \
				case 0x01: \
					Address = &ManufacturerString; \
					Size    = pgm_read_byte(&ManufacturerString.Header.Size); \
					break; \
				case 0x02: \
					Address = &ProductString; \
					Size    = pgm_read_byte(&ProductString.Header.Size); \
					break; \
			} \
 \
			break; 


#define GETDESCRIPTOR_CALLBACK_END \
	} \
 \
	*DescriptorAddress = Address; \
	return Size; \
}

