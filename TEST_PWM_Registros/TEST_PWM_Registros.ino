
int potenciometerPin = A0;    // select the input pin for the potentiometer
int ledPin = 3;               // select the pin for the LED
int potenciometerValue = 0;   // variable to store the value coming from the potenciometer

void setup() {
pinMode(ledPin, OUTPUT);    // declare the ledPin as an OUTPUT
  TCCR2A = 0;
  TCCR2B = 0;

  TCCR2A |= ( 0 << COM2A1);
  TCCR2A |= ( 0 << COM2A0);
  TCCR2A |= ( 1 << COM2B1);
  TCCR2A |= ( 0 << COM2B0);
  TCCR2A |= ( 1 << WGM21);
  TCCR2A |= ( 1 << WGM20);
  
  TCCR2B |= (0 << FOC2A);
  TCCR2B |= (0 << FOC2B);
  TCCR2B |= (0 << WGM22);
  TCCR2B |= (0 << CS22); 
  TCCR2B |= (1 << CS21); 
  TCCR2B |= (0 << CS20); 
  
  TCNT2  = 0;
  OCR2A = 0;
}

void loop() {
  potenciometerValue = analogRead(potenciometerPin);   // read the value from the sensor
  OCR2A = potenciometerValue/4;
}
