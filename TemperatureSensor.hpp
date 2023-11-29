// TemperatureSensor.hpp
#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "mbed.h"

class TemperatureSensor {
public:
    TemperatureSensor(PinName sda, PinName scl, int address);
    float readTemperature();

private:
    I2C i2c;
    int addr;
};

#endif // TEMPERATURE_SENSOR_H
