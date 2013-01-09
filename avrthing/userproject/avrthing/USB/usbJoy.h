#define USB_JOY 1

typedef struct
{
	int8_t  X; /**< Current absolute joystick X position, as a signed 8-bit integer */
	int8_t  Y; /**< Current absolute joystick Y position, as a signed 8-bit integer */
	uint8_t Button; /**< Bit mask of the currently pressed joystick buttons */
} USB_JoystickReport_Data_t;

#ifdef __GNUG__
class usbJoy: public usbDev {
	private:
	uint8_t PrevJoystickHIDReportBuffer[sizeof(USB_JoystickReport_Data_t)];
	USB_ClassInfo_HID_Device_t Joystick_HID_Interface;

	public:
	usbJoy(); 
	usbJoy(uint8_t);
	void ConfigChanged(void);
	void ControlRequest(void);
	void StartOfFrame(void);
	void USBTask(void);
	bool CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
				uint8_t* const ReportID, const uint8_t ReportType,
				void* ReportData, uint16_t* const ReportSize);
};
#endif
