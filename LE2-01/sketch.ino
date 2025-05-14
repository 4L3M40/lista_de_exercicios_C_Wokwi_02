/*01) Utilize um sensor de temperatura (como o DHT11 ou DHT22) para monitorar a 
temperatura em tempo real apresentando a temperatura e umidade na saída serial.*/

#include <DHT.h>

#define DHTPIN 4       // Pino de dados do sensor conectado ao GPIO4
#define DHTTYPE DHT22  // Tipo do sensor (DHT11 ou DHT22)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    dht.begin();
    delay(5000); // Aguarde 5 segundos para inicialização
}


void loop() {
    float temperatura = dht.readTemperature();
    float umidade = dht.readHumidity();

    if (isnan(temperatura) || isnan(umidade)) {
        Serial.println("Erro ao ler o sensor!");
        return;
    }

    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print("°C  |  Umidade: ");
    Serial.print(umidade);
    Serial.println("%");

    delay(2000); // Atualiza a leitura a cada 2 segundos
}
