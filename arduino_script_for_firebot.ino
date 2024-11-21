#include <Arduino.h>

#define PIN_FIRE A0
#define PIN_TEMP A1
#define PIN_GAS A2
#define PIN_LIGHT 3
#define PIN_SOUND 4
int raw = 0;
float temp = 0;

void setup(){
  Serial.begin(9600);
  pinMode(PIN_LIGHT,OUTPUT);
  pinMode(PIN_SOUND,OUTPUT);
  pinMode(1,OUTPUT);
}

void loop(){
  raw = analogRead(PIN_TEMP);
  float temperature = ( raw/1023.0 )*5.0*1000/10;
  Serial.print("Огня: ");
  Serial.print(analogRead(PIN_FIRE));
  Serial.print("  Газа: ");
  Serial.print(analogRead(PIN_GAS));
  Serial.print("  Температура: ");
  Serial.println(temperature);  
  if(analogRead(PIN_FIRE) < 650 && temperature >=40 || analogRead(PIN_GAS) > 100){
  //if(temperature>=30){
    analogWrite(A3,200);
    tone(PIN_SOUND, 440);
    digitalWrite(PIN_LIGHT, HIGH);x
    delay(200);
    noTone(PIN_SOUND);
    digitalWrite(PIN_LIGHT, LOW);
    delay(200);
  }
  delay(1000);
  }