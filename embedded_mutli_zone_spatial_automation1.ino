#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configured for I2C hex address 0x20
LiquidCrystal_I2C lcd(0x20, 16, 2); 

const int SENSOR_ZONE_A = 4;    
const int SENSOR_ZONE_B = 5;    
const int RELAY_PIN = 12;       
const int AUX_APPLIANCE_PIN = 11; 
const int STATUS_LED_PIN = 13;  

void setup() {
  pinMode(SENSOR_ZONE_A, INPUT);
  pinMode(SENSOR_ZONE_B, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(AUX_APPLIANCE_PIN, OUTPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(AUX_APPLIANCE_PIN, LOW);
  digitalWrite(STATUS_LED_PIN, LOW);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  int zoneA = digitalRead(SENSOR_ZONE_A);
  int zoneB = digitalRead(SENSOR_ZONE_B);

  if (zoneA == HIGH || zoneB == HIGH) {
    digitalWrite(RELAY_PIN, HIGH);         
    digitalWrite(AUX_APPLIANCE_PIN, HIGH);  
    digitalWrite(STATUS_LED_PIN, HIGH);     

    // Simple, direct text with "APPLIANCES"
    lcd.setCursor(0, 0);
    lcd.print("MOTION DETECTED ");
    lcd.setCursor(0, 1);
    lcd.print("APPLIANCES: ON  ");
  } else {
    digitalWrite(RELAY_PIN, LOW);          
    digitalWrite(AUX_APPLIANCE_PIN, LOW);   
    digitalWrite(STATUS_LED_PIN, LOW);      

    // Simple, direct text with "APPLIANCES"
    lcd.setCursor(0, 0);
    lcd.print("ROOM IS EMPTY   ");
    lcd.setCursor(0, 1);
    lcd.print("APPLIANCES: OFF ");
  }
  
  delay(50); 
}