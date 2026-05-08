CREATE DATABASE projeto_iot;

USE projeto_iot;

CREATE TABLE sensores (
    id INT PRIMARY KEY AUTO_INCREMENT,
    nome VARCHAR(50),
    tipo VARCHAR(50)
);

CREATE TABLE leituras (
    id INT PRIMARY KEY AUTO_INCREMENT,
    temperatura FLOAT,
    umidade FLOAT,
    rotacao INT,
    estado VARCHAR(30),
    data_leitura TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE alertas (
    id INT PRIMARY KEY AUTO_INCREMENT,
    mensagem VARCHAR(100),
    nivel VARCHAR(30),
    data_alerta TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE logs (
    id INT PRIMARY KEY AUTO_INCREMENT,
    descricao VARCHAR(255),
    data_log TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
