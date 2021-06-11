#pragma once
#include "CapteurProxy.h"

class CapteurTemperature
{
    private:
        CapteurProxy* m_proxy;
    public:
        CapteurTemperature(CapteurProxy* p_proxy);
        String AfficherTemperatureAir();
        float GetTemperatureAir();
};