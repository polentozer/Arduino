// importing servo library
#include <Servo.h>

// declaring variables and constants
Servo myServo;  // now myServo is a Servo object
int const potPin = A0;
int potVal;
int angle;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  angle = map(potVal, 0, 1023, 0, 170);
  Serial.print(", angle: ");
  Serial.println(angle);
  myServo.write(angle);
  delay(15);
}
