# BANCO DE DADOS

## Objetivo

Armazenar os dados coletados pelo sistema IoT utilizando um banco de dados relacional.

---

## Banco Escolhido

O banco de dados escolhido foi o MySQL.

---

## Justificativa da Escolha

O MySQL foi escolhido por:
- facilidade de utilização
- integração com APIs
- suporte amplo
- organização relacional
- compatibilidade com sistemas IoT

---

## Estrutura do Banco

O banco será responsável por armazenar:

- sensores
- leituras
- alertas
- logs

---

## Funcionamento

O ESP8266 envia os dados em JSON.

A API recebe as informações e armazena os registros no banco de dados.

---

## Importância

O banco de dados permite:
- histórico das leituras
- monitoramento
- geração de relatórios
- organização das informações
