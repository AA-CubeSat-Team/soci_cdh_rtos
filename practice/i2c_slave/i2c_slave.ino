#include "main.h"

void setup() {
  Serial.begin(9600);

  Wire.begin(0x62);             // join i2c bus with address #62
  Wire.onReceive(receiveEvent); // register event / Slave Reader
  Wire.onRequest(requestEvent); // register event / Slave Writer

}

void loop() {
  delay(100);
}
 
// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  if (Wire.available() >= 1) { // loop through all but the last
    int index = Wire.read();
    ACTIVE_INDEX = index;
    while (Wire.available() > 0) {
      char data = Wire.read(); // receive byte as a character
        REG[ACTIVE_INDEX] = data; 
    }
  }
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  
  // write if index >= 0x8
  if (ACTIVE_INDEX < 0x8) {
    unsigned char arr [4] = {REG[ACTIVE_INDEX], REG[ACTIVE_INDEX+1], REG[ACTIVE_INDEX+2], REG[ACTIVE_INDEX+3]};
    Wire.write(arr, 4); 
  } else if(ACTIVE_INDEX >= 0x8) {
    Wire.write(REG[ACTIVE_INDEX]);
  }

  // as expected by master
}






  
