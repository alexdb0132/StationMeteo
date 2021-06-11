#include "./CapteursProxy/CapteurTemperatureAirProxyBME280.h"

CapteurTemperatureAirProxyBME280::CapteurTemperatureAirProxyBME280(int p_address)
{
    this->m_BME280 = new Adafruit_BME280();
    this->m_BME280->begin(p_address);
}

float CapteurTemperatureAirProxyBME280::MesurerCapteur()
{
    return this->m_BME280->readTemperature();
}