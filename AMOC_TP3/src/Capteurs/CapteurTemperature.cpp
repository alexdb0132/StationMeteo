#include "./Capteurs/CapteurTemperature.h"
#include<Adafruit_BME280.h>

CapteurTemperature::CapteurTemperature(CapteurProxy* p_proxyAir, CapteurProxy* p_proxyEau):m_proxyAir(p_proxyAir),m_proxyEau(p_proxyEau)
{

}

String CapteurTemperature::AfficherTemperatureAir()
{
    return String(this->m_proxyAir->MesurerCapteur());
}
String CapteurTemperature::AfficherTemperatureEau()
{
    return String(this->m_proxyEau->MesurerCapteur());
}
float CapteurTemperature::GetTemperatureAir()
{
    return this->m_proxyAir->MesurerCapteur();
}
float CapteurTemperature::GetTemperatureEau()
{
    return this->m_proxyEau->MesurerCapteur();
}

