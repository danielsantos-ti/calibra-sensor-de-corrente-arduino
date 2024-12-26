# Medição de Corrente com Sensor Analógico

Este projeto utiliza um microcontrolador para medir a corrente elétrica através de um sensor analógico conectado ao pino A5 e controlar um relé conectado ao pino digital 5. A medição de corrente é calculada a partir do valor analógico lido, considerando um fator de sensibilidade e um offset inicial.

## 🚀 Funcionalidades

- **Calibração de Offset**: Lê o valor do sensor quando não há corrente para compensar desvios.
- **Medição de Corrente**: Calcula a corrente elétrica em amperes usando os dados do sensor.
- **Controle de Relé**: Liga e desliga o relé periodicamente para simular um ciclo de ativação.

---

## 📋 Requisitos

- **Microcontrolador compatível com Arduino**.
- **Sensor de corrente analógico ACS712 30A** conectado ao pino A5.
- **Relé** conectado ao pino digital 5.
- **Software Arduino IDE** para upload do código.

---

## 🔧 Configuração do Circuito

1. Conecte o **sensor de corrente** ao pino analógico A5 e ao GND.
2. Conecte o **relé** ao pino digital 5 e ao GND.
3. Certifique-se de que o sensor de corrente e o relé estão adequadamente alimentados.

---

## 💻 Código

### **Setup**
No `setup()`, o código:
- Define os pinos do relé e do sensor.
- Realiza a calibração do offset do sensor.
- Configura o monitor serial para exibir os resultados.

### **Loop**
No `loop()`, o código:
1. Ativa o relé.
2. Lê o valor do sensor.
3. Calcula a corrente elétrica com base no valor lido.
4. Exibe o valor da corrente no monitor serial.
5. Desliga o relé e aguarda um tempo.

---

## 📌 Fatores Importantes

- **Sensibilidade do Sensor**: Definido pela constante `sensibilidade`, que neste caso é `0.066`.
- **Offset Inicial**: Calculado no início para ajustar os valores lidos quando não há corrente.

---

## 🖥️ Saída do Monitor Serial

- **Offset calibrado**: Exibe o valor inicial de referência para compensar desvios.
- **Corrente medida**: Mostra o valor da corrente elétrica em amperes.

---

## 📜 Exemplo de Saída

```plaintext
Offset calibrado: 512
Corrente medida: 0.15 A
Corrente medida: 0.12 A
Corrente medida: 0.10 A
