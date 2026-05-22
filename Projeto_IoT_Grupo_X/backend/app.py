from flask import Flask, request, jsonify
from functools import wraps
import os
from dotenv import load_dotenv

# Carregar variáveis do arquivo .env
load_dotenv()

app = Flask(__name__)
CHAVE_SECRETA = os.getenv('API_KEY', 'sua_chave_aqui')

print(f"✓ API Key carregada: {CHAVE_SECRETA[:10]}...")

# Decorator para validar API Key
def validar_api_key(f):
    @wraps(f)
    def decorated_function(*args, **kwargs):
        api_key = request.headers.get('X-API-Key')
        
        if not api_key:
            return jsonify({
                'erro': 'API Key não fornecida',
                'status': 'falha',
                'codigo': 'NO_API_KEY'
            }), 401
        
        if api_key != CHAVE_SECRETA:
            return jsonify({
                'erro': 'API Key inválida',
                'status': 'falha',
                'codigo': 'INVALID_API_KEY'
            }), 401
        
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
        
        print(f"✓ Dados recebidos: Temp={temperatura}°C, Umidade={umidade}%")
        
        return jsonify({
            'mensagem': 'Dados recebidos com sucesso',
            'temperatura': temperatura,
            'umidade': umidade,
            'status': 'sucesso'
        }), 200
    except Exception as e:
        return jsonify({
            'erro': str(e),
            'status': 'falha'
        }), 400

if __name__ == '__main__':
    print("🚀 Iniciando servidor...")
    print(f"📍 Acesse: http://localhost:5000")
    app.run(debug=True, host='0.0.0.0', port=5000)