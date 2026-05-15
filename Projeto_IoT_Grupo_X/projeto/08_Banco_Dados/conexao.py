## sql server
-----
conexao = pyodbc.connect(

    'DRIVER={SQL Server};'
    'SERVER=.\\SQLEXPRESS;'
    'DATABASE=ProjetoIoT;'
    'Trusted_Connection=yes;'
)

cursor = conexao.cursor()

print("SQL Server conectado!")
----
##MySQL
---
import mysql.connector

def conectar():
    conn = mysql.connector.connect(
        host="localhost",
        user="root",
        password="",
        database="ProjetoIoT"
    )
    return conn
