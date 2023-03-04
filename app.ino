#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <string.h>

const char *WIFI_SSID = "Nome da Sua Rede";
const char *WIFI_PASSWORD = "Senha da Sua Rede";
const char *SERVER_URL = "https://api.callmebot.com/whatsapp.php?";
const char *PHONE = "phone=5511999999999";
const char *MESSAGE = "&text=Sua+mensagem+de+teste";
const char *API_KEY = "&apikey=999999999";
char REQUEST_URL[200]; // URL de requisição

const int VP_PIN = 36; // Pino VP do ESP32

void setup()
{
  Serial.begin(115200);

  // Se você preferir, pode colocar a URL completa na variável diretamente
  // Eu preferi dividir em partes para facilitar a leitura e depois concatenar

  strcpy(REQUEST_URL, SERVER_URL);
  strcat(REQUEST_URL, PHONE);
  strcat(REQUEST_URL, MESSAGE);
  strcat(REQUEST_URL, API_KEY);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Conectado ao Wi-Fi...");
  }

  Serial.println("Wi-Fi conectado com sucesso!");

  delay(1000);
}

void loop()
{
  HTTPClient http;
  int voltage = analogRead(VP_PIN);

  // Converte o valor do ADC para voltagem
  // 4095 é a resolução do ADC, 12 é a voltagem de referência
  // Se você estiver usando outra voltagem de referência, altere o 12 para a voltagem de referência
  float voltageValue = voltage / 4095.0 * 12;

  if (voltageValue > 6)
  {
    http.begin(REQUEST_URL);
    int httpCode = http.GET();
    http.end();
    delay(5000);
  }

  delay(200);
}