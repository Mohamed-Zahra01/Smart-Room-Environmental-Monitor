#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int tempPin = A0;
int lightPin = A1;

int led1 = 8;
int led2 = 9;
int fanPin = 10;

float smoothTemp = 25.0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(fanPin, OUTPUT);
}

void loop() {
  // ===== Read Temperature =====
  int tempValue = analogRead(tempPin);
  float tempC = tempValue * 0.488;

  smoothTemp = (smoothTemp * 0.85) + (tempC * 0.15);

  // ===== Read Light =====
  int lightValue = analogRead(lightPin);

  String lightStatus;
  int ledCount = 0;

  if (lightValue > 130) {
    lightStatus = "BRIGHT";
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    ledCount = 0;
  } 
  else if (lightValue > 33) {
    lightStatus = "NORMAL LIGHT";
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    ledCount = 1;
  } 
  else {
    lightStatus = "DARK";
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    ledCount = 2;
  }

  // ===== Fan Speed Logic =====
  int fanSpeed;

  if (smoothTemp <= 10) {
    fanSpeed = 0;
  } 
  else if (smoothTemp >= 28) {
    fanSpeed = 255;
  } 
  else {
    fanSpeed = map((int)smoothTemp, 10, 28, 80, 255);
  }

  analogWrite(fanPin, fanSpeed);

  int fanPercent = map(fanSpeed, 0, 255, 0, 100);

  // ===== Temperature Status =====
  String tempStatus;

  if (smoothTemp < 12) {
    tempStatus = "COLD";
  } 
  else if (smoothTemp < 28) {
    tempStatus = "WARM";
  } 
  else {
    tempStatus = "HOT";
  }

  // ===== Page 1: Sensor Values =====
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(smoothTemp, 1);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Light:");
  lcd.print(lightValue);
  lcd.print(" ");
  lcd.print(lightStatus);

  delay(2000);

  // ===== Page 2: Output Actions =====
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fan Speed:");
  lcd.print(fanPercent);
  lcd.print("%");

  lcd.setCursor(0, 1);
  lcd.print("LEDs:");
  lcd.print(ledCount);
  lcd.print(" ON");

  delay(2000);

  // ===== Page 3: Smart Status =====
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Room Status:");

  lcd.setCursor(0, 1);
  lcd.print(tempStatus);
  lcd.print("+");
  lcd.print(lightStatus);

  delay(2000);
}
