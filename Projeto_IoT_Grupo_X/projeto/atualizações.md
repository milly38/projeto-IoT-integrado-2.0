##changelog.md
--------------------------------------
# Changelog - Sistema IoT ESP8266

## Versão 1.0 - Início do Projeto
- Criação da estrutura inicial do ESP8266
- Configuração de conexão Wi-Fi
- Testes básicos de pinos

---

## Versão 1.1 - Sensores
- Implementação do DHT11
- Leitura de temperatura e umidade
- Testes de estabilidade dos sensores

---

## Versão 1.2 - API Flask
- Criação da API em Python
- Implementação do endpoint /dados
- Recebimento de dados via HTTP POST

---

## Versão 1.3 - Banco de Dados
- Integração com MySQL/SQLite
- Armazenamento de dados em tempo real
- Estruturação da tabela sensores

---

## Versão 1.4 - Integração Cloud
- Integração com Google Sheets
- Visualização de dados em tempo real
- Melhorias na comunicação ESP → API

- -------------------------------
## melhorias_futuras.md
---
# Melhorias Futuras - Sistema IoT

## Expansões possíveis do projeto

### Dashboard Web
- Criar painel com gráficos em tempo real
- Usar React ou HTML + Chart.js

### Autenticação
- Login de usuários na API
- Controle de acesso aos dados

### Banco em nuvem
- Migrar banco local para cloud (AWS, Firebase ou Azure)

### Alertas inteligentes
- Envio de alertas por e-mail ou WhatsApp
- Notificação quando temperatura ultrapassar limite

### Machine Learning
- Previsão de falhas com base nos sensores
- Análise de padrões de temperatura

### Escalabilidade
- Adicionar mais sensores IoT
- Suporte a múltiplos ESP8266

- ---------------------
## bugs_corrigidos.md 
---
# Bugs Corrigidos - Sistema IoT

## Problemas encontrados e resolvidos

### Problema 1 - Conexão Wi-Fi instável
- Causa: credenciais incorretas ou sinal fraco
- Solução: ajuste no SSID e melhoria do loop de conexão

---

### Problema 2 - Falha na leitura do DHT11
- Causa: delay insuficiente entre leituras
- Solução: aumento do tempo de delay no loop

---

### Problema 3 - API não recebia dados
- Causa: endpoint incorreto ou JSON mal formatado
- Solução: padronização do formato JSON no ESP8266

---

### Problema 4 - Banco de dados não armazenava registros
- Causa: conexão SQL mal configurada
- Solução: ajuste na string de conexão e validação de dados
