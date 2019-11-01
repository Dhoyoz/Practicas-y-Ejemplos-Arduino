#define termistorPin A1
#define termistorNominalRes 100000
#define termistorNominalTemp 25
#define termistorBValue 3950
#define VoltageDividerResistor 110000
float termistorRes = 0.0;
float steinhart;
void setup() {
    Serial.begin(9600);
    analogReference(EXTERNAL);
}

void loop() {
  
  termistorRes = ((float)analogRead (termistorPin)* VoltageDividerResistor)/(1023 - (float)analogRead (termistorPin));
  steinhart = termistorRes / termistorNominalRes;     // (R/Ro)
  steinhart = log(steinhart);                         // ln(R/Ro)
  steinhart /= termistorBValue;                       // 1/B * ln(R/Ro)
  steinhart += 1.0 / (termistorNominalTemp + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                        // Invert  
  steinhart -= 273.15;                                // convert to C
  Serial.print("Temperature "); 
  Serial.print(steinhart);
  Serial.println(" *C");
  delay(1000);
}
