
/*
  Arduino Day Zaragoza 2017
  Charla Factoria Maker
  Iniciación a los motores Paso a Paso
  Ejemplo para la maqueta PAP 1
  Un motor unipolar de 12V y 48 pasos por vuelta
  utiliza la librería Stepper que ya viene en el IDE arduino
*/

#include <Stepper.h>

const int stepsPerRevolution = 48;  // pasos por vuelta

// inicializa la librería stepper con los pines 4-7
Stepper motor(stepsPerRevolution, 4, 6, 5, 7);

void setup() {
  motor.setSpeed(10);
}

void loop() {
  motor.setSpeed(10);
  motor.step(stepsPerRevolution);
  delay(500);

  motor.setSpeed(3);
  motor.step(-stepsPerRevolution);
  delay(500);
}

