// Basic script for analog reading of pH probe
// with averaging of 10 values

// Basic setup
#define sensorPin A5
#define LED 13
#define Offset 0.18
unsigned long int avgVal;
float b;
int buf[10],temp;

// Setting up basics
void setup()
{
    pinMode(LED,OUTPUT);
    Serial.begin(9600);
}

// Basic loop for measuring pH
void loop()
{
    // LED for begining of measurment
    digitalWrite(13,HIGH);

    // Math for sampling and averaging 6 middle values in 100 ms
    for(int i=0;i<10;i++)
    {
        buf[i]=analogRead(sensorPin);
        delay(10);
    }
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(buf[i]>buf[j])
            {
                temp=buf[i];
                buf[i]=buf[j];
                buf[j]=temp;
            }
        }
    }
    avgVal=0;
    for(int i=2;i<8;i++)
        avgVal+=buf[i];

    // Conversion from analogRead to voltage to pH
    float voltage=(float)avgVal*5.0/1024/6;
    float phVal=3.5*voltage;

    // Outputting values
    Serial.print(avgVal);
    Serial.print('\t');
    Serial.print(voltage, 3);
    Serial.print('\t');
    Serial.print(phVal, 3);
    Serial.println("");

    // Delay in milliseconds
    delay(100);

    // LED for end of measurment
    digitalWrite(13, LOW);
}
