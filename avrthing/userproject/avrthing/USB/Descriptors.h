#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

#include <avr/pgmspace.h>
#include <LUFA/Drivers/USB/USB.h>
#include "macros/DescriptorMacros.h"
#include "macros/SerialMacros.h"
#include "macros/MouseMacros.h"
#include "macros/JoystickMacros.h"

#define JOYSTICK_EPNUM                    1
#define JOYSTICK_EPSIZE                   8

#define MOUSE_EPNUM                    1
#define MOUSE_EPSIZE                   8

#define CDC_NOTIFICATION_EPNUM         2
#define CDC_TX_EPNUM                   3
#define CDC_RX_EPNUM                   4
#define CDC_TXRX_EPSIZE                16
#define CDC_NOTIFICATION_EPSIZE        8

CONFIG_BEGIN
SERIAL_CONFIG
//JOYSTICK_CONFIG
MOUSE_CONFIG
CONFIG_END

uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
                                    const uint8_t wIndex,
                                    const void** const DescriptorAddress)
                                    ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL_PTR_ARG(3);

#endif


