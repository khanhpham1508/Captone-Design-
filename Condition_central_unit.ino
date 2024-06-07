#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

int Front_LED_R = 2;
int Left_LED_R = 4;
int Right_LED_R = 6;
int Back_LED_R = 8;

void setup() {
    pinMode(Front_LED_R, OUTPUT);
    pinMode(Left_LED_R, OUTPUT);
    pinMode(Right_LED_R, OUTPUT);
    pinMode(Back_LED_R, OUTPUT);
    lcd.init();
    lcd.backlight();
//    lcd.clear();
    
    // Khởi động Serial để debug qua USB
    Serial.begin(9600);

    // Khởi động Serial1 (UART1) cho module CAN với baudrate 9600
    Serial1.begin(9600);

    // Khởi động Serial2 (UART2) cho module Zigbee với baudrate 9600
    Serial2.begin(9600);

    // In thông báo để xác nhận Serial1 và Serial2 đã khởi động
    Serial.println("Serial1 (UART1) for CAN started");
    Serial.println("Serial2 (UART2) for Zigbee started");
}

void LED_Left(int Sen1_Distance) {
    if (Sen1_Distance < 50 && Sen1_Distance > 20) {
        digitalWrite(Left_LED_R, HIGH);
    } else {
        digitalWrite(Left_LED_R, LOW);
    }
}

void LED_Front(int Sen2_Distance, int Sen3_Distance) {
    if ((Sen2_Distance < 50 && Sen2_Distance > 20) || (Sen3_Distance < 50 && Sen3_Distance > 20)) {
        digitalWrite(Front_LED_R, HIGH);
    } else {
        digitalWrite(Front_LED_R, LOW);
    }
}

void LED_Right(int Sen4_Distance) {
    if (Sen4_Distance < 50 && Sen4_Distance > 20) {
        digitalWrite(Right_LED_R, HIGH);
    } else {
        digitalWrite(Right_LED_R, LOW);
    }
}

void LED_Back(int Sen5_Distance, int Sen6_Distance) {
    if ((Sen5_Distance < 50 && Sen5_Distance > 20) || (Sen6_Distance < 50 && Sen6_Distance > 20)) {
        digitalWrite(Back_LED_R, HIGH);
    } else {
        digitalWrite(Back_LED_R, LOW);
    }
}

void LCD_Distance(int Sen1_Distance, int Sen2_Distance, int Sen3_Distance, int Sen4_Distance, int Sen5_Distance, int Sen6_Distance) {
    lcd.clear();
    // LEFT 
    lcd.setCursor(0, 0); 
    lcd.print("LEFT: ");
    lcd.setCursor(8, 0);
    lcd.print(Sen1_Distance);
    lcd.print("cm");
    
    // FRONT    
    lcd.setCursor(0, 1);
    lcd.print("FRONT: ");
    lcd.setCursor(8, 1);
    lcd.print(Sen2_Distance);
    lcd.print("cm");
    lcd.setCursor(15, 1);
    lcd.print(Sen3_Distance);
    lcd.print("cm");
    
    // RIGHT  
    lcd.setCursor(0, 2); 
    lcd.print("RIGHT: ");
    lcd.setCursor(8, 2);
    lcd.print(Sen4_Distance);
    lcd.print("cm");
    
    // BACK    
    lcd.setCursor(0, 3);
    lcd.print("BACK: ");
    lcd.setCursor(8, 3);
    lcd.print(Sen5_Distance);
    lcd.print("cm");
    lcd.setCursor(15, 3);
    lcd.print(Sen6_Distance);
    lcd.print("cm");
}

void BACK_ERROR(int Sen1_Distance, int Sen2_Distance, int Sen3_Distance, int Sen4_Distance, int Sen5_Distance, int Sen6_Distance,bool receivedData2) {
    
    if (!receivedData2) {
      lcd.clear();
    // LEFT 
    lcd.setCursor(0, 0); 
    lcd.print("LEFT: ");
    lcd.setCursor(8, 0);
    lcd.print(Sen1_Distance);
    lcd.print("cm");
    
    // FRONT    
    lcd.setCursor(0, 1);
    lcd.print("FRONT: ");
    lcd.setCursor(8, 1);
    lcd.print(Sen2_Distance);
    lcd.print("cm");
    lcd.setCursor(15, 1);
    lcd.print(Sen3_Distance);
    lcd.print("cm");
    
    // RIGHT  
    lcd.setCursor(0, 2); 
    lcd.print("RIGHT: ");
    lcd.setCursor(8, 2);
    lcd.print(Sen4_Distance);
    lcd.print("cm");
    
    // BACK    
    lcd.setCursor(0, 3);
    lcd.print("BACK: ");
    lcd.setCursor(7, 3);
    lcd.print("ERROR !!!");
    }
}

void loop() {
    // Kiểm tra dữ liệu từ Serial1 (CAN module) và in ra Serial (USB)
    int Sen1_Distance;
    int Sen2_Distance;
    int Sen3_Distance;
    int Sen4_Distance;
    int Sen5_Distance;
    int Sen6_Distance;
    bool receivedData2 = false;

    if (Serial1.available()) {
        // Sen1
        String Sen1 = Serial1.readStringUntil('A');
        Sen1_Distance = Sen1.toFloat();
        Serial.print("Sensor 1: ");
        Serial.println(Sen1_Distance);

        // Sen2
        String Sen2 = Serial1.readStringUntil('B');
        Sen2_Distance = Sen2.toFloat();
        Serial.print("Sensor 2: ");
        Serial.println(Sen2_Distance);

        // Sen3
        String Sen3 = Serial1.readStringUntil('C');
        Sen3_Distance = Sen3.toFloat();
        Serial.print("Sensor 3: ");
        Serial.println(Sen3_Distance);

        // Sen4
        String Sen4 = Serial1.readStringUntil('D');
        Sen4_Distance = Sen4.toFloat();
        Serial.print("Sensor 4: ");
        Serial.println(Sen4_Distance);
    }

    // Kiểm tra dữ liệu từ Serial2 (Zigbee module) và in ra Serial (USB)
    if (Serial2.available()) {
        // Sen5
        String Sen5 = Serial2.readStringUntil('E');
        Sen5_Distance = Sen5.toFloat();
        Serial.print("Sensor 5: ");
        Serial.println(Sen5_Distance);

        // Sen6
        String Sen6 = Serial2.readStringUntil('F');
        Sen6_Distance = Sen6.toFloat();
        Serial.print("Sensor 6: ");
        Serial.println(Sen6_Distance);
        receivedData2 = true;
    }

    LED_Left(Sen1_Distance);
    LED_Front(Sen2_Distance, Sen3_Distance);
    LED_Right(Sen4_Distance);
    LED_Back(Sen5_Distance, Sen6_Distance);
    Serial.println(Sen4_Distance);

    if (receivedData2 == true) {
        LCD_Distance(Sen1_Distance, Sen2_Distance, Sen3_Distance, Sen4_Distance, Sen5_Distance, Sen6_Distance);
    } else {
        BACK_ERROR(Sen1_Distance, Sen2_Distance, Sen3_Distance, Sen4_Distance, Sen5_Distance, Sen6_Distance,receivedData2);
    }
}
