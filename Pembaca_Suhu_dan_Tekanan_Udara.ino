#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();
}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Gagal membaca sensor!!!"));
    return;
  }
  
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Kelembaban: ");
  Serial.print(h);
  Serial.println("%");
  
  Serial.print("Temperatur (C): ");
  Serial.print(t);
  Serial.println(" C");
    
  Serial.print("Temperatur (F): ");
  Serial.print(f);
  Serial.println(" F");
  Serial.println(" ");
}
