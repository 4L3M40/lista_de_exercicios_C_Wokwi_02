/*05) Desenvolva um sistema de porta automática que use um sensor de proximidade 
para detectar a aproximação de uma pessoa e acione um motor para abrir a porta.*/

#include <Arduino.h>
#include <Servo.h>

const int triggerPin = 5;  // Pino Trigger do HC-SR04
const int echoPin = 6;     // Pino Echo do HC-SR04
const int servoPin = 9;    // Pino do servo motor
const int distanceThreshold = 30; // Distância limite (cm) para abrir a porta

Servo servoMotor;         // Cria o objeto servo

unsigned long lastActionTime = 0; // Tempo da última ação
const unsigned long openDuration = 3000; // Duração de 3 segundos para a porta aberta

bool isDoorOpen = false; // Estado da porta
long lastDistance = 0;   // Armazena a última distância medida

long readDistance() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    long duration = pulseIn(echoPin, HIGH);
    long distance = duration * 0.034 / 2; // Conversão para cm
    return distance;
}

void setup() {
    Serial.begin(115200);
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);

    servoMotor.attach(servoPin); // Conecta o servo motor ao pino 9

    servoMotor.write(0); // Começa com a porta fechada (servo na posição 0)
}

void loop() {
    long distance = readDistance();
    Serial.print("Distância: ");
    Serial.print(distance);
    Serial.println(" cm");

    unsigned long currentMillis = millis(); // Obtém o tempo atual

    // Verifica se a distância é consistentemente menor que o limiar para abrir a porta
    if (distance < distanceThreshold && !isDoorOpen && abs(distance - lastDistance) > 2) {
        Serial.println("🔓 Pessoa detectada! Abrindo porta...");
        servoMotor.write(90); // Abre a porta (servo a 90 graus)
        lastActionTime = currentMillis; // Atualiza o tempo da última ação
        isDoorOpen = true;
    }

    // Verifica se a distância é consistentemente maior que o limiar para fechar a porta
    if (isDoorOpen && (distance > distanceThreshold) && (currentMillis - lastActionTime >= openDuration)) {
        Serial.println("🔒 Fechando porta...");
        servoMotor.write(0);  // Fecha a porta (servo de volta a 0 graus)
        isDoorOpen = false; // Atualiza o estado da porta
    }

    lastDistance = distance; // Armazena a distância atual para a comparação no próximo ciclo

    // Adicionando um delay de 1 segundo para evitar que as mensagens apareçam muito rápido
    delay(1000); // Espera 1 segundo entre as verificações e mensagens
}
