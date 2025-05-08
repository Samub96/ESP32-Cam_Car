#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <WiFi.h>
#include <WebServer.h>
#include "esp_camera.h"
#include "motor_control.h"
#include "flash_control.h"

// Credenciales Wi‑Fi
const char* ssid = "samu";
const char* password = "telematica";

// Servidores en puertos distintos: 80 para comandos, 81 para stream
WebServer server(80);
WebServer streamServer(81);

// === Stream de la cámara (NO bloqueante) ===
void handleStream() {
  WiFiClient client = streamServer.client();

  String response = "HTTP/1.1 200 OK\r\n";
  response += "Content-Type: multipart/x-mixed-replace; boundary=frame\r\n\r\n";
  client.print(response);

  while (client.connected()) {
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) continue;

    client.printf("--frame\r\nContent-Type: image/jpeg\r\nContent-Length: %u\r\n\r\n", fb->len);
    client.write(fb->buf, fb->len);
    client.print("\r\n");

    esp_camera_fb_return(fb);
    delay(100);  // Ajusta según fluidez y carga de CPU

    // Permitir atender otras peticiones
    server.handleClient();
    streamServer.handleClient();
  }
}

// === Control de movimiento ===
void handleControl() {
  String command = server.arg("action");

  if (command == "forward") moveForward();
  else if (command == "backward") moveBackward();
  else if (command == "left") turnLeft();
  else if (command == "right") turnRight();
  else stopMotors();

  server.send(200, "text/plain", "OK");
}

// === Control del flash ===
void handleFlash() {
  String state = server.arg("state");
  if (state == "on") flashOn();
  else flashOff();
  server.send(200, "text/plain", "Flash actualizado");
}

// === Arranque WiFi y servidores web ===
void startWebServer() {
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");

  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - startTime < 10000) {
    Serial.print(".");
    delay(500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ Conectado:");
    Serial.print("IP comandos: "); Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n❌ No se pudo conectar.");
    return;
  }

  // Servidor de comandos
  server.on("/move", HTTP_GET, handleControl);
  server.on("/flash", HTTP_GET, handleFlash);
  server.begin();

  // Servidor de stream
  Serial.print("Iniciando stream en: http://");
  Serial.print(WiFi.localIP());
  Serial.println(":81/stream");
  streamServer.on("/stream", HTTP_GET, handleStream);
  streamServer.begin();
}

// === Loop para atender ambos servidores ===
void handleWebServer() {
  server.handleClient();
  streamServer.handleClient();
}

#endif // WEB_SERVER_H
