#include <SoftwareSerial.h>
SoftwareSerial mySerial(11, 10);
const int trigPin = 7;  // Trig pin of the JSN-SR04T connected to Arduino digital pin 2
const int echoPin = 6;  // Echo pin of the JSN-SR04T connected to Arduino digital pin 3

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  mySerial.begin(9600);
}

void loop() {
  // Trigger pulse to initiate measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(50);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(200);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  float distanceCM = duration * 0.034 / 2;

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distanceCM);
  Serial.println(" cm");

  String send_data = String(distanceCM) + "#";
  mySerial.print(send_data);

  // Wait for a short delay before the next measurement
  delay(100);
}