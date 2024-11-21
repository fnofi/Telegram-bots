import telebot
from gradio_client import Client
bot=telebot.TeleBot('6197009361:AAENWL8Bjn18gZPhdyUCOcmzPKHpHWLDIlU')
@bot.message_handler(content_types=['text'])
def get_text_messages(message):
    if message.text=="/start":
        bot.send_message(message.from_user.id, "Добро пожаловать! Введите команду - \"/gpt\", чтобы получить информацию об правилах ЖКХ.")
    if message.text=="/gpt":
        bot.send_message(message.from_user.id, "Введите ваш вопрос:")
        bot.register_next_step_handler(message, get_ques)
def get_ques(message):
    global ques
    ques=message.text
    bot.send_message(message.from_user.id, "Ожидайте, я скоро отвечу.")
    client = Client("https://22b0e3df25f7e3d3b0.gradio.live")
    result = client.predict(ques, api_name="/predict")
    bot.send_message(message.from_user.id, result)
bot.polling(non_stop=True,interval=0)
