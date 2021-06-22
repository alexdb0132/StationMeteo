#include "./Mqtt/PubSub.h"

PubSub::PubSub(WiFiClient* p_net,const char* p_addresse):m_net(p_net)
{
    this->m_client.begin(p_addresse, 1883, *p_net);
    while (!this->m_client.connect("arduino", "public", "public")) {
    Serial.print(".");
    delay(1000);
  }
}
void PubSub::publish(const char* p_topic,const char* p_message)
{
    this->m_client.publish(p_topic, p_message);
}
void PubSub::subscribe(const char* p_topic)
{
    this->m_client.subscribe(p_topic);
}
