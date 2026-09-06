🤖 Bot de Cotação de Moedas no Telegram
Script em Python que consulta a cotação em tempo real de moedas (via AwesomeAPI) e envia alertas automáticos no Telegram com suporte a variáveis de ambiente para segurança das credenciais.

🛠️ Tecnologias Utilizadas
Python 3.10+

Requests: Consumo de APIs REST.

Python-dotenv: Gerenciamento seguro de variáveis de ambiente.

AwesomeAPI: API pública de cotações financeiras.

Telegram Bot API: Envio de notificações de câmbio.
1. Instalação de Dependências

No terminal da sua IDE (com o ambiente virtual ativo), rode o comando abaixo para instalar as duas bibliotecas necessárias:

Bash
pip install requests python-dotenv
2. Configuração dos Tokens (Arquivo .env)

Crie um arquivo chamado .env na raiz do projeto e insira seus dados do Telegram:

Snippet de código
TELEGRAM_BOT_TOKEN=seu_token_aqui
TELEGRAM_CHAT_ID=seu_chat_id_aqui
TELEGRAM_BOT_TOKEN: Obtenha enviando o comando /newbot para o @BotFather no Telegram.

TELEGRAM_CHAT_ID: Obtenha enviando qualquer mensagem para o bot @userinfobot no Telegram.
