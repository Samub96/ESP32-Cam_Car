#include "motor_control.h"
#include "camera_stream.h"
#include "web_server.h"
#include "flash_control.h"
#include "oled_display.h"

void setup() {
  Serial.begin(115200);
  //motores y flash
  setupMotors();
  setupFlash();

   //  OLED
  //initDisplay();
  //showMessage("Iniciando...", "");
  //Camara
  if (!setupCamera()) {
    Serial.println("Error al inicializar la cámara");
    while (true); // Detener
  }
  //servidor
  startWebServer();

  // 5. Muestra la IP en OLED
  //String ip = WiFi.localIP().toString();
  //howIP(ip);
  //Serial.printf("IP: %s\n", ip.c_str());
}

void loop() {
  handleWebServer();
}