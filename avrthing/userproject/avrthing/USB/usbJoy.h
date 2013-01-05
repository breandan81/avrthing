
#define USB_JOY 1
JOYSTICK_REPORT_DEFAULT

typedef struct
{
	int8_t  X; /**< Current absolute joystick X position, as a signed 8-bit integer */
	int8_t  Y; /**< Current absolute joystick Y position, as a signed 8-bit integer */
	uint8_t Button; /**< Bit mask of the currently pressed joystick buttons */
} USB_JoystickReport_Data_t;

void JS_ConfigChanged(void);
void JS_ControlRequest(void);
void JS_StartOfFrame(void);
void JS_USBTask(void);

