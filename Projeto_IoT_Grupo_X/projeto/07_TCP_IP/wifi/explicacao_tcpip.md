# COMUNICAÇÃO TCP/IP

## Objetivo
Permitir que o ESP8266 envie informações pela rede Wi-Fi utilizando o protocolo TCP/IP.

---

## O que é TCP/IP

TCP/IP é o conjunto de protocolos responsável pela comunicação entre dispositivos em rede, sendo utilizado na internet e em sistemas IoT.

O TCP (Transmission Control Protocol) garante que os dados sejam enviados corretamente e sem perdas.

O IP (Internet Protocol) é responsável pelo endereçamento dos dispositivos conectados na rede.

---

## Funcionamento no Projeto

No sistema desenvolvido, o ESP8266 conecta-se à rede Wi-Fi e envia dados coletados pelos sensores para integração com API e banco de dados.

Fluxo da comunicação:

ESP8266 → Wi-Fi → API → Banco de Dados

---

## Cliente e Servidor

O ESP8266 funciona como cliente, enviando informações para um servidor responsável pelo armazenamento e processamento dos dados.

O servidor pode:
- receber informações
- armazenar dados
- gerar relatórios
- integrar com outros sistemas

---

## API REST

A comunicação poderá ser realizada utilizando APIs REST, permitindo envio de dados em formato JSON.

Exemplo:

{
  "temperatura": 28,
  "umidade": 60,
  "estado": "NORMAL"
}

---

## Importância em Sistemas IoT

A utilização do TCP/IP permite:
- monitoramento remoto
- integração entre dispositivos
- armazenamento em nuvem
- compartilhamento de dados em tempo real

---

## Problemas Encontrados

Durante os testes foram encontrados:
- falhas de conexão Wi-Fi
- erro de autenticação
- instabilidade de sinal

As soluções envolveram:
- correção da senha da rede
- reinicialização da placa
- melhoria na configuração da comunicação
