/*03) Utilize um acelerômetro para identificar as velocidades de deslocamento nos 
eixos x, y e z.*/

#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
    Serial.begin(115200);
    Wire.begin();
    mpu.initialize();

    if (!mpu.testConnection()) {
        Serial.println("Falha ao conectar ao MPU6050!");
        while (1);
    }
}

void loop() {
    int16_t ax, ay, az;
    mpu.getAcceleration(&ax, &ay, &az);

    Serial.print("Aceleração X: "); Serial.print(ax);
    Serial.print(" | Y: "); Serial.print(ay);
    Serial.print(" | Z: "); Serial.println(az);

    delay(1000);
}
