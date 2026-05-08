# REGRAS DO SISTEMA

## Objetivo

Definir o comportamento do sistema de automação utilizando ESP8266 e sensores integrados.

---

# TABELA DE REGRAS

| Condição | Estado | Ação |
|----------|--------|------|
| Temperatura > 30°C | ALERTA | Acionar buzzer |
| SW1 pressionado | MANUAL | Acionar LED |
| IR detectado | EVENTO | Registrar ocorrência |
| Rotação alta | CRÍTICO | Enviar alerta |

---

# Funcionamento

O sistema realiza monitoramento contínuo dos sensores conectados ao ESP8266.

Com base nas leituras recebidas, o sistema executa decisões automáticas conforme as regras programadas.

---

# Estados do Sistema

## NORMAL
Funcionamento padrão sem ocorrências críticas.

---

## ALERTA
Ativado quando valores ultrapassam limites definidos.

---

## MANUAL
Ativado por interação do usuário através dos botões.

---

## CRÍTICO
Indica condição de risco ou funcionamento inadequado do sistema.

---

# Objetivo das Regras

As regras foram definidas para simular um sistema de automação industrial capaz de:

- monitorar sensores
- gerar alertas
- responder automaticamente
- registrar eventos
- organizar informações para análise
