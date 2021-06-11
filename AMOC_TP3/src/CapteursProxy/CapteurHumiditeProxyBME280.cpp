#include "./CapteursProxy/CapteurHumiditeProxyBME280.h"

CapteurHumiditeProxyBME280::CapteurHumiditeProxyBME280(int p_address)
{
    this->m_BME280 = new Adafruit_BME280();
    this->m_BME280->begin(p_address);
}

float CapteurHumiditeProxyBME280::MesurerCapteur()
{
    return this->m_BME280->readHumidity();
}