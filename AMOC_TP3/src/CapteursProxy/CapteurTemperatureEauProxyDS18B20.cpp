#include "./CapteursProxy/CapteurTemperatureEauProxyDS18B20.h"

CapteurTemperatureEauProxyDS18B20::CapteurTemperatureEauProxyDS18B20(int p_pin)
{
    this->m_ds18b20 = new OneWire(p_pin);
    this->m_sensor = new DallasTemperature(this->m_ds18b20);
}

float CapteurTemperatureEauProxyDS18B20::MesurerCapteur()
{
    this->m_sensor->requestTemperatures();
    return this->m_sensor->getTempFByIndex(0);
}
