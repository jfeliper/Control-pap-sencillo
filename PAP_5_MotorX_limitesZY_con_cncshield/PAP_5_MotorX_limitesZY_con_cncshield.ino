/*
  Arduino Day Zaragoza 2017
  Charla Factoria Maker
  Iniciación a los motores Paso a Paso
  Ejemplo para la maqueta PAP 5
  Control de motor bipolar mediante Arduino Uno y cncshield.
  El pololu necesita tres señales de control: Enable, Dirección y Paso
  El pololu se controla con las señales Dir_Pin_X (pata 5) y Step_Pin_X (pata 2)
  La señal Enable está activa con nivel bajo (LOW) y con HIGH se desactiva el motor
  Este programa genera una serie de pulsos en la salida Step_Pin_X (Hay que ponerlo a 1, esperar un tiempo, ponerlo a 0)
  Cuando ha mandado un número de pulsos, cambia la dirección
  Los finales de carrera usan un interruptor NO entre el pin y GND y usan la resistencia de pull-up interna.
  Se pueden comprobar con el ejemplo Digital>DigitalInputPullUp
  Conectamos los dos finales de carrera en limitX y LimitY para facilitar el programa.
  Comienza con dirección LOW, hacia el final de carrera Y
  Cuando toca el final de carrera (limitY=LOW) cambia la dirección a HIGH y el motor se mueve hacia el final de carrera X
  Cuando llega al final de carrera (limitX=LOW) cambia la dirección a LOW y vuelve a empezar el ciclo*/

int retardo = 1;  // Duración del pulso
int EnPin = 8;     // Señal de enable de los 4 pololus al pin 8
int Dir_Pin_X = 5; // Señal de dirección del motor X al pin 5
int Step_Pin_X = 2;  // Señal de paso del motor X al pin 2
int limitX = 9;   //Final de carrera
int limitY = 10;
bool Dir_estado = LOW;   // Para cambiar de dirección
int contador = 0; // cuenta los pasos
void setup() {
  Serial.begin(9600);
  pinMode(EnPin, OUTPUT);        // Define el pin como salida
  pinMode(Dir_Pin_X, OUTPUT);    // Define el pin como salida
  pinMode(Step_Pin_X, OUTPUT);     // Define el pin como salida
  pinMode(limitX, INPUT_PULLUP);  // Activa pull-up interna
  pinMode(limitY, INPUT_PULLUP); // Activa pull-up interna
  digitalWrite(EnPin, LOW);      // Activa con nivel bajo
  digitalWrite(Dir_Pin_X, Dir_estado);   // Saca  Dir
}

void loop() {                    // Paso:  un 1 y luego un 0
  int sensorValY = digitalRead(limitY); // Lee final de carrera
  int sensorValX = digitalRead(limitX);
  digitalWrite(Step_Pin_X, HIGH);  // Activa el pin de Paso
  delay(retardo);                     // Espera un poco
  digitalWrite(Step_Pin_X, LOW);   // Desactiva el pin de Paso
  delay(retardo);                     // Espera un poco
  contador = contador + 1;
  // Si lee LOW es porque el final de carrera está pulsado
  if (sensorValX == LOW) {
    if (contador > 10) Serial.println(contador);
    Dir_estado = LOW;
    contador = 0;
  }
  // Si lee LOW es porque el final de carrera está pulsado
  if (sensorValY == LOW) {
    if (contador > 10) Serial.println(contador);
    Dir_estado = HIGH;
    contador = 0;
  }
  digitalWrite(Dir_Pin_X, Dir_estado);    // Saca  Dir
}
