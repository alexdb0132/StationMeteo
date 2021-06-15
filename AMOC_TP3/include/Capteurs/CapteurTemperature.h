#pragma once
#include "CapteurProxy.h"

class CapteurTemperature
{
    private:
        CapteurProxy* m_proxyAir;
        CapteurProxy* m_proxyEau;
    public:
        CapteurTemperature(CapteurProxy* p_proxyAir,CapteurProxy* p_proxyEau);
        String AfficherTemperatureAir();
        String AfficherTemperatureEau();
        float GetTemperatureAir();
        float GetTemperatureEau();
};