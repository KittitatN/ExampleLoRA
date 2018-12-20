#include "SoftwareSerial.h"

SoftwareSerial newSerial(10,11);


void setup() {
  // initialize both serial ports:
  Serial.begin(115200);
  newSerial.begin(115200);
}

void loop() {

  while (newSerial.available() > 0) {
    Serial.write(newSerial.read());
  }
  while (Serial.available() > 0) {
    newSerial.write(Serial.read());
  }

}
