#ifndef _VIRTUALSERIAL_MOUSE_H_
#define _VIRTUALSERIAL_MOUSE_H_

#include <LUFA/Drivers/USB/USB.h>

#define CDC_NOTIFICATION_EPNUM         2
#define CDC_TX_EPNUM                   3
#define CDC_RX_EPNUM                   4
#define CDC_TXRX_EPSIZE                16
#define CDC_NOTIFICATION_EPSIZE        8

void initUSBSerial(void);
void Ser_USBTask(void);
void Ser_ConfigChanged(void);
void Ser_ControlRequest(void);
#endif

