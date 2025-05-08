#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h> // Librería específica para SH1106G

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1       // SH1106 no necesita reset físico
#define SCREEN_ADDRESS 0x3C    // Dirección I2C usual

#define OLED_SDA 16
#define OLED_SCL 2
#define WHITE 1

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bool displayReady = false;

void initDisplay() {
  Wire.begin(OLED_SDA, OLED_SCL);

  if (!display.begin(SCREEN_ADDRESS)) {
    Serial.println(F("❌ OLED SH1106G no detectada"));
    displayReady = false;
    return;
  }

  displayReady = true;
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(F("OLED iniciada"));
  display.display();
}

void showMessage(const String& line1, const String& line2 = "") {
  if (!displayReady) return;

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(line1);
  if (!line2.isEmpty()) {
    display.setCursor(0, 16);
    display.println(line2);
  }
  display.display();
}

void showIP(const String& ip) {
  if (!displayReady) return;

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(F("IP asignada:"));
  display.setTextSize(2);
  display.setCursor(0, 16);
  display.println(ip);
  display.display();
}

#endif
