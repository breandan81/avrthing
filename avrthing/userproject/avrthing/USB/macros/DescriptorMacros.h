
/*
   These two macros begin and end the typedef for the
   USB_Descriptor_Configuration_t, which contains sections for each device
   type.  Those blocks are in CONFIG_TYPE_<devtype>() macros.
*/

#define CONFIG_BEGIN \
typedef struct \
{ \
	USB_Descriptor_Configuration_Header_t Config;

#define CONFIG_END \
} USB_Descriptor_Configuration_t;

/*
   The meat of things, the configuration descriptor.  The type is defined in
   the above macros, with blocks for each device type.  This creates the
   descriptor and stores it in flash memory.  The subsections are
   <devtype>_CONFIG_DESC().
*/

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

/*
   This macro builds a descriptor for the device with options for the Class,
   Subclass, Protocol, VID, PID, and Release number.  The next macro creates a
   default version of this descriptor stolen from the LUFA VirtualSerialMouse
   demo.
*/

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
};

#define DEVICE_DESC_DEFAULT DEVICE_DESC(USB_CSCP_NoDeviceClass, USB_CSCP_NoDeviceSubclass, USB_CSCP_NoDeviceProtocol, 0x03EB, 0x2043, 00.01)

/*
   The GetDescriptor callback function does what it sends on the tin.
   There are cases in the switch() block for different device types,
   with names like so: GETDESCRIPTOR_CALLBACK_<devtype>
*/

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

/*
   Simple macros for various strings....
*/

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

