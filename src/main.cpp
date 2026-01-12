#include <Arduino.h>

const int analogPin = D2; 

void setup() {
  Serial.begin(115200);
  delay(1000);

  analogReadResolution(12);               // 12-bit: 0–4095
  analogSetPinAttenuation(analogPin, ADC_11db);
  // ADC_11db ≈ 0–3.3V
}

void loop() {
  int adcValue = analogRead(analogPin);

  float voltage = (adcValue / 4095.0) * 3.3;

  Serial.print("ADC Value: ");
  Serial.print(adcValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 3);
  Serial.println(" V");

  delay(500);
}