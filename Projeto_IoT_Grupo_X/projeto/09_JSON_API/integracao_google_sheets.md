# INTEGRAÇÃO COM GOOGLE SHEETS

## Objetivo

Pesquisar formas de integração entre o sistema IoT e o Google Sheets para armazenamento e visualização das informações coletadas.

---

## Funcionamento da Integração

Os dados coletados pelo ESP8266 podem ser enviados para um banco de dados e posteriormente sincronizados com o Google Sheets.

Fluxo da informação:

ESP8266 → API → Banco de Dados → Google Sheets

---

## Tecnologias Utilizadas

As tecnologias pesquisadas para integração foram:

- Python
- Google Sheets API
- Webhooks
- JSON
- APIs REST

---

## Google Sheets API

A Google Sheets API permite:
- criar planilhas
- adicionar linhas automaticamente
- atualizar dados em tempo real
- integrar sistemas externos

---

## Processo de Funcionamento

1. O ESP8266 coleta os dados dos sensores
2. Os dados são organizados em JSON
3. A API recebe as informações
4. O banco de dados armazena os registros
5. Um script em Python envia os dados ao Google Sheets

---

## Autenticação

A integração com o Google Sheets exige autenticação utilizando:
- conta Google
- chave de API
- permissões de acesso

---

## Possíveis Dificuldades

Durante a pesquisa foram identificados alguns desafios:

- limite de requisições da API
- necessidade de autenticação
- conexão com internet
- tratamento de erros de comunicação

---

## Importância da Integração

A integração com Google Sheets facilita:
- visualização dos dados
- geração de relatórios
- acompanhamento remoto
- organização das informações

---

## Exemplo de Dados

{
  "temperatura": 28,
  "umidade": 60,
  "rotacao": 120,
  "estado": "NORMAL"
}
