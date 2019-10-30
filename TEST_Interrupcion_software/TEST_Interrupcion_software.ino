#include <TimerOne.h>
int ledPin = 10;
int intSensorPin = 2;
volatile bool sensorStatus = false;
volatile bool ledStatus = false;

void setup()
{
  pinMode (ledPin, OUTPUT);
  pinMode(intSensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(intSensorPin), ISR_SENSOR, CHANGE);

  Timer1.initialize (500000);
  Timer1.attachInterrupt (ISR_BlinkLed);
}

void loop()
{
 if (sensorStatus && !ledStatus){
  digitalWrite(ledPin, LOW);
 }else{
  digitalWrite(ledPin, HIGH);
 } 
}

void ISR_BlinkLed (){
   if (sensorStatus){
    if (ledStatus){
      ledStatus = false;
    } else {
      ledStatus = true;
    }
   }
 }

void ISR_SENSOR (){
  if (digitalRead(2) == LOW)
  {
    sensorStatus = true;
  } else {
    sensorStatus = false;
  }
}
