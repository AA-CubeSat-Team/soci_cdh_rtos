#include <Wire.h>

void setup() {
  Wire.begin(0x7E);             // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);           // start serial for output
  Serial.println("I2C secondary setup");

}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  Serial.println("I2C interrupt");
  while (0 < Wire.available()) { // loop through all but the last
    uint8_t c = Wire.read(); // receive byte as a character
    Serial.print("0x");
    Serial.print(c, HEX);
    Serial.print(" ");
  }
}

void requestEvent() {
  Serial.println("I2C request recved");
  uint8_t byt = 0x1f;
  for(int i=0; i<32; i++){
    Wire.write(byt--);
  }
}
