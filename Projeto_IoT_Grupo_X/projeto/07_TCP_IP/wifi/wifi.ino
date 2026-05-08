#include <ESP8266WiFi.h>

const char* ssid = "programador";
const char* password = "2306eg";

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {

    delay(1000);
    Serial.println("Conectando...");
  }

  Serial.println("WiFi conectado!");
}

void loop() {

}