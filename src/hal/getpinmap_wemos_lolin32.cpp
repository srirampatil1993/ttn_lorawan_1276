/*

Module:  getconfig_ttgo_lora32_v1.cpp

Function:
        Arduino-LMIC C++ HAL pinmap for TTGO ESP32 OLED V1

Copyright & License:
        See accompanying LICENSE file.

Author:
        German Martin, gmag11@gmail.com   June 2019

*/

#include <arduino_lmic_hal_boards.h>
#include <Arduino.h>

#include "../lmic/oslmic.h"

#define LORA_DIO0 32
#define LORA_DIO1 33
//#define LORA_DIO2 UNUSED_PIN

namespace Arduino_LMIC {

class HalConfiguration_wemos_lolin32 : public HalConfiguration_t
	{
public:
	enum DIGITAL_PINS : uint8_t
		{
		PIN_SX1276_NSS = 15,
		PIN_SX1276_NRESET = 27,
		PIN_SX1276_DIO0 = LORA_DIO0,
		PIN_SX1276_DIO1 = LORA_DIO1,
		PIN_SX1276_DIO2 = HalPinmap_t::UNUSED_PIN,//LORA_DIO2,
		PIN_SX1276_ANT_SWITCH_RX = HalPinmap_t::UNUSED_PIN,
		PIN_SX1276_ANT_SWITCH_TX_BOOST = HalPinmap_t::UNUSED_PIN,
		PIN_SX1276_ANT_SWITCH_TX_RFO = HalPinmap_t::UNUSED_PIN,
		PIN_VDD_BOOST_ENABLE = HalPinmap_t::UNUSED_PIN,
		};

	virtual void begin(void) override
		{
		digitalWrite(PIN_SX1276_NSS, 1);
		pinMode(PIN_SX1276_NSS, OUTPUT);
		}

	// virtual void end(void) override

	// virtual ostime_t setModuleActive(bool state) override

	};

static HalConfiguration_wemos_lolin32 myConfig;

static const HalPinmap_t myPinmap =
        {
        .nss = HalConfiguration_wemos_lolin32::PIN_SX1276_NSS,      // chip select is D7
        .rxtx = HalConfiguration_wemos_lolin32::PIN_SX1276_ANT_SWITCH_RX, // RXTX is D29
        .rst = HalConfiguration_wemos_lolin32::PIN_SX1276_NRESET,   // NRESET is D8

        .dio = {HalConfiguration_wemos_lolin32::PIN_SX1276_DIO0,    // DIO0 (IRQ) is D25
				HalConfiguration_wemos_lolin32::PIN_SX1276_DIO1,    // DIO1 is D26
				HalConfiguration_wemos_lolin32::PIN_SX1276_DIO2,    // DIO2 is D27
               },
        .rxtx_rx_active = 0,
        .rssi_cal = 10,
        .spi_freq = 1000000,     /* 1MHz */
        .pConfig = &myConfig
        };

const HalPinmap_t * GetPinmap_wemos_lolin32(void)
	{
	return &myPinmap;
	}

}; // namespace Arduino_LMIC

