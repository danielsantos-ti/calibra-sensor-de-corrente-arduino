#include <Arduino.h>

const int relePin = 5;
const int sensorPin = A5;
float sensibilidade = 0.066;
float offset;


void setup() {

  pinMode(relePin, OUTPUT);
  pinMode(sensorPin, INPUT);
  
  digitalWrite(relePin, LOW);

  Serial.begin(9600);

  //calibrar o offset (ler quando não há corrente)
  offset = analogRead(sensorPin);
  Serial.print("Offset calibrado: ");
  Serial.println(offset);

}

void loop() {
    
  digitalWrite(relePin, HIGH);
  delay(500);

  int valorDoSensor = analogRead(sensorPin);

  float corrente = ((valorDoSensor - offset) * 5.0 / 1024.0) / sensibilidade;

  //float voltagem = valorDoSensor * (5.0 / 1024.0);
  //float corrente = (voltagem - 2.5) / 0.066;

  Serial.print("Corrente medida: ");
  Serial.print(corrente);
  Serial.println(" A");

  delay(500);

  digitalWrite(relePin, LOW);
  delay(500);
  
}
