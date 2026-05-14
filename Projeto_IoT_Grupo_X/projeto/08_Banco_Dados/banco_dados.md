# BANCO DE DADOS

## Objetivo

Armazenar os dados coletados pelo sistema IoT utilizando um banco de dados relacional.

---

## Banco Escolhido

O banco de dados escolhido foi o MySQL.

---

## Justificativa da Escolha

**Relacionamentos bem estruturados**
- Suporta chaves estrangeiras (FOREIGN KEY)
- Permite relação 1:N entre SENSORES e LEITURAS
- Permite relação 1:0,1 entre LEITURAS e ALERTAS
- Integridade referencial garantida

**Performance adequada**
- Para centenas de leituras por dia: excelente
- Índices na coluna `data_leitura` permitem consultas rápidas
- Queries simples executam em milissegundos
**Integração com tecnologias do projeto**
- Biblioteca `mysql` do Node.js: ✓ Nativa
- Suporte a API REST: ✓ Direto do servidor Node.js
- Integração Google Sheets: ✓ Via script Node.js

**Escalabilidade**
- Suporta milhões de registros
- Pode rodar em servidor local (SENAI) ou em cloud
- Fácil backup e recuperação

**Segurança**
- Autenticação por usuário/senha
- Controle de permissões por tabela
- Criptografia em produção

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
