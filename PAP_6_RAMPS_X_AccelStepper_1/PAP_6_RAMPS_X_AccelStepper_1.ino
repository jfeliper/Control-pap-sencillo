/*
  Arduino Day Zaragoza 2017
  Charla Factoria Maker
  Iniciación a los motores Paso a Paso
  Ejemplo para la maqueta PAP 6
  Control de motor bipolar mediante Arduino Mega y RAMPS.
  Cada pololu necesita tres señales: Enable, Dirección y Paso
  La señal Enable está activa con nivel bajo (LOW) y con HIGH se desactiva el motor
  Para generar los pulsos usamos la librería AccelStepper
  Cuando ha girado los pasos indicados le decimos que gire -pasos
*/

#include <AccelStepper.h>

// The X Stepper pins
// for the Arduino Mega + RAMPS 1.4
#define MOTOR_X_ENABLE_PIN 38
#define MOTOR_X_STEP_PIN 54
#define MOTOR_X_DIR_PIN 55

// Define a stepper and the pins it will use
// AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5
AccelStepper motorA(1, MOTOR_X_STEP_PIN, MOTOR_X_DIR_PIN);

void setup()
{
  motorA.setEnablePin(MOTOR_X_ENABLE_PIN);
  motorA.setPinsInverted(false, false, true);
  motorA.setAcceleration(10000);
  motorA.move(6400);
  motorA.setMaxSpeed(5000);
  //motorA.setSpeed(100);
  motorA.enableOutputs();
}

void loop()
{
  // If at the end of travel go to the other end
  if (motorA.distanceToGo() == 0)
    motorA.moveTo(-motorA.currentPosition());
  motorA.run();
}
