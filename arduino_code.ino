// Temperature Controlled Fan using Arduino and Lm35 Code
#include<LiquidCrystal.h>

int IRsensor=3;
int RS=4;
int EN=5;
int D4=6;
int D5=7;
int D6=8;
int D7=9;

int lm35Pin= A0;        // LM35 output pin
int ENB=10;            // the enable pin connected to digital pin 9
int IN3=11;            // the input pins are connected to digital pins 10 and 11
int IN4=12;

LiquidCrystal lcd (RS,EN, D4,D5,D6,D7);

void setup() {
    lcd.begin(16,2);
    lcd.clear();
  
    Serial.begin(9600);
  
    pinMode(lm35Pin, INPUT);
    pinMode(IRsensor, INPUT);
    pinMode(ENB, OUTPUT);  // enable pin and input pins are initialized as output
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
}
void loop() {
    int value = digitalRead(IRsensor);
    Serial.println("");
    Serial.print("Sensor Value=");
    Serial.println(value);
    delay(1000);

    // Get the voltage reading from the LM35
    int reading = analogRead(lm35Pin);

    // Convert that reading into voltage
    float voltage = reading * (5000 / 1024);

    // Convert the voltage into the temperature in Celsius
    float temperatureC = voltage / 10;

    // Print the temperature in Celsius
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.print("\xC2\xB0"); // shows degree symbol
    Serial.print("C | ");
    delay(1000);

    lcd.setCursor(0,0);
}
if (temperatureC > 28 && value == 1) 
{
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 255);
    lcd.print("Speed= HIGH");
} 
else if (26 < temperatureC && temperatureC < 28 && value == 1) 
{
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 100);
    lcd.print("Speed= MEDIUM");
} 
else if (24 < temperatureC && temperatureC < 26 && value == 1) 
{
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 45);
    lcd.print("Speed= LOW");
} 
else 
{
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 0);
    lcd.print("FAN OFF");
}
