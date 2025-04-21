#include "motor_control.h"
#include "camera_stream.h"
#include "web_server.h"
#include "flash_control.h"

void setup() {
  Serial.begin(115200);

  setupMotors();
  setupFlash();

  if (!setupCamera()) {
    Serial.println("Error al inicializar la cámara");
    while (true); // Detener
  }

  startWebServer();
}

void loop() {
  handleWebServer();
}
