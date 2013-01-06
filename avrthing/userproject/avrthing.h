#ifndef AVRTHING_H
#define AVRTHING_H


//C includes
#ifdef __GNUG__
extern "C" {
#endif
#include <avr/interrupt.h>
#include "avrthing/timer.h"
#include "avrthing/USB/Descriptors.h"
//#include "avrthing/USB/usbJoy.h"
#include "avrthing/USB/usbSerial.h"
#ifdef __GNUG__
}
#endif
//C++ includes
#include "avrthing/digitalIO.h"
#include "avrthing/analogIO.h"
#include "avrthing/pins/awesomedip.h"
#include "avrthing/USB/usb.h"
#include "avrthing/USB/usbMouse.h"

//defines
#define MHZ 16 // change this if you are using a different clockspeed, note USB needs an XTAL source of at least 8 MHZ to function

#define JOYSTICK_EPNUM                    1
#define JOYSTICK_EPSIZE                   8

#define MOUSE_EPNUM                    6
#define MOUSE1_EPNUM                   1
#define MOUSE2_EPNUM                   6
#define MOUSE_EPSIZE                   8

#define CDC_NOTIFICATION_EPNUM         2
#define CDC_TX_EPNUM                   3
#define CDC_RX_EPNUM                   4
#define CDC_TXRX_EPSIZE                16
#define CDC_NOTIFICATION_EPSIZE        8

#ifdef __GNUG__
extern usbDev **usbDevs;
extern usbMouse *mouse1;
#endif
#endif
