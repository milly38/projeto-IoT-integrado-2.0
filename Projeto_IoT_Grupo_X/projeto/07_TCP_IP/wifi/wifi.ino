o professor acabou de mandar esse - #include <ESP8266WiFi.h>

// Nome da rede Wi-Fi
const char* ssid = "CONECTADO";

// Senha da rede Wi-Fi
const char* password = "C@necTa0!";

void setup() {
  
  // Inicializa comunicação serial
  Serial.begin(115200);
  
  Serial.println();
  Serial.println("Conectando ao Wi-Fi...");

  // Inicia conexão Wi-Fi
  WiFi.begin(ssid, password);

  // Aguarda conexão
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Exibe conexão realizada
  Serial.println();
  Serial.println("Wi-Fi conectado com sucesso!");

  // Exibe IP obtido
  Serial.print("IP do ESP8266: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  
}
