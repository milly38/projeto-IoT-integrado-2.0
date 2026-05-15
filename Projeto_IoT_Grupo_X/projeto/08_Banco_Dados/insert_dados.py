from conexao import conectar

def inserir(temperatura, umidade, rotacao, estado):

    conn = conectar()
    cursor = conn.cursor()

    sql = """
    INSERT INTO sensores (temperatura, umidade, rotacao, estado)
    VALUES (%s, %s, %s, %s)
    """

    valores = (temperatura, umidade, rotacao, estado)

    cursor.execute(sql, valores)
    conn.commit()

    print("Dados inseridos com sucesso!")

    cursor.close()
    conn.close()
