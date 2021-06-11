#include "./CapteursProxy/CapteurPressionProxyBME280.h"

CapteurPressionProxyBME280::CapteurPressionProxyBME280(int p_address)
{
    this->m_BME280 = new Adafruit_BME280();
    this->m_BME280->begin(p_address);
}

float CapteurPressionProxyBME280::MesurerCapteur()
{
    return this->m_BME280->readPressure();
}