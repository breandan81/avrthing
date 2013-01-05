#include "macros/MouseMacros.h"
#define USB_MOUSE 1

void Mouse_ConfigChanged(void);
void Mouse_ControlRequest(void);
void EVENT_USB_Device_StartOfFrame(void);
void Mouse_USBTask(void);
