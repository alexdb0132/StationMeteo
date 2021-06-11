#pragma once
#include "CapteurProxy.h"

class CapteurHumidite
{
    private:
        CapteurProxy* m_proxy;
    public:
        CapteurHumidite(CapteurProxy* p_proxy);
        String AfficherHumidite();
};