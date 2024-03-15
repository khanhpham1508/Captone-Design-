#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 10);

LiquidCrystal_I2C lcd(0x27, 20, 4);
#define trigPin 7 //Sensor Echo pin connected to Arduino pin 13
#define echoPin 6 //Sensor Trip pin connected to Arduino pin 12

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  mySerial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
  lcd.print("Distance:");  //Print Message on First Row
}

void loop()
{
  float duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(9,0);   //Set Cursor again to first column of second row
  lcd.print(distance); //Print measured distance
  lcd.print("cm");  //Print your units.
  delay(170); //pause to let things settle
}
