#include "./Capteurs/CapteurPression.h"
#include<Adafruit_BME280.h>

CapteurPression::CapteurPression(CapteurProxy* p_proxy):m_proxy(p_proxy)
{

}

String CapteurPression::AfficherPressionAir()
{
        float pressionKPA = this->m_proxy->MesurerCapteur() / 1000;
        return String(pressionKPA);
}
