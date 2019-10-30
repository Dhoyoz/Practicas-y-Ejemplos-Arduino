int ledPin = 10;
int intSensorPin = 2;
volatile bool sensorStatus = false;

void setup()
{
  pinMode (ledPin, OUTPUT);
  pinMode(intSensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(intSensorPin), ISR_SENSOR, CHANGE);
}

void loop()
{
 if (sensorStatus){
  digitalWrite(ledPin, LOW);
 }else{
  digitalWrite(ledPin, HIGH);
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
