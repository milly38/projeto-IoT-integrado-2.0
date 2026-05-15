import json

def validar_dados(dados):

    campos_obrigatorios = ["temperatura", "umidade", "estado"]

    for campo in campos_obrigatorios:
        if campo not in dados:
            return False

    return True


# teste rápido
if __name__ == "__main__":
    teste = {"temperatura": 25, "umidade": 60, "estado": "OK"}

    print(validar_dados(teste))
