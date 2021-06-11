#pragma once
#include <Adafruit_BME280.h>
#include "./Capteurs/CapteurProxy.h"

class CapteurHumiditeProxyBME280: public CapteurProxy
{
    private:
        Adafruit_BME280* m_BME280;
    public:
        CapteurHumiditeProxyBME280(int p_addresse);
        float MesurerCapteur();
};