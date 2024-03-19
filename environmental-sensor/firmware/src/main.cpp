#include <Arduino.h>
#include <HardwareSerial.h>
const int sensorPinRX = 16; //RXD2
const int sensorPinTX = 17; //TXD2

char array[18]; 
char Sendcalled(char sendByte[9]);
char SendByte[9] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
char ReceiveByte[25];
int ReceivebytePlace = 0;
int place = 0;
bool StartCalled(String readData);
bool StopCalled(String readData);
String ReadMassage();
String ReceivedByte();



void setup() {
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
}

void loop() {
  String receivedData = ReadMassage();
  bool startCalled = StartCalled(receivedData);
  bool stopCalled = StopCalled(receivedData);
  if (startCalled && !stopCalled) {
    Sendcalled(SendByte);
    ReceivedByte();
  } else if ((startCalled==true) && (stopCalled==true)) {
    Serial.println("stop");
    for(;;);
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
  delay(1000);
  char asd[9] = {0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79};
  for(int i=0;i<9;i++){
    Serial2.write(asd[i]);
    Serial.println("Byte yollandı");
  }

  delay(1000);

  
}

String ReceivedByte(){
  char readByte;
  bool read_start = false;
  while(Serial2.available()>0){
    readByte =Serial2.read();
    if(readByte == 0xFF){
      read_start = true;
      ReceivebytePlace = 0;
    }else if(read_start == true){
      ReceiveByte[ReceivebytePlace] = readByte;
      ReceivebytePlace++;
    }
    Serial.println("byte alındı");
    Serial.println(readByte);
  }
  delay(1000);
}