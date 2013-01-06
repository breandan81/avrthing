#include "usbDev.h"

#define AVRTHING_USB 1
#ifdef __GNUG__
extern "C" {
#endif
void runUSB(void);
void EVENT_USB_Device_Connect(void);
void EVENT_USB_Device_Disconnect(void);
void EVENT_USB_Device_ConfigurationChanged(void);
void EVENT_USB_Device_ControlRequest(void);
void EVENT_USB_Device_StartOfFrame(void);
#ifdef __GNUG__
}
#endif
