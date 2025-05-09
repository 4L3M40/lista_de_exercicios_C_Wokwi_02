/*02) Desenvolva um sistema de alarme utilizando um sensor PIR para detectar 
movimento. Quando movimento é detectado, o sistema deve acionar um buzzer.*/

#define PIR_PIN 13  // Pino do sensor PIR
#define BUZZER_PIN 12  // Pino do buzzer

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int movimento = digitalRead(PIR_PIN);
  
  if (movimento == HIGH) { // Movimento detectado
    Serial.println("Movimento detectado! Acionando buzzer.");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000); // Buzzer ligado por 1 segundo
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    Serial.println("Nenhum movimento.");
  }

  delay(500); // Pequeno delay para evitar leituras falsas
}
