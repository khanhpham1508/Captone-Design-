#include <SoftwareSerial.h>

// Chỉ định chân TX và RX cho giao tiếp UART
#define TX_PIN 9
#define RX_PIN 8

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Khai báo một đối tượng SoftwareSerial

void setup() {
  Serial.begin(9600);   // Khởi tạo Serial monitor
  mySerial.begin(9600); // Khởi tạo giao tiếp UART với baudrate 9600
}

void loop() {
  
  // Đọc dữ liệu từ slave
  if (mySerial.available()) {
    while (mySerial.available()) {
      Serial.write(mySerial.read());
    }
  }

}
