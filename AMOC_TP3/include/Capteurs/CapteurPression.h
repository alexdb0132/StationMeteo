#pragma once
#include "CapteurProxy.h"

class CapteurPression
{
    private:
        CapteurProxy* m_proxy;
    public:
        CapteurPression(CapteurProxy* p_proxy);
        String AfficherPressionAir();
};