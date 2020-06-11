//
// Created by francis on 6/11/20.
//

#ifndef SHT21_H
#define SHT21_H

#include <Arduino.h>
#include <Wire.h>

#define SHT21_ADDRESS 0X40    // i2c Address for the sensor

#define TRIGGER_TEMP_MEASURE_NOHOLD 0XF3
#define TRIGGER_HUMD_MEASURE_NOHOLD 0XF5

class SHT21
{
public:
	SHT21();
	void begin();
	float getTemperature();
	float getHumidity();

private:
	uint16_t readSHT21(uint8_t command);
};


#endif //SHT21_H
