// declaring variables
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;
const int ledPin = 13;

void setup() {
  // put your setup code here, to run once:

  // using onboard led (pin 13) for calibration indicator
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // while loop for calibration
  while (millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
  // turn onboard LED off after calibration
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(A0);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 5000);
  tone(8, pitch, 200);
  delay(20);
}
