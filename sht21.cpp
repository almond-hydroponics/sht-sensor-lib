//
// Created by francis on 6/11/20.
//

#include <Wire.h>
#include "sht21.h"


SHT21::SHT21()
= default;

void SHT21::begin()
{
	Wire.begin();
}

float SHT21::getTemperature()
{
	return (-46.85 + 175.72 / 65536.0 * (float)(readSHT21(TRIGGER_TEMP_MEASURE_NOHOLD)));
}

float SHT21::getHumidity()
{
	return (-6.0 + 125.0 / 65536.0 * (float)(readSHT21(TRIGGER_HUMD_MEASURE_NOHOLD)));
}

uint16_t SHT21::readSHT21(uint8_t command)
{
	uint16_t result;

	Wire.beginTransmission(SHT21_ADDRESS);
	Wire.write(command);
	Wire.endTransmission();
	delay(1000);
	Wire.requestFrom(SHT21_ADDRESS, 3);

	while (Wire.available() < 3) {
		delay(1);
	}

	result = ((Wire.read()) << 8);
	result += Wire.read();
	result &= ~0x0003    // clear two low bits (status bits)
	return result;
}
