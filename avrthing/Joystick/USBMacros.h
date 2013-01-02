/* Type Defines: */
	/** Type define for the device configuration descriptor structure. This must be defined in the
	 *  application code, as the configuration descriptor contains several sub-descriptors which
	 *  vary between devices, and which describe the device's usage to the host.
	 */
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

#define SERIAL_CONFIG \
	USB_Descriptor_Interface_t               CDC_CCI_Interface; \
	USB_CDC_Descriptor_FunctionalHeader_t    CDC_Functional_Header; \
	USB_CDC_Descriptor_FunctionalACM_t       CDC_Functional_ACM; \
	USB_CDC_Descriptor_FunctionalUnion_t     CDC_Functional_Union; \
	USB_Descriptor_Endpoint_t                CDC_NotificationEndpoint; \
	 \
	USB_Descriptor_Interface_t               CDC_DCI_Interface; \
	USB_Descriptor_Endpoint_t                CDC_DataOutEndpoint; \
	USB_Descriptor_Endpoint_t                CDC_DataInEndpoint; \

