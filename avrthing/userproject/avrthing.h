#ifndef AVRTHING_H
#define AVRTHING_H


//C includes
/*
extern "C" {
#include "usbSerial.h"
}
*/
//C++ includes
#include "avrthing/timer.h"
#include "avrthing/USB/Descriptors.h"
#include "avrthing/USB/usb.h"
//#include "avrthing/USB/usbJoy.h"
#include "avrthing/USB/usbMouse.h"
#include "avrthing/USB/usbSerial.h"
#include "avrthing/digitalIO.h"
#include "avrthing/analogIO.h"
#include "avrthing/pins/awesomedip.h"

//defines
#define MHZ 16 // change this if you are using a different clockspeed, note USB needs an XTAL source of at least 8 MHZ to function

//globals
#define JOYSTICK_EPNUM                    1
#define JOYSTICK_EPSIZE                   8

#define MOUSE_EPNUM                    1
#define MOUSE_EPSIZE                   8

#define CDC_NOTIFICATION_EPNUM         2
#define CDC_TX_EPNUM                   3
#define CDC_RX_EPNUM                   4
#define CDC_TXRX_EPSIZE                16
#define CDC_NOTIFICATION_EPSIZE        8

#endif
