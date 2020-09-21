#include <string>

class DHT;

class AmbientSensor {
public:
    AmbientSensor(DHT* sensor);
    
    std::string getTemperatureString() const;
    
    std::string getHumidityString() const;
private:
    DHT* m_sensor;
};