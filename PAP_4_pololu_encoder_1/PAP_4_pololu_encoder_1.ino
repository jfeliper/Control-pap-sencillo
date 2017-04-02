/*
  Arduino Day Zaragoza 2017
  Charla Factoria Maker
  Iniciación a los motores Paso a Paso
  Ejemplo para la maqueta PAP 4
  Control de motor bipolar mediante pololu. Placa con interruptores
  El pololu necesita tres señales de control: Enable, Dirección y Paso
  Usamos las mismas direcciones que la cncshield con Arduino Uno
  El pololu se controla con las señales Dir_Pin_X (pata 5) y Step_Pin_X (pata 2)
  La señal Enable está activa con nivel bajo (LOW) y con HIGH se desactiva el motor
*/

int EnPin = 8;     // cncshiel conecta la señal de enable de los 4 pololus al pin 8
int Dir_Pin_X = 5; // cncshiel conecta la señal de dirección del motor X al pin 5
int Step_Pin_X = 2;  // cncshiel conecta la señal de paso del motor X al pin 2

bool Dir_estado = LOW;   // Esta variable sirve para cambiar de dirección
int contador = 0;
void setup() {
  pinMode(EnPin, OUTPUT);        // Define el pin como salida
  pinMode(Dir_Pin_X, OUTPUT);    // Define el pin como salida
  pinMode(Step_Pin_X, OUTPUT);     // Define el pin como salida

  digitalWrite(EnPin, LOW);      // El pololu se activa con nivel bajo
  digitalWrite(Dir_Pin_X, Dir_estado);   // Saca por la pata de dircción el estado inicial
}

void loop() {                    // Para mandar un paso tenemos que mandar un 1 y luego un 0
  digitalWrite(Step_Pin_X, HIGH);  // Activa el pin de Paso
  delay(2);                     // Espera un poco
  digitalWrite(Step_Pin_X, LOW);   // Desactiva el pin de Paso
  delay(2);                     // Espera un poco
  contador = contador + 1;
  if (contador == 200) {
    Dir_estado = !Dir_estado;    // Invierte la direccion
    contador = 0;                // Reinicia el contador para hacer otros pasos en dirección contraria
    digitalWrite(Dir_Pin_X, Dir_estado);    // Saca por el pin de dirección el estado de la dirección
  }
}
