#pragma once
#include <Adafruit_BME280.h>
#include "./Capteurs/CapteurProxy.h"

class CapteurTemperatureAirProxyBME280: public CapteurProxy
{
    private:
        Adafruit_BME280* m_BME280;
    public:
        CapteurTemperatureAirProxyBME280(int p_addresse);
        float MesurerCapteur();
};