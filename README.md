# 💻 Exercícios de Programação com Sensores (C/C++ no Wokwi)

Este repositório contém 6 exercícios desenvolvidos na plataforma [Wokwi](https://wokwi.com/) utilizando a linguagem C/C++ com foco em **sistemas embarcados**, **automação** e **IoT**. Os projetos utilizam diversos sensores e atuadores conectados a microcontroladores como o ESP32 ou Arduino.

---

## ✅ Exercício 01 - Leitura de Temperatura e Umidade com DHT22

Projeto que utiliza um sensor **DHT22** para monitorar **temperatura e umidade** em tempo real, exibindo os dados no **monitor serial**.

**Componentes:**
- Sensor DHT22 (ou DHT11)
- Microcontrolador (ex: ESP32)
- Comunicação serial (115200 baud)

**Funcionalidades:**
- Leitura da temperatura (°C)
- Leitura da umidade (%)
- Tratamento de erro de leitura

```cpp
float temperatura = dht.readTemperature();
float umidade = dht.readHumidity();
