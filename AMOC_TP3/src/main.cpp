#include <Arduino.h>
#include "Capteurs/CapteurTemperature.h"
#include "Capteurs/CapteurPression.h"
#include "Capteurs/CapteurHumidite.h"
#include "CapteursProxy/CapteurHumiditeProxyBME280.h"
#include "CapteursProxy/CapteurPressionProxyBME280.h"
#include "CapteursProxy/CapteurTemperatureAirProxyBME280.h"
#include "CapteursProxy/CapteurTemperatureEauProxyDS18B20.h"
CapteurHumidite* humidite;
CapteurPression* pression;
CapteurTemperature* temp;
void setup() {
  Serial.begin(9600);
  humidite = new CapteurHumidite(new CapteurHumiditeProxyBME280(0x76));
  pression = new CapteurPression(new CapteurPressionProxyBME280(0x76));
  temp = new CapteurTemperature(new CapteurTemperatureAirProxyBME280(0x76),new CapteurTemperatureEauProxyDS18B20(14));
}

void loop() {
  Serial.println("humidite :" + humidite->AfficherHumidite());
  Serial.println("pression :" + pression->AfficherPressionAir());
  Serial.println("temperature :" + temp->AfficherTemperatureAir());
  Serial.println("temperature Eau:" + temp->AfficherTemperatureEau());
  delay(1000);
}