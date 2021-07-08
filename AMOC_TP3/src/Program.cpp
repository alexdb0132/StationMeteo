#include "./Program.h"
#include "WiFiManager.h"
#include "WebServer.h"

WifiConfig* wifiman; 

Program::Program()
{
    Serial.begin(115200);
    wifiman = new WifiConfig();
    this->m_capteurHumidite = new CapteurHumidite(new CapteurHumiditeProxyBME280(0x76));
    this->m_capteurPression = new CapteurPression(new CapteurPressionProxyBME280(0x76));
    this->m_capteurTemperature = new CapteurTemperature(new CapteurTemperatureAirProxyBME280(0x76), new CapteurTemperatureEauProxyDS18B20(14));
    while(WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(1000);
    }
    this->m_net = new WiFiClient();
    this->m_mqtt = new PubSubClient(*m_net);

    Serial.println(*wifiman->GetAddresseMQTT());
    this->m_mqtt->setServer(*wifiman->GetAddresseMQTT(),1883);
    this->m_mqtt->connect("core-mosquitto", "mqtt-mosquitto","mqtt123");
}

void Program::Tick()
{
    m_mqtt->publish("bateau/aire",m_capteurTemperature->AfficherTemperatureAir().c_str());
    m_mqtt->publish("bateau/eau",m_capteurTemperature->AfficherTemperatureEau().c_str());
    m_mqtt->publish("bateau/humidite",m_capteurHumidite->AfficherHumidite().c_str());
    m_mqtt->publish("bateau/pression",m_capteurPression->AfficherPressionAir().c_str());
    delay(500);
}

