// TemperatureSensor.cpp
#include "TemperatureSensor.hpp"

TemperatureSensor::TemperatureSensor(PinName sda, PinName scl, int address) : i2c(sda, scl), addr(address << 1) {
    char CONFIG[1] = {0x01};
    i2c.write(addr, CONFIG, 1);
}

float TemperatureSensor::readTemperature() {
    char data[2];
    char TVAL[1] = {0x00}; 
    i2c.write(addr, TVAL, 1);
    i2c.read(addr, data, 2);
    return static_cast<float>((data[0] << 8 | data[1])) / 128.0;
}
