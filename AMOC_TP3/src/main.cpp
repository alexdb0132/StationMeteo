#include "CapteursProxy/CapteurHumiditeProxyBME280.h"
#include "CapteursProxy/CapteurPressionProxyBME280.h"
#include "CapteursProxy/CapteurTemperatureAirProxyBME280.h"
#include "CapteursProxy/CapteurTemperatureEauProxyDS18B20.h"
#include "Capteurs/CapteurHumidite.h"
#include "Capteurs/CapteurPression.h"
#include "Capteurs/CapteurTemperature.h"
#include <WiFi.h>
#include "Mqtt/PubSub.h"
#include "./WifiMan/WifiAccessPoint.h"



/* test wifiManager*/
WifiAccessPoint* wifiman;                        
void setup() {
  wifiman = new WifiAccessPoint();
}
void loop() {
  wifiman->Tick();
}
/* test Mqtt + temp

CapteurTemperature* temp;
const char ssid[] = "iPhone de kevin";
const char pass[] = "12345678";

WiFiClient* net;
PubSub* mqtt;

void setup() {
  temp = new CapteurTemperature(new CapteurTemperatureAirProxyBME280(0x76),new CapteurTemperatureEauProxyDS18B20(14));
  net = new WiFiClient();
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
    mqtt = new PubSub(net,"172.20.10.5");
}

void loop(){
  mqtt->publish("/hello",temp->AfficherTemperatureAir().c_str());
  Serial.println(WiFi.localIP());
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
