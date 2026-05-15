from flask import Flask, request

app = Flask(__name__)

@app.route('/dados', methods=['POST'])
def dados():
    data = request.json
    print("Recebido:", data)
    return {"status": "ok"}

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
