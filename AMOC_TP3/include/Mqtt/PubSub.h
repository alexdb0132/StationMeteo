/*#pragma once
#include <WiFi.h>
#include <PubSubClient.h>

class PubSub
{
    private:
        WiFiClient* m_net;
        PubSubClient m_client;
    public:
        PubSub(IPAddress p_adresse, WiFiClient* p_net);
        void publish(const char* p_topic, const char* p_message);
        void subscribe(const char* p_topic);
};  
*/