#include <SoftwareSerial.h>

// Chỉ định chân TX và RX cho giao tiếp UART
#define TX_PIN 11
#define RX_PIN 10

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Khai báo một đối tượng SoftwareSerial

void setup() {
  Serial.begin(9600);   // Khởi tạo Serial monitor
  mySerial.begin(9600); // Khởi tạo giao tiếp UART với baudrate 9600
}

void loop() {

  // Gửi dữ liệu từ slave tới master
  mySerial.println(" di an kem na!");


}
