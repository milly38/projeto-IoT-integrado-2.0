#include <DHT.h>

#define DHTPIN D4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200);
  dht.begin();
}

void loop() {

  float temp = dht.readTemperature();
  float umid = dht.readHumidity();

  Serial.println(temp);
  Serial.println(umid);

  delay(2000);
}