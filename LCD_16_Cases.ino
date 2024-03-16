#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
SoftwareSerial mySerial(13, 12);
int sen1_LED = 8;
int sen2_LED = 7;
int sen3_LED = 6;
int sen4_LED = 5;
 

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  pinMode(sen1_LED, OUTPUT);
  pinMode(sen2_LED, OUTPUT);    
  pinMode(sen3_LED, OUTPUT);
  pinMode(sen4_LED, OUTPUT); 
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {

if (mySerial.available()>0) 
  {
  String sensor1distance = mySerial.readStringUntil('!');
  float float_sen1 = sensor1distance.toFloat();
  String sensor2distance = mySerial.readStringUntil('@');
  float float_sen2 = sensor2distance.toFloat();
  String sensor3distance = mySerial.readStringUntil('#');
  float float_sen3 = sensor3distance.toFloat();
  String sensor4distance = mySerial.readStringUntil('$');
  float float_sen4 = sensor4distance.toFloat();


  Serial.print("Sensor 1: ");
  Serial.println(float_sen1);
  Serial.print("Sensor 2:");
  Serial.println(float_sen2);
  Serial.print("Sensor 3: ");
  Serial.println(float_sen3);
  Serial.print("Sensor 4:");
  Serial.println(float_sen4);

  if (float_sen1 < 150 && float_sen2 < 200 && float_sen3 < 200 && float_sen4 < 150) {
    digitalWrite(sen1_LED, HIGH);
    digitalWrite(sen2_LED, HIGH);
    digitalWrite(sen3_LED, HIGH);
    digitalWrite(sen4_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("FRONT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen1); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("RIGHT: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen2); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,2);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("LEFT: ");  //Print Message on First Row
    lcd.setCursor(9,2);   //Set Cursor again to first column of second row
    lcd.print(float_sen3); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,3);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("BACK: ");  //Print Message on First Row
    lcd.setCursor(9,3);   //Set Cursor again to first column of second row
    lcd.print(float_sen4); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
  } 
  else {
    digitalWrite(sen1_LED, LOW);
    digitalWrite(sen2_LED, LOW);
    digitalWrite(sen3_LED, LOW);
    digitalWrite(sen4_LED, LOW);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("NO Objectives!");  //Print Message on First Row
    delay(100);
  }
if (float_sen1 > 150 && float_sen2 > 200 && float_sen3 > 200 && float_sen4 < 150) {
    digitalWrite(sen1_LED, LOW);
    digitalWrite(sen2_LED, LOW);
    digitalWrite(sen3_LED, LOW);
    digitalWrite(sen4_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0,3);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("BACK: ");  //Print Message on First Row
    lcd.setCursor(9,3);   //Set Cursor again to first column of second row
    lcd.print(float_sen4); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
  } 
  else {
    digitalWrite(sen1_LED, HIGH);
    digitalWrite(sen2_LED, HIGH);
    digitalWrite(sen3_LED, HIGH);
    digitalWrite(sen4_LED, LOW);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("FRONT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen1); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("RIGHT: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen2); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,2);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("LEFT: ");  //Print Message on First Row
    lcd.setCursor(9,2);   //Set Cursor again to first column of second row
    lcd.print(float_sen3); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
  }
  if (float_sen1 > 150 && float_sen2 > 200 && float_sen3 < 200 && float_sen4 > 150) {
    digitalWrite(sen1_LED, LOW);
    digitalWrite(sen2_LED, LOW);
    digitalWrite(sen3_LED, HIGH);
    digitalWrite(sen4_LED, LOW);
    lcd.clear();
    lcd.setCursor(0,2);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("LEFT: ");  //Print Message on First Row
    lcd.setCursor(9,2);   //Set Cursor again to first column of second row
    lcd.print(float_sen3); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
  } else {
    digitalWrite(sen1_LED, HIGH);
    digitalWrite(sen2_LED, HIGH);
    digitalWrite(sen3_LED, LOW);
    digitalWrite(sen4_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("FRONT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen1); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("LEFT: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen2); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,3);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("BACK: ");  //Print Message on First Row
    lcd.setCursor(9,3);   //Set Cursor again to first column of second row
    lcd.print(float_sen4); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
  }
  if (float_sen1 > 150 && float_sen2 > 200 && float_sen3 < 200 && float_sen4 < 150) {
    digitalWrite(sen1_LED, LOW);
    digitalWrite(sen2_LED, LOW);
    digitalWrite(sen3_LED, HIGH);
    digitalWrite(sen4_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("LEFT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen3); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("BACK: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen4); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
  } else {
    digitalWrite(sen1_LED, HIGH);
    digitalWrite(sen2_LED, HIGH);
    digitalWrite(sen3_LED, LOW);
    digitalWrite(sen4_LED, LOW);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("FRONT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen1); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("RIGHT: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen2); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
  }
   if (float_sen1 > 150 && float_sen2 < 200 && float_sen3 > 200 && float_sen4 > 150) {
    digitalWrite(sen1_LED, LOW);
    digitalWrite(sen2_LED, HIGH);
    digitalWrite(sen3_LED, LOW);
    digitalWrite(sen4_LED, LOW);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("RIGHT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen2); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
   } else {
    digitalWrite(sen1_LED, HIGH);
    digitalWrite(sen2_LED, LOW);
    digitalWrite(sen3_LED, HIGH);
    digitalWrite(sen4_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("FRONT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen1); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("LEFT: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen3); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,3);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("BACK: ");  //Print Message on First Row
    lcd.setCursor(9,3);   //Set Cursor again to first column of second row
    lcd.print(float_sen4); //Print measured distance
    lcd.print("cm");  //Print your units.
   }
   if (float_sen1 > 150 && float_sen2 < 200 && float_sen3 > 200 && float_sen4 < 150) {
    digitalWrite(sen1_LED, LOW);
    digitalWrite(sen2_LED, HIGH);
    digitalWrite(sen3_LED, LOW);
    digitalWrite(sen4_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("RIGHT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen2); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("BACK: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen4); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
   } else {
    digitalWrite(sen1_LED, HIGH);
    digitalWrite(sen2_LED, LOW);
    digitalWrite(sen3_LED, HIGH);
    digitalWrite(sen4_LED, LOW);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("FRONT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen1); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("LEFT: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen3); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
   }
   if (float_sen1 > 150 && float_sen2 < 200 && float_sen3 < 200 && float_sen4 > 150) {
    digitalWrite(sen1_LED, LOW);
    digitalWrite(sen2_LED, HIGH);
    digitalWrite(sen3_LED, HIGH);
    digitalWrite(sen4_LED, LOW);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("RIGHT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen2); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("LEFT: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen3); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
   } else {
    digitalWrite(sen1_LED, HIGH);
    digitalWrite(sen2_LED, LOW);
    digitalWrite(sen3_LED, LOW);
    digitalWrite(sen4_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("FRONT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen1); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("BACK: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen4); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
   }
   if (float_sen1 > 150 && float_sen2 < 200 && float_sen3 < 200 && float_sen4 < 150) {
    digitalWrite(sen1_LED, LOW);
    digitalWrite(sen2_LED, HIGH);
    digitalWrite(sen3_LED, HIGH);
    digitalWrite(sen4_LED, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("RIGHT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen2); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,1);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("LEFT: ");  //Print Message on First Row
    lcd.setCursor(9,1);   //Set Cursor again to first column of second row
    lcd.print(float_sen3); //Print measured distance
    lcd.print("cm");  //Print your units.
    lcd.setCursor(0,3);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("BACK: ");  //Print Message on First Row
    lcd.setCursor(9,3);   //Set Cursor again to first column of second row
    lcd.print(float_sen4); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
   } else {
    digitalWrite(sen1_LED, HIGH);
    digitalWrite(sen2_LED, LOW);
    digitalWrite(sen3_LED, LOW);
    digitalWrite(sen4_LED, LOW);
    lcd.clear();
    lcd.setCursor(0,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("FRONT: ");  //Print Message on First Row
    lcd.setCursor(9,0);   //Set Cursor again to first column of second row
    lcd.print(float_sen1); //Print measured distance
    lcd.print("cm");  //Print your units.
    delay(100);
  }
}
}
