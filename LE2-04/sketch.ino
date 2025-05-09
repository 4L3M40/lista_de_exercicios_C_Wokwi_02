/*04) Use um sensor de luz (LDR) para medir a luminosidade do ambiente e um 
atuador (rele ou transistor) para controlar automaticamente uma lâmpada.*/

#define LDR_PIN 34     // Pino analógico onde o LDR está conectado
#define RELE_PIN 26    // Pino de controle do relé

void setup() {
    Serial.begin(115200);
    pinMode(RELE_PIN, OUTPUT);
}

void loop() {
    int valorLDR = analogRead(LDR_PIN); // Lê o valor do sensor
    Serial.print("Luminosidade: ");
    Serial.println(valorLDR);
    
    // Definir um limite para acionar a lâmpada
    if (valorLDR < 2000) {  // Quanto menor, mais escuro
        digitalWrite(RELE_PIN, HIGH); // Liga a lâmpada
        Serial.println("Lâmpada Ligada!");
    } else {
        digitalWrite(RELE_PIN, LOW); // Desliga a lâmpada
        Serial.println("Lâmpada Desligada!");
    }
    
    delay(1000); // Atualiza a cada 1 segundo
}
