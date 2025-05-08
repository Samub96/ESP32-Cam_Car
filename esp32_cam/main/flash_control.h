#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#define FLASH_LED_PIN 4  // Flash de la ESP32-CAM

void setupFlash() {
  pinMode(FLASH_LED_PIN, OUTPUT);
  digitalWrite(FLASH_LED_PIN, LOW);
}

void flashOn() {
  digitalWrite(FLASH_LED_PIN, HIGH);
}

void flashOff() {
  digitalWrite(FLASH_LED_PIN, LOW);
}

#endif