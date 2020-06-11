//
// Created by francis on 6/11/20.
//

#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <Wire.h>

#define SHT21_ADDRESS 0X40    // Unshifted 7-bit i2c Address for the sensor

#define ERROR_I2C_TIMEOUT    998
#define ERROR_BAD_CRC        999

#define TRIGGER_TEMP_MEASURE_HOLD  0xE3
#define TRIGGER_HUMD_MEASURE_HOLD  0xE5
#define TRIGGER_TEMP_MEASURE_NOHOLD  0xF3
#define TRIGGER_HUMD_MEASURE_NOHOLD  0xF5
#define WRITE_USER_REG  0xE6
#define READ_USER_REG  0xE7
#define SOFT_RESET  0xFE

#define USER_REGISTER_RESOLUTION_MASK 0x81
#define USER_REGISTER_RESOLUTION_RH12_TEMP14 0x00
#define USER_REGISTER_RESOLUTION_RH8_TEMP12 0x01
#define USER_REGISTER_RESOLUTION_RH10_TEMP13 0x80
#define USER_REGISTER_RESOLUTION_RH11_TEMP11 0x81

#define USER_REGISTER_END_OF_BATTERY 0x40
#define USER_REGISTER_HEATER_ENABLED 0x04
#define USER_REGISTER_DISABLE_OTP_RELOAD 0x02

class SHT21
{

public:
	SHT21();

	// Public Functions
	void begin(TwoWire &wirePort = Wire); //If user doesn't specify then Wire will be used
	float readTemperature();
	float readHumidity();
	void setResolution(byte resolutionBits);
	byte readUserRegister();
	void writeUserRegister(byte val);

	// Public Variables

private:
	// Private Functions
	TwoWire *_i2cPort; //The generic connection to user's chosen I2C hardware
	uint16_t readValue(byte cmd);
	static byte
	checkCRC(uint16_t message_from_sensor, uint8_t check_value_from_sensor);

	// Private Variables
};
