# CONFIGURAÇÃO DO AMBIENTE

## Objetivo
Configurar corretamente a Arduino IDE para programação da placa ESP8266 D1.

---

## Arduino IDE

Foi realizada a instalação da Arduino IDE para desenvolvimento do sistema IoT.

---

## Configuração do ESP8266

Para habilitar suporte ao ESP8266 na IDE, foi adicionada a seguinte URL:

http://arduino.esp8266.com/stable/package_esp8266com_index.json

Caminho utilizado:

Arquivo → Preferências → URLs adicionais para Gerenciadores de Placas

---

## Instalação da Placa

Passos realizados:

1. Acessar:
Ferramentas → Placa → Gerenciador de Placas

2. Pesquisar:
ESP8266

3. Instalar o pacote:
ESP8266 Community

---

## Seleção da Placa

A placa utilizada no projeto foi:

LOLIN(WEMOS) D1 R2 & mini

---

## Seleção da Porta COM

Foi selecionada a porta COM correspondente ao ESP8266 conectado via USB.

---

## Teste Blink

Foi utilizado o código Blink para validar:

- comunicação da placa
- upload do código
- funcionamento da IDE

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
}
---

## Resultado

O upload foi realizado com sucesso e o LED interno da placa piscou corretamente, confirmando:

- funcionamento da IDE
- reconhecimento da placa
- comunicação USB ativa
- ambiente pronto para desenvolvimento


---
