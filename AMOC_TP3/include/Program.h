#pragma once
#include "CapteursProxy/CapteurHumiditeProxyBME280.h"
#include "CapteursProxy/CapteurPressionProxyBME280.h"
#include "CapteursProxy/CapteurTemperatureAirProxyBME280.h"
#include "CapteursProxy/CapteurTemperatureEauProxyDS18B20.h"
#include "Capteurs/CapteurHumidite.h"
#include "Capteurs/CapteurPression.h"
#include "Capteurs/CapteurTemperature.h"
#include "./WifiConfig/WifiConfig.h"
#include <WiFi.h>
#include <PubSubClient.h>

class Program
{
    private:
        CapteurHumidite* m_capteurHumidite;
        CapteurTemperature* m_capteurTemperature;
        CapteurPression* m_capteurPression;
        PubSubClient* m_mqtt;
        WiFiClient* m_net;
    public:
        Program();
        void Tick();
};