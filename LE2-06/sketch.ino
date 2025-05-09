/*06) Crie um sistema para monitorar a disponibilidade de vagas de estacionamento 
usando sensores de ultrassom para detectar se uma vaga está ocupada ou não, o 
estacionamento possui 10 vagas.*/

#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>

// Configuração dos pinos (como no seu projeto funcional)
#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

// Pinos dos sensores PIR
const int pirPins[] = {14, 27, 26, 25, 33, 32, 13, 16, 17, 21};

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  
  // Inicialização do display (modificação para evitar o erro)
  tft.begin();
  
  // Verificação alternativa
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(10, 10);
  tft.println("ESTACIONAMETO");
  Serial.println("Display inicializado");

  // Configura sensores PIR
  for (int i = 0; i < 10; i++) {
    pinMode(pirPins[i], INPUT_PULLDOWN);
  }
  
  delay(1000); // Tempo para estabilização
}

void loop() {
  // Atualização do status das vagas
  for(int i = 0; i < 10; i++) {
    bool ocupada = digitalRead(pirPins[i]);
    
    // Atualiza display
    tft.fillRect(10, 50 + (i * 20), 200, 18, ocupada ? ILI9341_RED : ILI9341_GREEN);
    tft.setTextSize(1);
    tft.setCursor(15, 50 + (i * 20));
    tft.print("Vaga ");
    tft.print(i + 1);
    tft.print(": ");
    tft.print(ocupada ? "OCUPADA" : "LIVRE  ");
    
    delay(50); // Pequeno delay entre leituras
  }
  
  delay(500); // Atualização geral mais lenta
}