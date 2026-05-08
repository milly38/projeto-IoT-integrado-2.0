# LÓGICA DO SISTEMA

## Funcionamento Geral

O sistema realiza leitura contínua dos sensores conectados ao ESP8266.

Os dados coletados são processados para tomada de decisões automáticas.

---

## Regras do Sistema

### Temperatura Alta
Quando a temperatura ultrapassa 30°C:
- o sistema entra em ALERTA
- o buzzer é acionado

---

### Botão Pressionado
Quando o botão SW1 é pressionado:
- o sistema entra em modo MANUAL
- o LED é acionado

---

### Detecção IR
Quando o sensor IR detecta sinal:
- o sistema registra EVENTO

---

### Rotação Elevada
Quando a rotação ultrapassa o limite:
- o sistema entra em estado CRÍTICO
- um alerta pode ser enviado

---

## Comunicação

Após o processamento:
- os dados são organizados em JSON
- enviados via TCP/IP
- armazenados no banco de dados
