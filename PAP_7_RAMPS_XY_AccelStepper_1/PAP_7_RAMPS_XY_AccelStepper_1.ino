/*
  Arduino Day Zaragoza 2017
  Charla Factoria Maker
  Iniciación a los motores Paso a Paso
  Ejemplo para la maqueta PAP 7
  Control de 2 motores bipolares de DVD mediante Arduino Mega y RAMPS.
  Cada pololu necesita tres señales: Enable, Dirección y Paso
  La señal Enable está activa con nivel bajo (LOW) y con HIGH se desactiva el motor
  Para generar los pulsos usamos la librería AccelStepper
  Cuando ha girado los pasos indicados le decimos que gire -pasos
*/
#include <AccelStepper.h>

// for the Arduino Mega + RAMPS 1.4
#define MOTOR_X_ENABLE_PIN 38
#define MOTOR_X_STEP_PIN 54
#define MOTOR_X_DIR_PIN 55

#define MOTOR_Y_ENABLE_PIN A2
#define MOTOR_Y_STEP_PIN A6
#define MOTOR_Y_DIR_PIN A7

// Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper motorX(1, MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);
AccelStepper motorY(1, MOTOR_Y_STEP_PIN, MOTOR_Y_DIR_PIN);

void setup()
{
  motorX.setEnablePin(MOTOR_X_ENABLE_PIN);
  motorX.setPinsInverted(false, false, true);
  motorX.setAcceleration(2000);
  motorX.move(3200);
  motorX.setMaxSpeed(10000);
  motorX.enableOutputs();

  motorY.setEnablePin(MOTOR_Y_ENABLE_PIN);
  motorY.setPinsInverted(false, false, true);
  motorY.setAcceleration(30000);
  motorY.move(3200);
  motorY.setMaxSpeed(30000);
  motorY.enableOutputs();
}

void loop()
{
  // Cuando el motor X llega a un extremo, invierte el sentido
  if (motorX.distanceToGo() == 0)
    motorX.moveTo(-motorX.currentPosition());
  motorX.run();

  // Cuando el motor Y llega a un extremo, invierte el sentido
  if (motorY.distanceToGo() == 0)
    motorY.moveTo(-motorY.currentPosition());
  motorY.run();
}
