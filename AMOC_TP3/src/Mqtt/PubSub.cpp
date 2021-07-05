/*#include "./Mqtt/PubSub.h"

PubSub::PubSub(IPAddress p_addresse, WiFiClient* p_net)
{
    this->m_client = new PubSubClient(*p_net);

    this->m_client.setServer(p_addresse,1883);

    while (!this->m_client.connect("bateau", "mqtt-mosquitto", "mqtt123")) {
    Serial.print(".");
    delay(1000);
  }
}
void PubSub::publish(const char* p_topic,const char* p_message)
{
    Serial.println("publish");
    this->m_client.publish(p_topic, p_message);
}
void PubSub::subscribe(const char* p_topic)
{
    this->m_client.subscribe(p_topic);
}
*/