#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
int pirPin = 2;
int personas = 0;
int estadoAnterior = LOW;
 
void setup() {
  pinMode(pirPin, INPUT);
 
  lcd.init();
  lcd.backlight();
 
  Serial.begin(9600); // iniciar comunicación serial
 
  lcd.setCursor(0, 0);
  lcd.print("Personas: 0");
 
  Serial.println("Sistema iniciado...");
}
 
void loop() {
  int estadoActual = digitalRead(pirPin);
 
  // Detecta cambio de LOW a HIGH
  if (estadoActual == HIGH && estadoAnterior == LOW) {
    personas++;
 
    // LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Personas: ");
    lcd.print(personas);
 
    // SERIAL (ALERTA)
    Serial.print("Persona detectada! Total: ");
    Serial.println(personas);
 
    delay(1000); // evita múltiples conteos
  }
 
  estadoAnterior = estadoActual;
}