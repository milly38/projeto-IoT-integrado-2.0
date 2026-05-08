# 🚀 Projeto Integrador - Sistema IoT com ESP8266

## 👥 Equipe do Projeto
- Emilly
- Gabriela 
- Gustavo Henrique
- Pedro Santos 

---

## 📌 Descrição do Projeto
Este projeto consiste no desenvolvimento de um sistema de monitoramento inteligente utilizando o microcontrolador ESP8266, integrado com sensores, API, banco de dados e visualização de dados.

O sistema é capaz de coletar dados em tempo real, processar informações e disponibilizá-las para análise.

---

## 🎯 Objetivo
Desenvolver uma solução de IoT capaz de:

- Coletar dados de sensores (temperatura, umidade, rotação, etc.)
- Processar informações em tempo real
- Armazenar dados em banco de dados
- Integrar com API e serviços externos (ex: Google Sheets)
- Simular um sistema de automação industrial

---

## 🛠️ Tecnologias Utilizadas

- ESP8266 D1
- Arduino IDE
- JSON
- TCP/IP
- MySQL
- API REST
- Google Sheets
- GitHub
- 
---

## 🧠 Etapas do Projeto

### ⚙️ 01 - Configuração do Ambiente
Configuração da Arduino IDE, instalação da placa ESP8266 e validação do funcionamento com teste básico (Blink).

---

### 🔌 02 - Investigação de Pinos
Estudo técnico dos pinos do ESP8266, identificando quais podem ser utilizados com segurança no sistema.

---

### 🧩 03 - Modelagem do Sistema
Definição das regras de funcionamento, entradas, saídas e fluxo de processamento dos dados.

---

### 📸 04 - Evidências
Registro de testes, prints da IDE, funcionamento de sensores e validações do sistema.

---

### 🔁 05 - Atualizações
Controle de versões e evolução do desenvolvimento do projeto.

---

## 🔄 Fluxo do Sistema

Sensores → ESP8266 → Processamento → JSON → API → Banco de Dados → Google Sheets
---

## 📊 Variáveis do Sistema

- Temperatura  
- Umidade  
- Rotação  
- Estado do sistema  

---

## 💡 Regras de Funcionamento

| Condição              | Estado   | Ação                    |
|----------------------|----------|-------------------------|
| Temp > 30°C          | ALERTA   | Ativar notificação      |
| Botão pressionado    | MANUAL   | Alterar modo           |
| IR detectado         | EVENTO   | Registrar ocorrência    |
| Rotação fora do limite | CRÍTICO | Enviar alerta          |

---

## 📚 Aprendizados

- Configuração de microcontroladores ESP8266  
- Estruturação de sistemas IoT  
- Modelagem de sistemas automatizados  
- Investigação de hardware e pinos  
- Organização de projeto em etapas  

---

## 📸 Evidências

Todas as evidências estão organizadas na pasta:

📁 `04_Evidencias/`

Incluindo:
- Prints da IDE  
- Testes de sensores  
- Resultados do sistema  
- Imagens do hardware  

---

## 🔁 Controle de Versão

### v1.0
- Estrutura inicial do projeto

### v1.1
- Configuração do ESP8266

### v1.2
- Investigação dos pinos

### v2.0
- Definição da modelagem do sistema

---

## 🚨 Problemas e Soluções

| Problema | Solução |
|----------|--------|
| Erro de upload | Ajuste de porta COM |
| Pino incorreto | Correção com base no datasheet |
| Falha no boot | Evitado uso de pinos restritos |

---

## ⚠️ Observações Finais

Este projeto segue uma abordagem incremental, onde cada etapa é validada antes da implementação da próxima, garantindo maior confiabilidade e organização do sistema.

---



