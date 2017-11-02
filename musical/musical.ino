// declaring variables
int potOne;
int wait[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 500, 1000};
int i = 3;
int waitUp = 0;
int waitDown = 0;
int pitch;
const int ledPin = 7;
const int pinPotOne = A2;
const int pinButOne = 4;
const int pinButTwo = 8;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // if everything is normal LED shouldn't be ON
  digitalWrite(ledPin, LOW);

  //check if buttons are being pressed
  waitUp = digitalRead(pinButTwo); 
  waitDown = digitalRead(pinButOne);

  if(waitUp == HIGH && waitDown == LOW && i<11) {
    i += 1;
  }
  else if(waitUp == HIGH && waitDown == LOW && i == 11) {
    digitalWrite(ledPin, HIGH);
  }
  else if(waitUp == LOW && waitDown == HIGH && i > 0) {
    i -= 1;
  }
  else if(waitUp == LOW && waitDown == HIGH && i == 0) {
    digitalWrite(ledPin, HIGH);
  }
  else if(waitUp == HIGH && waitDown == HIGH) {
    i = 3;
    digitalWrite(ledPin, HIGH);
  }

  delay(10);
  potOne = analogRead(pinPotOne);
  int pitch = map(potOne, 0, 1023, 20, 3000);
  Serial.println("potOne, pitch, wait");
  Serial.print(potOne);
  Serial.print(", ");
  Serial.print(pitch);
  Serial.print(", ");
  Serial.println(wait[i]);
  tone(12, pitch, wait[i]);
  delay(wait[i]);
}
