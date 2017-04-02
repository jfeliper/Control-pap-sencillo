/*
  Arduino Day Zaragoza 2017
  Charla Factoria Maker
  Iniciación a los motores Paso a Paso
  Ejemplo para la maqueta PAP 2
  Dos motores unipolares de 5V con reductor, para azimut y cenit
  utiliza la librería Stepper que ya viene en el IDE arduino
*/

#include <Stepper.h>

const int stepsPerRevolution = 1000;

Stepper cenit(stepsPerRevolution, 8, 10, 9, 11);
Stepper acimut(stepsPerRevolution, 4, 6, 5, 7);

void setup() {
  cenit.setSpeed(20);
  acimut.setSpeed(20);
}

void loop() {
  cenit.step(stepsPerRevolution);
  delay(500);
  acimut.step(stepsPerRevolution);
  delay(500);

  cenit.step(-stepsPerRevolution);
  delay(500);
  acimut.step(-stepsPerRevolution);
  delay(500);
}

