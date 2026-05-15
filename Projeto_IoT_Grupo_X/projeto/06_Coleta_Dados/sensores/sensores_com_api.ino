// ================= BIBLIOTECAS =================
#include <DHT.h>

// ================= PINOS =================
#define DHTPIN D4
#define DHTTYPE DHT11

#define LED1 D1
#define LED2 D0

#define BOTAO_SW1 D2
#define SENSOR_IR D5
#define BUZZER D7

#define LM35 A0

// ================= SENSOR =================
DHT dht(DHTPIN, DHTTYPE);

// ================= VARIÁVEIS =================
float temperatura = 0;
float umidade = 0;
int sensorAnalogico = 0;

String estado = "NORMAL";

bool botao = false;
bool ir = false;

// ================= SETUP =================
void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  pinMode(BOTAO_SW1, INPUT_PULLUP);
  pinMode(SENSOR_IR, INPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(BUZZER, LOW);

  Serial.println("Sistema IoT iniciado");
}

// ================= LOOP =================
void loop() {

  lerSensores();
  lerEntradas();
  regrasSistema();
  atuadores();
  enviarSerialJSON();

  delay(2000); // leve e estável
}

// ================= LEITURA =================
void lerSensores() {

  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();

  sensorAnalogico = analogRead(LM35);

  if (isnan(temperatura) || isnan(umidade)) {
    estado = "ERRO_SENSOR";
  }
}

// ================= ENTRADAS =================
void lerEntradas() {

  botao = (digitalRead(BOTAO_SW1) == LOW); // botão pressionado = LOW

  ir = (digitalRead(SENSOR_IR) == LOW); // muitos módulos IR são LOW ativo
}

// ================= REGRAS =================
void regrasSistema() {

  estado = "NORMAL";

  if (temperatura > 30) {
    estado = "ALERTA";
  }

  if (temperatura > 35) {
    estado = "CRITICO";
  }

  if (botao) {
    estado = "MANUAL";
  }

  if (ir) {
    estado = "EVENTO";
  }
}

// ================= ATUADORES =================
void atuadores() {

  if (estado == "NORMAL") {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(BUZZER, LOW);
  }

  else if (estado == "ALERTA") {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    tone(BUZZER, 1000);
  }

  else if (estado == "CRITICO") {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    tone(BUZZER, 2000);
  }

  else if (estado == "MANUAL") {
    digitalWrite(LED1, !digitalRead(LED1));
    digitalWrite(BUZZER, LOW);
  }

  else if (estado == "EVENTO") {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    noTone(BUZZER);
  }

  else if (estado == "ERRO_SENSOR") {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    tone(BUZZER, 500);
  }
}

// ================= JSON (PARA FLASK) =================
String montarJSON() {

  String json = "{";
  json += "\"temperatura\":" + String(temperatura) + ",";
  json += "\"umidade\":" + String(umidade) + ",";
  json += "\"analogico\":" + String(sensorAnalogico) + ",";
  json += "\"estado\":\"" + estado + "\"";
  json += "}";

  return json;
}

// ================= SERIAL =================
void enviarSerialJSON() {

  Serial.println(montarJSON());
}
