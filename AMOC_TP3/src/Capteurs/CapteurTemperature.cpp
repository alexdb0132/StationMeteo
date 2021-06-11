#include "./Capteurs/CapteurTemperature.h"
#include<Adafruit_BME280.h>

CapteurTemperature::CapteurTemperature(CapteurProxy* p_proxy):m_proxy(p_proxy)
{

}

String CapteurTemperature::AfficherTemperatureAir()
{
    return String(this->m_proxy->MesurerCapteur()) + " °C";
}
