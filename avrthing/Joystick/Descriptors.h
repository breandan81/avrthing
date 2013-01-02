#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

#include <avr/pgmspace.h>
#include <LUFA/Drivers/USB/USB.h>
#include "USBMacros/USBMacros.h"
#include "USBMacros/JoystickMacros.h"
#include "USBMacros/SerialMacros.h"

CONFIG_BEGIN
JOYSTICK_CONFIG
SERIAL_CONFIG
CONFIG_END

#define JOYSTICK_EPNUM 1
#define JOYSTICK_EPSIZE 8

#define CDC_NOTIFICATION_EPNUM         2
#define CDC_TX_EPNUM                   3
#define CDC_RX_EPNUM                   4
#define CDC_NOTIFICATION_EPSIZE        8
#define CDC_TXRX_EPSIZE                16

		uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
		                                    const uint8_t wIndex,
		                                    const void** const DescriptorAddress)
		                                    ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL_PTR_ARG(3);

#endif

