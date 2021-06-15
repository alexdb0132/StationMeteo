#include <Adafruit_BME280.h>
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#include "Capteurs/CapteurTemperature.h"
#include "Capteurs/CapteurPression.h"
#include "Capteurs/CapteurHumidite.h"
#include "CapteursProxy/CapteurHumiditeProxyBME280.h"
#include "CapteursProxy/CapteurPressionProxyBME280.h"
#include "CapteursProxy/CapteurTemperatureAirProxyBME280.h"

#include <WiFi.h>
#include <MQTT.h>

CapteurHumidite* humidite;
CapteurPression* pression;
CapteurTemperature* temp;

const char ssid[] = "ssid";
const char pass[] = "pass";

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "public", "public")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("/hello");
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);

  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`.
}

void setup() {
  /*humidite = new CapteurHumidite(new CapteurHumiditeProxyBME280(0x76));
  pression = new CapteurPression(new CapteurPressionProxyBME280(0x76));
  temp = new CapteurTemperature(new CapteurTemperatureAirProxyBME280(0x76));*/
  
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported
  // by Arduino. You need to set the IP address directly.
  //
  // MQTT brokers usually use port 1883 for secure connections.
  client.begin("public.cloud.shiftr.io", 1883, net);
  client.onMessage(messageReceived);

  connect();
}

void loop() {
  client.loop();

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    client.publish("/hello", "world");
  }

  /*Serial.println("humidite :" + humidite->AfficherHumidite());
  Serial.println("pression :" + pression->AfficherPressionAir());
  Serial.println("temperature :" + temp->AfficherTemperatureAir());
  delay(500);*/
}
