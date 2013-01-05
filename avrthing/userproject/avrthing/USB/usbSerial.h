#include "macros/SerialMacros.h"
#define USB_CDC 1

void initUSBSerial(void);
void Ser_USBTask(void);
void Ser_ConfigChanged(void);
void Ser_ControlRequest(void);
