#pragma once
#include <OneWire.h>
#include <DallasTemperature.h>
#include "./Capteurs/CapteurProxy.h"

class CapteurTemperatureEauProxyDS18B20: public CapteurProxy
{
    private:
        OneWire* m_ds18b20;
        DallasTemperature* m_sensor;
    public:
        CapteurTemperatureEauProxyDS18B20(int p_pin);
        float MesurerCapteur();
};