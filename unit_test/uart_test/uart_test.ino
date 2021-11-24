#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(2,3); //2 -> slave's RX, 3 -> slave's TX

#define messageSize 18

void setup() {
  Serial.begin(115200);
  mySerial.begin(115200); // TO DO: change the BAUDRATE to match the Dev Board
}
int len = 0;
char val[32];
void loop() {
    if(mySerial.available() > 0) {
      val[len++] = mySerial.read();
  } else if (len == messageSize) {
    for (int i = 0; i < messageSize; i++) {
        mySerial.write(val[i]);
    }
  }
}
