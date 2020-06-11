## sht-sensor-lib
Library and example sketch for temperature and humidity sensor SHT21 (Sensirion) works with Arduino, ESP8266

This library works with temperature and humidity sensor SHT21 (Sensirion) both tested with Arduino and ESP8266. The demo sketch puts out the current temperature (Celsius) and humidity (%RH) values via the serial port.

## SHT21/HTU21D for Temperature, Humidity

The HTU21D aka. SHT21 is a I2C digital Temperature / humidity sensor with a typical accuracy of ±2% with an operating range that's optimized from 5% to 95% RH, temperature output has an accuracy of ±1°C from -30~90°C. 

THe sensor is implemented as a reusable class which will use the sensor and expose the environmental factors (namely temperature and humidity). 

#### Usage
    SHT21 sht;
    bool b = sht.begin(4, 5);
    if (b)
    {
      Serial.printf("Temp:%f, Humid:%f, dew:%f, HI%f \n", htu.getTemperature(), htu.getHumidity(), htu.getDewPoint(), htu.getHeatIndex());
    }

`begin` can pass the ESP8266 IO pin numbers to be used as SDA and SCL lines for I2C communication. 

The measurements are retunrned in metric units, i.e. `Temperature` in `Celcius` and `Relative Humidity` in  `Percentage`.
