#pragma once
#include <MQTT.h>
#include <WiFi.h>

class PubSub
{
    private:
        WiFiClient* m_net;
        MQTTClient m_client;
    public:
        PubSub(WiFiClient* p_net, const char* p_addresse);
        void publish(const char* p_topic, const char* p_message);
        void subscribe(const char* p_topic);
};  