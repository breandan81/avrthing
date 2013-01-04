#include <avr/power.h>
#include "USBMacros/timer.h"
#include "USBMacros/usbJoy.h"
#include "USBMacros/usbSerial.h"
#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Drivers/Peripheral/TWI.h>

void runUSB(void);
void SetupHardware(void);
int main(void);

