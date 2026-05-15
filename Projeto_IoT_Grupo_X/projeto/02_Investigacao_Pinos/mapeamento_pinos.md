# Mapeamento de Pinos - ESP8266 D1 Mini

## Objetivo
Definir a utilização dos pinos do ESP8266 no sistema IoT de monitoramento e controle.

---

## Placa utilizada
ESP8266 D1 Mini

---

## Mapeamento de Hardware

| Componente        | Pino ESP8266 | GPIO   | Função                     |
|------------------|-------------|--------|----------------------------|
| LED 1            | D1          | GPIO5  | Saída digital (indicador)  |
| LED 2            | D0          | GPIO16 | Saída digital (indicador)  |
| Botão SW1        | D2          | GPIO4  | Entrada digital            |
| Botão SW2        | D3          | GPIO0  | Entrada digital (BOOT)     |
| DHT11            | D4          | GPIO2  | Sensor temperatura/umidade |
| Buzzer           | D7          | GPIO13 | Alarme sonoro              |
| Sensor IR        | D6          | GPIO12 | Detecção de objeto         |
| Encoder (rotação)| RX / D8     | GPIO3/15 | Leitura de rotação       |
| RGB LED          | D8, D9, D10 | GPIO15, GPIO9, GPIO10 | Controle RGB |
| LM35 (analógico) | A0          | ADC0   | Leitura de temperatura analógica |

---

## ⚠️ Observações importantes

- GPIO0 (D3) interfere no boot → usar com cuidado (pull-up necessário)
- GPIO15 (D8) deve estar LOW no boot
- ESP8266 possui apenas 1 entrada analógica (A0)
- Não existem A1 e A2 no ESP8266

---

## Comunicação do sistema

Os dados coletados serão enviados via Wi-Fi para uma API Flask utilizando protocolo HTTP em formato JSON.
