### ✅ Exercício 01 - Leitura de Temperatura e Umidade com DHT22

Projeto que utiliza um sensor **DHT22** para monitorar **temperatura e umidade** em tempo real, exibindo os dados no **monitor serial**.

**Componentes:**
- Sensor DHT22 (ou DHT11)
- Microcontrolador (ex: ESP32)
- Comunicação serial (115200 baud)

**Funcionalidades:**
- Leitura da temperatura (°C)
- Leitura da umidade (%)
- Tratamento de erro de leitura para garantir dados válidos

> 🧭 Ideal para aplicações de monitoramento ambiental, climatização e automação residencial.

---

### ✅ Exercício 02 - Alarme com Sensor de Movimento PIR e Buzzer

Sistema de **alarme simples** que detecta movimento usando um **sensor PIR** e aciona um **buzzer** como alarme sonoro.

**Componentes:**
- Sensor PIR
- Buzzer
- Microcontrolador

**Funcionalidades:**
- Detecção de movimento
- Ativação do buzzer por 1 segundo
- Mensagens no monitor serial

> 🚨 Útil para sistemas de segurança simples e alarmes de presença.

---

### ✅ Exercício 03 - Leitura de Aceleração com MPU6050

Sistema que realiza a leitura de aceleração nos eixos **X, Y e Z** utilizando o sensor **MPU6050**, com saída das informações no monitor serial.

**Componentes:**
- Sensor MPU6050 (acelerômetro + giroscópio)
- Microcontrolador (via comunicação I2C)

**Funcionalidades:**
- Leitura da aceleração nos 3 eixos
- Comunicação I2C
- Verificação da conexão com o sensor

> 📈 Pode ser usado para detectar movimento, inclinação ou impactos em projetos embarcados.

---

### ✅ Exercício 04 - Automação de Iluminação com LDR e Relé

Sistema que controla **automaticamente uma lâmpada** com base na **luminosidade** do ambiente, utilizando um sensor **LDR** e um **relé**.

**Componentes:**
- Sensor LDR (resistor dependente de luz)
- Módulo Relé
- Microcontrolador

**Funcionalidades:**
- Leitura do nível de luz ambiente
- Controle automático da lâmpada (liga/desliga)
- Saída de status no monitor serial

> 💡 Ideal para projetos de economia de energia e automação residencial noturna.

---

### ✅ Exercício 05 - Porta Automática com Sensor de Proximidade e Servo Motor

Sistema que simula uma **porta automática**, abrindo quando uma pessoa se aproxima e fechando após um tempo.

**Componentes:**
- Sensor Ultrassônico HC-SR04
- Servo motor
- Microcontrolador

**Funcionalidades:**
- Medição de distância em tempo real
- Abertura da porta ao detectar aproximação
- Fechamento automático após um tempo
- Lógica com controle de tempo e variação de distância

> 🚪 Útil para automatização de portas em locais com fluxo de pessoas.

---

### ✅ Exercício 06 - Monitoramento de Vagas de Estacionamento com Display

Sistema para monitorar **10 vagas de estacionamento** usando sensores **PIR** para indicar se uma vaga está **ocupada** ou **livre**, com exibição visual em um **display TFT colorido**.

**Componentes:**
- 10 sensores PIR
- Display TFT ILI9341 (SPI)
- Microcontrolador

**Funcionalidades:**
- Verificação individual do estado de cada vaga
- Exibição gráfica (vermelho para ocupado, verde para livre)
- Atualização periódica no display e no monitor serial

> 🅿️ Perfeito para simulações de sistemas de estacionamento inteligente.

---
