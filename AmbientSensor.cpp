#include "AmbientSensor.h"

#include "DHT.h"
#include <string>
#include <iostream>
#include <sstream>

AmbientSensor::AmbientSensor(DHT* sensor) : m_sensor(sensor)
{}

std::string AmbientSensor::getTemperatureString() const {
    return static_cast<ostringstream*>( &(ostringstream() << (m_sensor->ReadTemperature(CELCIUS))) )->str();
}

std::string AmbientSensor::getHumidityString() const {
    return static_cast<ostringstream*>( &(ostringstream() << (m_sensor->ReadHumidity())) )->str();
}