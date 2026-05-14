#controle_versoes.md
---
# CONTROLE DE VERSÕES

| Versão | Data | Alteração |
|--------|------|-----------|
| v1.0 | 23/04 | Estrutura inicial do projeto |
| v1.1 | 24/04 | Configuração do ESP8266 |
| v1.2 | 24/04 | Investigação dos pinos |
| v2.0 | 25/04 | Implementação da leitura dos sensores |
| v2.1 | 26/04 | Estruturação dos dados JSON |
| v2.2 | 27/04 | Organização das pastas do GitHub |
| v2.2 | 14/05 | Reestruturação do código dos sensores |

---
#mudancas.md
---
# MUDANÇAS E MELHORIAS

---

## Ajuste da Comunicação Wi-Fi

Ocorreram falhas de autenticação durante conexão com a rede.

Foi necessário:
- corrigir senha
- revisar configuração da rede

---

## Organização do Projeto

A estrutura do GitHub foi reorganizada para melhorar:
- documentação
- separação das etapas
- controle das evidências

## Alteração 14/05 - PEU

**Problema/Solução**
Memória IRAM acima de 90% -	Otimizou strings, removeu debug desnecessários
WiFi desconecta frequentemente - Adicionou reconexão automática com delay progressivo
JSON não formatava corretamente - Usou library ArduinoJson (opcional mas recomendada)
MySQL conexão tira timeout - Aumentou connection timeout, adicionou keep-alive
Google Sheets limite de requests - Implementou sincronização em lotes (1/minuto)
