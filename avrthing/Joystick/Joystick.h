#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

	/* Includes: */
		#include <avr/io.h>
		#include <avr/wdt.h>
		#include <avr/power.h>
		#include <avr/interrupt.h>
		#include <string.h>

		#include "Descriptors.h"

		#include <LUFA/Version.h>
		#include <LUFA/Drivers/USB/USB.h>

	/* Type Defines: */
		/** Type define for the joystick HID report structure, for creating and sending HID reports to the host PC.
		 *  This mirrors the layout described to the host in the HID report descriptor, in Descriptors.c.
		 */
		typedef struct
		{
			int8_t  X; /**< Current absolute joystick X position, as a signed 8-bit integer */
			int8_t  Y; /**< Current absolute joystick Y position, as a signed 8-bit integer */
			uint8_t Button; /**< Bit mask of the currently pressed joystick buttons */
		} USB_JoystickReport_Data_t;

	/* Function Prototypes: */
		void SetupHardware(void);

		void EVENT_USB_Device_Connect(void);
		void EVENT_USB_Device_Disconnect(void);
		void EVENT_USB_Device_ConfigurationChanged(void);
		void EVENT_USB_Device_ControlRequest(void);
		void EVENT_USB_Device_StartOfFrame(void);

		bool CALLBACK_HID_Device_CreateHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
		                                         uint8_t* const ReportID,
		                                         const uint8_t ReportType,
		                                         void* ReportData,
		                                         uint16_t* const ReportSize);
		void CALLBACK_HID_Device_ProcessHIDReport(USB_ClassInfo_HID_Device_t* const HIDInterfaceInfo,
		                                          const uint8_t ReportID,
		                                          const uint8_t ReportType,
		                                          const void* ReportData,
		                                          const uint16_t ReportSize);

#endif

