#include "./Capteurs/CapteurHumidite.h"
#include<Adafruit_BME280.h>

CapteurHumidite::CapteurHumidite(CapteurProxy* p_proxy):m_proxy(p_proxy)
{

}

String CapteurHumidite::AfficherHumidite()
{
    return String(this->m_proxy->MesurerCapteur()) + " %";
}
