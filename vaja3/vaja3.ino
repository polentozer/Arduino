// basic setup
const int sensorPin = A2;
float baselineTemp;
unsigned long int avgVal;
const int b = 50;
int buf[b], temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // opens a serial port
  for(int pinNumber = 3; pinNumber<6; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
  digitalWrite(4, HIGH);
  // measure baseline temperature
  for(int i = 0; i < b; i++){
    buf[i] = analogRead(sensorPin);
    delay(100);
  }
  avgVal=0;
  for(int i = 0; i < b; i++){
    avgVal += buf[i];
  };
  float volBase = ((avgVal / b) / 1024.0) * 5.0;
  baselineTemp = (volBase - .5) * 100;
  digitalWrite(4, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", voltage: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  Serial.print(baselineTemp);
  Serial.print(" :: ");
  // convert the voltage to temperature in degrees C
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature);
  if(temperature < baselineTemp+2){
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }else if(temperature >= baselineTemp+6){
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  delay(1);
}
