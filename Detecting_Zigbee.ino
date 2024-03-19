#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 10);
#define S1Trig 4   // Trig pin of the JSN-SR04T connected to Arduino digital pin 2
#define S1Echo 5   // Echo pin of the JSN-SR04T connected to Arduino digital pin 3
#define S2Trig 6   // Trig pin of the JSN-SR04T connected to Arduino digital pin 2
#define S2Echo 7   // Echo pin of the JSN-SR04T connected to Arduino digital pin 3

int sensorOne() {
  //pulse output
  digitalWrite(S1Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S1Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S1Trig, LOW);

  long t = pulseIn(S1Echo, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}

int sensorTwo() {
  //pulse output
  digitalWrite(S2Trig, LOW);
  delayMicroseconds(4);
  digitalWrite(S2Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(S2Trig, LOW);

  long t = pulseIn(S2Echo, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}
void setup() {
  Serial.begin(9600);
  pinMode(S1Trig, OUTPUT);
  pinMode(S2Trig, OUTPUT);
  pinMode(S1Echo, INPUT);
  pinMode(S2Echo, INPUT);
  mySerial.begin(9600);
}

void loop() {
  int rightSensor = sensorTwo();
  int leftSensor  = sensorOne() ;
  // Print the distance to the Serial Monitor
  Serial.print("Distance1: ");
  Serial.print(rightSensor);
  Serial.println(" cm");
  Serial.print("Distance2: ");
  Serial.print(leftSensor);
  Serial.println(" cm");

  String send_data = String(rightSensor)+ String(leftSensor) + "*";
  mySerial.print(send_data);

  // Wait for a short delay before the next measurement
  
}
