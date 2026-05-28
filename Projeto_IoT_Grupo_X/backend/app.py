from flask import Flask, request, jsonify
from functools import wraps
import os
from dotenv import load_dotenv
import mysql.connector # Importa o conector do MySQL

# Carregar variáveis do arquivo .env
load_dotenv()

app = Flask(__name__)
CHAVE_SECRETA = os.getenv('API_KEY', 'sua_chave_aqui')

print(f"✓ API Key carregada: {CHAVE_SECRETA[:10]}...")

# Função auxiliar para conectar e inserir logs no MySQL
def salvar_log_banco(tabela, campos, valores):
    conexao = None
    cursor = None
    try:
        conexao = mysql.connector.connect(
            host=os.getenv('DB_HOST', 'localhost'),
            user=os.getenv('DB_USER'),
            password=os.getenv('DB_PASSWORD'),
            database=os.getenv('DB_NAME')
        )
        cursor = conexao.cursor()
        
        # Cria a query dinamicamente baseada nos campos passados
        placeholders = ", ".join(["%s"] * len(valores))
        colunas = ", ".join(campos)
        query = f"INSERT INTO {tabela} ({colunas}) VALUES ({placeholders})"
        
        cursor.execute(query, valores)
        conexao.commit()
    except Exception as e:
        # Se falhar o banco de dados, printamos no terminal (falha crítica de infraestrutura)
        print(f"❌ Erro crítico ao salvar log no banco: {str(e)}")
    finally:
        if cursor: cursor.close()
        if conexao: conexao.close()

# Decorator para validar API Key
def validar_api_key(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        api_key = request.headers.get('X-API-Key')
        endpoint_atual = request.path
        
        if not api_key:
            # LOG: Tentativa de acesso sem chave fornecida
            salvar_log_banco(
                'logs_acesso', 
                ['status_acesso', 'endpoint', 'mensagem'], 
                ['FALHA', endpoint_atual, 'API Key nao fornecida']
            )
            return jsonify({
                'erro': 'API Key não fornecida',
                'status': 'falha',
                'codigo': 'NO_API_KEY'
            }), 401
        
        if api_key != CHAVE_SECRETA:
            # LOG: Tentativa de acesso com chave errada (Invasão/Erro de config)
            salvar_log_banco(
                'logs_acesso', 
                ['status_acesso', 'endpoint', 'mensagem'], 
                ['FALHA', endpoint_atual, 'API Key invalida']
            )
            return jsonify({
                'erro': 'API Key inválida',
                'status': 'falha',
                'codigo': 'INVALID_API_KEY'
            }), 401
        
        # LOG: Acesso permitido com sucesso antes de rodar a rota
        salvar_log_banco(
            'logs_acesso', 
            ['status_acesso', 'endpoint', 'mensagem'], 
            ['SUCESSO', endpoint_atual, 'Acesso autorizado']
        )
        return f(*args, **kwargs)
    return decorated_function

# Rota pública (sem autenticação)
@app.route('/api/status', methods=['GET'])
def status():
    return jsonify({
        'mensagem': 'API está funcionando',
        'status': 'online'
    }), 200

# Rota protegida (COM autenticação)
@app.route('/api/dados', methods=['POST'])
@validar_api_key
def receber_dados():
    try:
        dados = request.get_json()
        temperatura = dados.get('temperatura')
        umidade = dados.get('umidade')
        
        # Validação básica de payload/dados nulos (Item 1 do roteiro: validação de requisições)
        if temperatura is None or umidade is None:
            # LOG: Dados inválidos vindos do ESP8266
            salvar_log_banco(
                'logs_eventos_falhas',
                ['origem', 'tipo_evento', 'descricao'],
                ['ESP8266', 'ALERTA', 'Payload recebido com campos ausentes ou nulos']
            )
            return jsonify({'erro': 'Dados incompletos', 'status': 'falha'}), 400
            
        print(f"✓ Dados recebidos: Temp={temperatura}°C, Umidade={umidade}%")
        
        return jsonify({
            'mensagem': 'Dados recebidos com sucesso',
            'temperatura': temperatura,
            'umidade': umidade,
            'status': 'sucesso'
        }), 200
        
    except Exception as e:
        # LOG: Se houver erro de servidor interno ou json corrompido
        salvar_log_banco(
            'logs_eventos_falhas',
            ['origem', 'tipo_evento', 'descricao'],
            ['API_PYTHON', 'ERRO', f'Erro ao processar dados: {str(e)}']
        )
        return jsonify({
            'erro': str(e),
            'status': 'falha'
        }), 400

if __name__ == '__main__':
    print("🚀 Iniciando servidor...")
    print(f"📍 Acesse: http://localhost:5000")
    app.run(debug=True, host='0.0.0.0', port=5000)
