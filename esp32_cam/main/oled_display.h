#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106G.h>    // Cabecera correcta para SH1106G

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1         // Sin pin de reset físico
#define SCREEN_ADDRESS 0x3C      // Dirección I2C habitual para SH1106

// Pines I2C 
#define OLED_SDA 14   
#define OLED_SCL 15  

// Instancia del display SH1106G
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initDisplay() {
  // Inicializa I2C en los pines indicados
  Wire.begin(OLED_SDA, OLED_SCL);

  // Inicia la pantalla SH1106G
  if (!display.begin(SCREEN_ADDRESS)) {
    Serial.println(F("❌ No se detectó pantalla OLED SH1106G"));
    return;
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(F("OLED lista!"));
  display.display();
}

void showIP(const String& ip) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("IP Asignada:"));
  display.setTextSize(2);
  display.setCursor(0, 16);
  display.println(ip);
  display.display();
}

#endif
