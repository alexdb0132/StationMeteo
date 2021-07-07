#include "Program.h"
#include <WiFi.h>
#include "Mqtt/PubSub.h"
#include <PubSubClient.h>


//Code officiel

Program* program;
void setup()
{
  program = new Program();
}

void loop()
{
  program->Tick();
}


/* test wifiManager
CapteurTemperature* temp;
PubSubClient* mqtt;
WifiConfig* wifimanager;    

void setup() {
  temp = new CapteurTemperature(new CapteurTemperatureAirProxyBME280(0x76),new CapteurTemperatureEauProxyDS18B20(14));
  Serial.begin(115200);
  wifimanager = new WifiConfig();
  //mqtt = new PubSubClient(wifimanager);
  Serial.println("mqttcreer");
}
void loop() {
  //mqtt->publish("bateau/aire",temp->AfficherTemperatureAir().c_str());
  //Serial.println(WiFi.localIP());
  delay(5000);
}
*/
 //test Mqtt + temp
/*
CapteurTemperature* temp;
const char ssid[] = "Valerie";
const char pass[] = "gintonic";

WiFiClient* net;
PubSubClient* mqtt;
CapteurHumidite* humidite;
CapteurPression* pression;

void setup() {
  temp = new CapteurTemperature(new CapteurTemperatureAirProxyBME280(0x76),new CapteurTemperatureEauProxyDS18B20(14));
  humidite = new CapteurHumidite(new CapteurHumiditeProxyBME280(0x76));
  pression = new CapteurPression(new CapteurPressionProxyBME280(0x76));
  net = new WiFiClient();
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  mqtt = new PubSubClient(*net);
  mqtt->setServer(IPAddress(192,168,43,20),1883);
  mqtt->connect("core-mosquitto", "mqtt-mosquitto", "mqtt123");
}

void loop(){
  mqtt->publish("bateau/aire",temp->AfficherTemperatureAir().c_str());
  mqtt->publish("bateau/eau",temp->AfficherTemperatureEau().c_str());
  mqtt->publish("bateau/humidite",humidite->AfficherHumidite().c_str());
  mqtt->publish("bateau/pression",pression->AfficherPressionAir().c_str());
  delay(5000);
}
*/

/*test capteur
CapteurHumidite* humidite;
CapteurPression* pression;
CapteurTemperature* temp;

void setup() {
  Serial.begin(115200);
  humidite = new CapteurHumidite(new CapteurHumiditeProxyBME280(0x76));
  pression = new CapteurPression(new CapteurPressionProxyBME280(0x76));
  temp = new CapteurTemperature(new CapteurTemperatureAirProxyBME280(0x76),new CapteurTemperatureEauProxyDS18B20(14));
}

void loop() {
  //Serial.println("humidite :" + humidite->AfficherHumidite());
  //Serial.println("pression :" + pression->AfficherPressionAir());
  //Serial.println("temperature :" + temp->AfficherTemperatureAir());
  Serial.println("temperature Eau:" + temp->AfficherTemperatureEau());
  delay(1000);
}
*/
