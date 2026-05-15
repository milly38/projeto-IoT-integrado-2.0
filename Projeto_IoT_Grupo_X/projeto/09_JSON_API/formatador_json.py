import json

def formatar_dados(temp, umid, rotacao, estado):

    dados = {
        "temperatura": round(temp, 2),
        "umidade": round(umid, 2),
        "rotacao": rotacao,
        "estado": estado
    }

    return json.dumps(dados)
