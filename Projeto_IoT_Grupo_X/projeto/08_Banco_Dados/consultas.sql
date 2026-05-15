-- Ver todos os dados
SELECT * FROM sensores;

-- Últimos registros
SELECT * FROM sensores ORDER BY data_hora DESC LIMIT 10;

-- Média de temperatura
SELECT AVG(temperatura) FROM sensores;
