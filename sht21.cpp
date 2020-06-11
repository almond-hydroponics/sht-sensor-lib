//
// Created by francis on 6/11/20.
//

#include <Wire.h>
#include "sht21.h"


SHT21::SHT21()
{
	//Set initial values for private vars
}

//Start I2C communication
void SHT21::begin(TwoWire &wirePort)
{
	_i2cPort = &wirePort; // Grab which port the user wants us to use
	_i2cPort->begin();
}

#define MAX_WAIT 100
#define DELAY_INTERVAL 10
#define MAX_COUNTER (MAX_WAIT/DELAY_INTERVAL)

uint16_t SHT21::readValue(byte cmd)
{
	// Request humidity reading
	_i2cPort->beginTransmission(SHT21_ADDRESS);
	_i2cPort->write(cmd);    // Prefer no hold.
	_i2cPort->endTransmission();

	// from datasheet, while measurement is taken, hang in for about 50ms
	bool validResult;
	byte counter;
	for (counter = 0, validResult = 0; counter < MAX_COUNTER && !validResult; counter++) {
		delay(DELAY_INTERVAL);

		//Comes back in three bytes, data(MSB) / data(LSB) / Checksum
		validResult = (3 == _i2cPort->requestFrom(SHT21_ADDRESS, 3));
	}

	if (!validResult) return (ERROR_I2C_TIMEOUT); //Error out

	byte msb, lsb, checksum;
	msb = _i2cPort->read();
	lsb = _i2cPort->read();
	checksum = _i2cPort->read();

	uint16_t rawValue = ((uint16_t)msb << 8) | (uint16_t)lsb;

	if (checkCRC(rawValue, checksum) != 0) return (ERROR_BAD_CRC); //Error out

	return rawValue & 0xFFFC; // Zero out the status bits
}

//Read the humidity
//Calc humidity and return it to the user
//Returns 998 if I2C timed out
//Returns 999 if CRC is wrong
float SHT21::readHumidity()
{
	uint16_t rawHumidity = readValue(TRIGGER_HUMD_MEASURE_NOHOLD);

	if (rawHumidity == ERROR_I2C_TIMEOUT || rawHumidity == ERROR_BAD_CRC)
		return (rawHumidity);

	//Given the raw humidity data, calculate the actual relative humidity
	float tempRH = rawHumidity * (125.0 / 65536.0); //2^16 = 65536
	float rh = tempRH - 6.0; //From page 14

	return (rh);
}

//Read the temperature
//Calc temperature and return it to the user
//Returns 998if I2C timed out
//Returns 999 if CRC is wrong
float SHT21::readTemperature()
{
	uint16_t rawTemperature = readValue(TRIGGER_TEMP_MEASURE_NOHOLD);

	if (rawTemperature == ERROR_I2C_TIMEOUT || rawTemperature == ERROR_BAD_CRC)
		return (rawTemperature);

	//Given the raw temperature data, calculate the actual temperature
	float tempTemperature = rawTemperature * (175.72 / 65536.0); //2^16 = 65536
	float realTemperature = tempTemperature - 46.85;

	return (realTemperature);
}

//Set sensor resolution
//Sets the sensor resolution to one of four levels
// 0/0 = 12bit RH, 14bit Temp
// 0/1 = 8bit RH, 12bit Temp
// 1/0 = 10bit RH, 13bit Temp
// 1/1 = 11bit RH, 11bit Temp
//Power on default is 0/0
void SHT21::setResolution(byte resolution)
{
	byte userRegister = readUserRegister(); //Go get the current register state
	userRegister &= B01111110; //Turn off the resolution bits
	resolution &= B10000001; //Turn off all other bits but resolution bits
	userRegister |= resolution; //Mask in the requested resolution bits

	//Request a write to user register
	writeUserRegister(userRegister);
}

// React the user register
byte SHT21::readUserRegister()
{
	byte userRegister;

	//Request the user register
	_i2cPort->beginTransmission(SHT21_ADDRESS);
	_i2cPort->write(READ_USER_REG); //Read the user register
	_i2cPort->endTransmission();

	//Read result
	_i2cPort->requestFrom(SHT21_ADDRESS, 1);

	userRegister = _i2cPort->read();

	return (userRegister);
}

void SHT21::writeUserRegister(byte val)
{
	_i2cPort->beginTransmission(SHT21_ADDRESS);
	_i2cPort->write(WRITE_USER_REG); //Write to the user register
	_i2cPort->write(val); //Write the new resolution bits
	_i2cPort->endTransmission();
}

//Give this function the 2 byte message (measurement) and the check_value byte from the SHT21
//If it returns 0, then the transmission was good
//If it returns something other than 0, then the communication was corrupted
//From: http://www.nongnu.org/avr-libc/user-manual/group__util__crc.html
//POLYNOMIAL = 0x0131 = x^8 + x^5 + x^4 + 1 : http://en.wikipedia.org/wiki/Computation_of_cyclic_redundancy_checks
#define SHIFTED_DIVISOR 0x988000 //This is the 0x0131 polynomial shifted to farthest left of three bytes

byte SHT21::checkCRC(uint16_t message_from_sensor, uint8_t check_value_from_sensor)
{
	//Test cases from datasheet:
	//message = 0xDC, checkvalue is 0x79
	//message = 0x683A, checkvalue is 0x7C
	//message = 0x4E85, checkvalue is 0x6B

	uint32_t remainder = (uint32_t)message_from_sensor
		<< 8; //Pad with 8 bits because we have to add in the check value
	remainder |= check_value_from_sensor; //Add on the check value

	uint32_t divsor = (uint32_t)SHIFTED_DIVISOR;

	for (int i = 0; i < 16; i++) //Operate on only 16 positions of max 24. The remaining 8 are our remainder and should be zero when we're done.
	{
		//Serial.print("remainder: ");
		//Serial.println(remainder, BIN);
		//Serial.print("divsor:    ");
		//Serial.println(divsor, BIN);
		//Serial.println();

		if (remainder & (uint32_t)1 << (23 - i)) //Check if there is a one in the left position
			remainder ^= divsor;

		divsor >>= 1; //Rotate the divsor max 16 times so that we have 8 bits left of a remainder
	}
	return (byte)remainder;
}
