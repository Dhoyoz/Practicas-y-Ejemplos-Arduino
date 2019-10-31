#define termistorPin A0
#define termistorNominalRes 100000
#define termistorNominalTemp 25
#define termistorBValue 3950
#define VoltageDividerResistor 100000
float termistorRes = 0.0;
float steinhart;
void setup() {
    Serial.begin(115200);
    analogReference(EXTERNAL);
}

void loop() {
  termistorRes = 10.23/(1023-analogRead (termistorPin));
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
