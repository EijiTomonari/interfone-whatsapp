# Automação: Interfone com WhatsApp usando ESP32

## Resumo

Um código para monitorar por alterações na voltagem de um dispositivo usando o ADC do ESP32 e notificar via WhatsApp.

## API WhatsApp

A API utilizada é a CallMeBot, que é gratuita. Você precisa obter uma chave de API através do site deles.

## Divisor de Tensão

Se você for monitorar uma tensão maior do que 3.3v, você precisará de um divisor de tensão, pois a voltagem no ADC não pode passar desse valor. 

No meu caso, por exemplo, a voltagem de referência era de 12V.

Para mais informações sobre como fazer um divisor de tensão:

[Calculadora de Lei de Ohm](https://ohmslawcalculator.com/voltage-divider-calculator)

[Medir tensões com ESP32](https://www.youtube.com/watch?v=S34R4zg03uE&ab_channel=G6EJD-David)