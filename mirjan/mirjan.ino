int ph_pin = A5; //This is the pin number connected to Po
float Po;
int pH;

void setup() {
  Serial.begin(9600);
}

void loop() {
  measure_ph();
  Serial.print("Ph je: ");
  Serial.println(pH);
  delay(2000);
}

void measure_ph() {
  int measure = analogRead(ph_pin);
  Serial.print("Measure: ");
  Serial.print(measure);
  double voltage = 5 / 1024.0 * measure; //classic digital to voltage conversion
  Serial.print("\tVoltage: ");
  Serial.print(voltage, 3);
  // PH_step = (voltage@PH7 - voltage@PH4) / (PH7 - PH4)
  // PH_probe = PH7 - ((voltage@PH7 - voltage@probe) / PH_step)
  Po = 7 + ((2.5 - voltage) / 0.18);
  pH = Po*1000;
  Serial.print("\tPH: ");
  Serial.print(Po, 3);
  Serial.println("");
}

