import os
import requests
from dotenv import load_dotenv

load_dotenv()

def obter_cotacao_dolar():
    # API pública e gratuita de câmbio
    url = "https://economia.awesomeapi.com.br/last/USD-BRL"
    
    try:
        resposta = requests.get(url)
        resposta.raise_for_status()  # Lança um erro se a requisição falhar
        
        dados = resposta.json()
        cotacao = dados["USDBRL"]["bid"]
        return float(cotacao)
    except requests.exceptions.RequestException as e:
        print(f"Erro ao consultar a API: {e}")
        return None
def obter_cotacao_euro():
    # API pública e gratuita de câmbio
    url = "https://economia.awesomeapi.com.br/last/EUR-BRL"

    try:
        resposta = requests.get(url)
        resposta.raise_for_status()  # Lança um erro se a requisição falhar
        
        dados = resposta.json()
        cotacao = dados["EURBRL"]["bid"]
        return float(cotacao)
    except requests.exceptions.RequestException as e:
        print(f"Erro ao consultar a API: {e}")
        return None
def obter_cotacao_bitcoin():
    # API pública e gratuita de câmbio
    url = "https://economia.awesomeapi.com.br/last/BTC-BRL"

    try:
        resposta = requests.get(url)
        resposta.raise_for_status()  # Lança um erro se a requisição falhar
        
        dados = resposta.json()
        cotacao = dados["BTCBRL"]["bid"]
        return float(cotacao)
    except requests.exceptions.RequestException as e:
        print(f"Erro ao consultar a API: {e}")
        return None
    

def enviar_alerta_telegram(mensagem):
    
    bot_token = os.getenv("TELEGRAM_BOT_TOKEN")
    chat_id = os.getenv("TELEGRAM_CHAT_ID")
    if not bot_token or not chat_id:
        print("\n[Simulação de Alerta] Token ou Chat ID do Telegram não configurados.")
        print(f"Não foi possível enviar a mensagem.")
        
    

    url = f"https://api.telegram.org/bot{bot_token}/sendMessage"
    payload = {"chat_id": chat_id, "text": mensagem}

    try:
        requests.post(url, data=payload)
        print("Alerta enviado com sucesso pelo Telegram!")
    except Exception as e:
        print(f"Erro ao enviar mensagem pelo Telegram: {e}")

def main():
    opcao = 0
    while not (opcao == -1):
     opcao = int(input("Escolha uma cotação: \n 1: Dolar \n 2: Euro \n 3: Libra \n 4: Bitcoin \n-1: Sair \n"))
     match opcao:
         case 1:
           print("Você escolheu a Dolar")
           cotacao = obter_cotacao_dolar()
           if cotacao:
                   valor_formatado = f"R$ {cotacao:.2f}"
                   print(f"Cotação atual do Dólar: {valor_formatado}")
                   
                   
                   limite_desejado = 5.20
                   
                   if cotacao <= limite_desejado:
                       mensagem = f"🚨 ALERTA DE CÂMBIO! O Dólar caiu para {valor_formatado}!"
                       enviar_alerta_telegram(mensagem)
                   else:
                       mensagem = f"📊 Cotação diária: O Dólar está em {valor_formatado} (acima do limite de R$ {limite_desejado:.2f})."
                       enviar_alerta_telegram(mensagem)
         case 2:
           print("Você escolheu a Euro")
           cotacao = obter_cotacao_euro()
           if cotacao:
                              valor_formatado = f"R$ {cotacao:.2f}"
                              print(f"Cotação atual do Euro: {valor_formatado}")
                              
                              
                              limite_desejado = 5.50
                              
                              if cotacao <= limite_desejado:
                                  mensagem = f"🚨 ALERTA DE CÂMBIO! O Euro caiu para {valor_formatado}!"
                                  enviar_alerta_telegram(mensagem)
                              else:
                                  mensagem = f"📊 Cotação diária: O Euro está em {valor_formatado} (acima do limite de R$ {limite_desejado:.2f})."
                                  enviar_alerta_telegram(mensagem)
           
         case 3:
           print("Você escolheu a Libra")
           cotacao = obter_cotacao_libra()
           if cotacao:
                              valor_formatado = f"R$ {cotacao:.2f}"
                              print(f"Cotação atual da Libra: {valor_formatado}")
                              
                              
                              limite_desejado = 6.00
                              
                              if cotacao <= limite_desejado:
                                  mensagem = f"🚨 ALERTA DE CÂMBIO! A Libra caiu para {valor_formatado}!"
                                  enviar_alerta_telegram(mensagem)
                              else:
                                  mensagem = f"📊 Cotação diária: A Libra está em {valor_formatado} (acima do limite de R$ {limite_desejado:.2f})."
                                  enviar_alerta_telegram(mensagem)
         case 4:
           print("Você escolheu o Bitcoin")
           cotacao = obter_cotacao_bitcoin()
           if cotacao:
                              valor_formatado = f"R$ {cotacao:.2f}"
                              print(f"Cotação atual do Bitcoin: {valor_formatado}")
                              
                              
                              limite_desejado = 100000.00
                              
                              if cotacao <= limite_desejado:
                                  mensagem = f"🚨 ALERTA DE CÂMBIO! O Bitcoin caiu para {valor_formatado}!"
                                  enviar_alerta_telegram(mensagem)
                              else:
                                  mensagem = f"📊 Cotação diária: O Bitcoin está em {valor_formatado} (acima do limite de R$ {limite_desejado:.2f})."
                                  enviar_alerta_telegram(mensagem)

               

if __name__ == "__main__":
    main()