// ===== BIBLIOTECAS =====
#include <DHT.h>

// ===== DEFINIÇÕES DE PINOS (baseado na Etapa 1) =====
#define DHTPIN D4           // Sensor DHT11
#define DHTTYPE DHT11

#define BOTAO_SW1 D1        // Botão manual
#define LED_RGB_R D5        // LED RGB - Vermelho
#define LED_RGB_G D6        // LED RGB - Verde
#define BUZZER D8           // Buzzer (aviso)
#define SENSOR_ROTACAO A0   // Sensor de rotação (análogo)
#define SENSOR_IR D2        // IR Receiver

// ===== INICIALIZAÇÕES =====
DHT dht(DHTPIN, DHTTYPE);

// ===== VARIÁVEIS DO SISTEMA =====
float temperatura = 0;
float umidade = 0;
int rotacao = 0;
String estado = "NORMAL";
bool botao_pressionado = false;
bool ir_detectado = false;

// ===== SETUP =====
void setup() {
  Serial.begin(115200);
  delay(1000);
  
  // Inicializa DHT11
  dht.begin();
  Serial.println("[SETUP] DHT11 inicializado");
  
  // Configura pinos como entrada
  pinMode(BOTAO_SW1, INPUT);
  pinMode(SENSOR_IR, INPUT);
  pinMode(SENSOR_ROTACAO, INPUT);
  
  // Configura pinos como saída
  pinMode(LED_RGB_R, OUTPUT);
  pinMode(LED_RGB_G, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  
  // Desliga tudo no início
  digitalWrite(LED_RGB_R, LOW);
  digitalWrite(LED_RGB_G, LOW);
  digitalWrite(BUZZER, LOW);
  
  Serial.println("[SETUP] Sensores e atuadores configurados");
}

// ===== LOOP PRINCIPAL =====
void loop() {
  // 1️⃣ LÊ OS SENSORES
  lerSensores();
  
  // 2️⃣ VERIFICA AS ENTRADAS (botões, IR)
  verificarEntradas();
  
  // 3️⃣ APLICA AS REGRAS DO SISTEMA
  aplicarRegras();
  
  // 4️⃣ ACIONA OS ATUADORES (LED, buzzer)
  acionarAtuadores();
  
  // 5️⃣ EXIBE NO SERIAL
  exibirDados();
  
  // Aguarda 2 segundos antes de nova leitura
  delay(10000);
}

// ===== FUNÇÕES DE LEITURA =====

void lerSensores() {
  // Lê DHT11
  temperatura = dht.readTemperature();
  umidade = dht.readHumidity();
  
  // Verifica se leitura foi bem-sucedida
  if (isnan(temperatura) || isnan(umidade)) {
    Serial.println("[ERRO] Falha ao ler DHT11");
    estado = "ERRO";
    return;
  }
  
  // Lê rotação (0-1023)
  rotacao = analogRead(SENSOR_ROTACAO);
  // Converte para 0-100%
  rotacao = map(rotacao, 0, 1023, 0, 100);
}

void verificarEntradas() {
  // Verifica botão SW1
  if (digitalRead(BOTAO_SW1) == HIGH) {
    botao_pressionado = true;
  } else {
    botao_pressionado = false;
  }
  
  // Verifica IR
  if (digitalRead(SENSOR_IR) == HIGH) {
    ir_detectado = true;
  } else {
    ir_detectado = false;
  }
}

void aplicarRegras() {
  // Começa sempre em NORMAL
  estado = "NORMAL";
  
  // ===== REGRA 1: Temperatura Alta =====
  if (temperatura > 30) {
    estado = "ALERTA";
    Serial.println("[ALERTA] Temperatura acima de 30°C!");
  }
  
  // ===== REGRA 2: Temperatura Crítica =====
  if (temperatura > 35) {
    estado = "CRÍTICO";
    Serial.println("[CRÍTICO] Temperatura acima de 35°C!");
  }
  
  // ===== REGRA 3: Botão Pressionado =====
  if (botao_pressionado) {
    estado = "MANUAL";
    Serial.println("[MANUAL] Botão SW1 foi pressionado");
  }
  
  // ===== REGRA 4: IR Detectado =====
  if (ir_detectado) {
    estado = "EVENTO";
    Serial.println("[EVENTO] IR detectado!");
  }
  
  // ===== REGRA 5: Rotação Alta =====
  if (rotacao > 80) {
    if (estado != "CRÍTICO") { // Não sobrescreve CRÍTICO
      estado = "CRÍTICO";
    }
    Serial.println("[CRÍTICO] Rotação acima de 80%!");
  }
}

void acionarAtuadores() {
  // ===== LED RGB =====
  if (estado == "NORMAL") {
    digitalWrite(LED_RGB_G, HIGH);  // Verde
    digitalWrite(LED_RGB_R, LOW);
    digitalWrite(BUZZER, LOW);
  } 
  else if (estado == "ALERTA") {
    digitalWrite(LED_RGB_R, HIGH);  // Vermelho
    digitalWrite(LED_RGB_G, LOW);
    tone(BUZZER, 1000, 500);        // Som de alerta
  } 
  else if (estado == "CRÍTICO") {
    // Pisca vermelho + buzzer contínuo
    digitalWrite(LED_RGB_R, !digitalRead(LED_RGB_R)); // Alterna
    digitalWrite(LED_RGB_G, LOW);
    digitalWrite(BUZZER, HIGH);     // Som contínuo
  } 
  else if (estado == "MANUAL") {
    digitalWrite(LED_RGB_G, !digitalRead(LED_RGB_G)); // Pisca verde
    digitalWrite(LED_RGB_R, LOW);
    digitalWrite(BUZZER, LOW);
  }
  else if (estado == "EVENTO") {
    digitalWrite(LED_RGB_R, HIGH);  // Vermelho
    digitalWrite(LED_RGB_G, HIGH);  // + Verde = Amarelo
    digitalWrite(BUZZER, LOW);
  }
  else if (estado == "ERRO") {
    // Pisca tudo
    digitalWrite(LED_RGB_R, !digitalRead(LED_RGB_R));
    digitalWrite(LED_RGB_G, !digitalRead(LED_RGB_G));
    digitalWrite(BUZZER, !digitalRead(BUZZER));
  }
}

void exibirDados() {
  Serial.println("\n==== LEITURA DOS SENSORES ====");
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");
  
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.println(" %");
  
  Serial.print("Rotação: ");
  Serial.print(rotacao);
  Serial.println(" %");
  
  Serial.print("Botão SW1: ");
  Serial.println(botao_pressionado ? "PRESSIONADO" : "SOLTO");
  
  Serial.print("IR: ");
  Serial.println(ir_detectado ? "DETECTADO" : "NÃO DETECTADO");
  
  Serial.print("Estado do Sistema: ");
  Serial.println(estado);
  Serial.println("================================\n");
}

// ===== FUNÇÃO DE DEBUG (Opcional) =====
void debugDadosJSON() {
  // Estrutura que será enviada para API
  Serial.println(montarJSON());
}

String montarJSON() {
  String json = "{";
  json += "\"temperatura\":" + String(temperatura) + ",";
  json += "\"umidade\":" + String(umidade) + ",";
  json += "\"rotacao\":" + String(rotacao) + ",";
  json += "\"estado\":\"" + estado + "\"";
  json += "}";
  return json;
}
