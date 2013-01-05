#ifndef _DESCRIPTORS_H_
#define _DESCRIPTORS_H_

#include <avr/pgmspace.h>
#include <LUFA/Drivers/USB/USB.h>
#include "../../avrthing.h"
#include "macros/DescriptorMacros.h"
#include "macros/JoystickMacros.h"
#include "macros/SerialMacros.h"
#include "macros/MouseMacros.h"

CONFIG_BEGIN
#ifdef USB_CDC
SERIAL_CONFIG
#endif
#ifdef USB_JOY
JOYSTICK_CONFIG
#endif
#ifdef USB_MOUSE
MOUSE_CONFIG
#endif
CONFIG_END

uint16_t CALLBACK_USB_GetDescriptor(const uint16_t wValue,
                                    const uint8_t wIndex,
                                    const void** const DescriptorAddress)
                                    ATTR_WARN_UNUSED_RESULT ATTR_NON_NULL_PTR_ARG(3);

#endif


