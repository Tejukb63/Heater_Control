#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

//here i  am defining the sensor setup

#define DHTPIN 2
#define DHTTYPE DHT22
uint8_t heater = 8; ///hERE I USED LED as a heating device,when condition meets led will glow up to heat the room
uint8_t buzzer = 7;


DHT dht(DHTPIN,DHTTYPE);
LiquidCrystal_I2C lcd(0x27,16,2);

enum state{
  Idle, Heating, Stabilizing, Target_Reached, Overheat
};

state condition=Idle;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  dht.begin();
  lcd.backlight();
  pinMode(heater, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = dht.readTemperature();

  if(temp<25){
    condition = Heating;
  }
  else if(temp>=25 && temp<28){
    condition= Stabilizing;
  }
  else if(temp>=28 && temp<30){
    condition = Target_Reached;
  }
  else if(temp>=30){
    condition = Overheat;
  }
  else{
    condition = Idle;
  }


  switch(condition){
    case Heating:
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, LOW);
      break;
    
    case Overheat:
      digitalWrite(heater, LOW);
      digitalWrite(buzzer, HIGH);
      break;
    
    default:
      digitalWrite(heater, LOW);
      digitalWrite(buzzer, LOW);
  }
 
  Serial.print("Temp: "); Serial.print(temp);
  Serial.print(" C | State: ");
  printState(condition);

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223); // Degree symbol
  lcd.print("C   ");    // Spaces to clear extra chars

  lcd.setCursor(0, 1);
  lcd.print("State: ");
  lcd.print(getStateName(condition));
  lcd.print("   ");     // Clear extra chars

  delay(2000);
}

void printState(state s) {
  Serial.println(getStateName(s));
}

String getStateName(state s) {
  switch (s) {
    case Idle: return "Idle";
    case Heating: return "Heating";
    case Stabilizing: return "Stabilizing";
    case Target_Reached: return "Target OK";
    case Overheat: return "Overheat";
  }
  return "";
}

