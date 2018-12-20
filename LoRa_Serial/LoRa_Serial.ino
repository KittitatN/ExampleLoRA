/**********************************************************************
  Program      : LoRa_AcSip_Arduino_TEST_LoRa1
  Description  : S76S + ATSAMD21G18
  FileName     : LoRa_AcSip_Arduino_TEST_LoRa1.ino
  Compiler     : Arduino 1.8.3
  Chip Target  : S76S + ATSAMD21G18
  Date         : 20/08/2561
  Author       : vichien@windowslive.com
**********************************************************************/
#include <Arduino.h> // required before wiring_private.h


/********************************************************
  Function Name   : setup
  Description     :
  Input           :
  Return          :
********************************************************/
void setup()
{

  delay(3000);

  Serial.begin(115200);
  Serial1.begin(115200);
  delay(1000);

  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("****************************************");
  Serial.println("LoRa_AcSip_Arduino_TEST_LoRa1");
  Serial.println("****************************************");

  
}

/********************************************************
  Function Name   : loop
  Description     :
  Input           :
  Return          :
********************************************************/
void loop()
{

  while (Serial.available() > 0)
  {
    Serial1.write(Serial.read());
  }
  while (Serial1.available() > 0)
  {
    Serial.write(Serial1.read());
  }
}
