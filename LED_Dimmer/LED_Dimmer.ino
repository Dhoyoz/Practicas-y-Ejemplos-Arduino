
int potenciometerPin = A0;    // select the input pin for the potentiometer
int ledPin = 3;               // select the pin for the LED
int potenciometerValue = 0;   // variable to store the value coming from the potenciometer

void setup() {
  
  pinMode(ledPin, OUTPUT);    // declare the ledPin as an OUTPUT:
}

void loop() {
 
  potenciometerValue = analogRead(potenciometerPin);   // read the value from the sensor
  analogWrite(ledPin, potenciometerValue / 4);          // Set PWM dutyCicle acording Potenciometer

}
