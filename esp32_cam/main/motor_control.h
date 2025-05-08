#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

// Pines para control de motores (puente H tipo L298N)
#define IN1 14
#define IN2 15
#define IN3 13
#define IN4 12

void stopMotors();
// Inicialización de pines
void setupMotors() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  stopMotors();
}

// Función auxiliar para reducir redundancia
void setMotor(bool in1, bool in2, bool in3, bool in4) {
  digitalWrite(IN1, in1);
  digitalWrite(IN2, in2);
  digitalWrite(IN3, in3);
  digitalWrite(IN4, in4);
}

// Detener todos los motores
void stopMotors() {
  setMotor(LOW, LOW, LOW, LOW);
}

// Avanzar
void moveForward() {
  setMotor(HIGH, LOW, HIGH, LOW);
}

// Retroceder
void moveBackward() {
  setMotor(LOW, HIGH, LOW, HIGH);
}

// Girar a la izquierda
void turnLeft() {
  setMotor(LOW, HIGH, HIGH, LOW);
}

// Girar a la derecha
void turnRight() {
  setMotor(HIGH, LOW, LOW, HIGH);
}

#endif
