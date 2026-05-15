# Arquitetura da API - Sistema IoT

## Objetivo
A API tem a função de receber os dados enviados pelo ESP8266, processar, armazenar e disponibilizar para visualização.

---

## Tecnologias utilizadas
- Python
- Flask
- Flask-RESTful (opcional)
- JSON
- HTTP POST

---

## Fluxo da API

1. ESP8266 coleta dados dos sensores
2. Envia requisição HTTP POST
3. API Flask recebe os dados
4. Valida e trata as informações
5. Armazena no banco de dados
6. (Opcional) envia para Google Sheets

---

## Estrutura da requisição

```json
{
  "temperatura": 25.6,
  "umidade": 60,
  "luminosidade": 300,
  "status": "OK"
}
