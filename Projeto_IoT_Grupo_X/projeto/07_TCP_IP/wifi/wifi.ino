#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Cyber-Projeto";
const char* password = "Senai@122";

// COLOQUE SEU IPV4 CERTO
String servidor = "http://:5000/temperatura?sensor=ESP8266&temperatura=30";

WiFiClient client;

void setup() {

  Serial.begin(115200);

  WiFi.begin(ssid, password);

  Serial.println("Conectando WiFi...");

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado!");
}

void loop() {

  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    http.begin(client, servidor);

    int httpCode = http.GET();

    Serial.print("Código HTTP: ");
    Serial.println(httpCode);

    String resposta = http.getString();

    Serial.println(resposta);

    http.end();
  }

  delay(5000);
}
