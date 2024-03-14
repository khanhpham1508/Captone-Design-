#include <SoftwareSerial.h>
SoftwareSerial mySerial(13, 12);
int sen1_LED = 8;
int sen2_LED = 7;
 

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(sen1_LED, OUTPUT);
  pinMode(sen2_LED, OUTPUT);    

}

void loop() {

if (mySerial.available()>0) 
  {
  String sensor1distance = mySerial.readStringUntil('*');
  float float_sen1 = sensor1distance.toFloat();
  String sensor2distance = mySerial.readStringUntil('&');
  float float_sen2 = sensor2distance.toFloat();


  Serial.print("Sensor 1: ");
  Serial.println(float_sen1);
  Serial.print("Sensor 2:");
  Serial.println(float_sen2);

  if (float_sen1 < 100) {
    digitalWrite(sen1_LED, HIGH);
    delay(100);
  } 
  else {
    digitalWrite(sen1_LED, LOW);
  }

  if (float_sen2 < 100) {
    digitalWrite(sen2_LED, HIGH);
    delay(100);
  } 
  else {
    digitalWrite(sen2_LED, LOW);
  }

  }
}