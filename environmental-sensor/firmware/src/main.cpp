#include <Arduino.h>

#define RXD 16  //RXD2
#define TXD 17  //TXD2

char array[18]; 
int place = 0;
char SendByte[9] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
bool StartCalled(String readData);
bool StopCalled(String readData);
String ReadMassage();
char Sendcalled(char sendByte[9]);
String ReceivedByte();


void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  String receivedData = ReadMassage();
  Serial.println("Received Data: " + receivedData);
  bool startCalled = StartCalled(receivedData);
  bool stopCalled = StopCalled(receivedData);
  if (startCalled && !stopCalled) {
    Sendcalled(SendByte);
    ReceivedByte();
  } else if (startCalled && stopCalled) {
    Serial.println("stop");
  }

  delay(1000);
}

String ReadMassage() {
  char inbyte;
  bool read_start = false;

  while (Serial.available() > 0) {
    inbyte = Serial.read();

    if (inbyte == '#') {
      read_start = true;
      place = 0;
    } else if ((read_start==true) && (inbyte != '!')) {
      array[place] = inbyte;  
      place++;
    } else if ((read_start==true) && (inbyte == '!')) {
      array[place] = '\0';
      if (String(array) == "start" || String(array) == "stop") {
        return String(array);
      }
    }
  } 
  return "";   
}

bool StartCalled(String readData) {
  if (readData == "start") {
    return true;
  }
  return false;
}

bool StopCalled(String readData) {
  if (readData == "stop") {
    return true;
  }
  return false;
}

char Sendcalled(char sendByte[9]) {

  Serial1.write(sendByte,9);
  Serial.print("Byte yollandı");

}
String ReceivedByte(){
  char readByte;
  while(Serial1.available()>0){
    readByte =Serial1.read();
    Serial.println(readByte);
  }
}