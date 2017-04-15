// Basic script for analog reading of pH probe

// Basic setup
void setup() {
  // Setting baud
  Serial.begin(9600);
}

// Basic loop for measuring pH
void loop() {
  // Math for pH measurment
  int sensorValue = analogRead(A5);
  double voltage = 5 / 1024.0 * sensorValue;
  float po = 7 + ((2.5 - voltage) / 0.18);
  int ph = po * 1000;
  // Outputting values
  Serial.print(sensorValue);
  Serial.print('\t');
  Serial.print(voltage, 3);
  Serial.print('\t');
  Serial.print(po, 3);
  Serial.print('\t');
  Serial.print(ph);
  Serial.println("");
  // Delay in milliseconds
  delay(100);
}
