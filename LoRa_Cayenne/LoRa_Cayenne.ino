/**********************************************************************
  Program      : LoRa_AcSip_Arduino_TEST_LoRa1
  Description  : S76S + ATSAMD21G18
  FileName     : LoRa_AcSip_Arduino_TEST_LoRa1.ino
  Compiler     : Arduino 1.8.3
  Chip Target  : S76S + ATSAMD21G18
  Date         : 20/08/2561
  Author       : vichien@windowslive.com
**********************************************************************/
#include <Arduino.h>   // required before wiring_private.h
#include <Wire.h>
#include <HTS221.h>
#include "wiring_private.h" // pinPeripheral() function


Uart Serial2(&sercom1, 11, 10, SERCOM_RX_PAD_0, UART_TX_PAD_2);

#define     LED_GPIO   13

void        Set_Config1             (void);
void        SERCOM1_Handler         (void);
void        Serial2_String_Write    (char *s);
void        Set_Config1             (void);
void        Set_ConfigABP           (void);
void        Set_ConfigOTAA          (void);


String str1 = "";

/********************************************************
  Function Name   : SERCOM1_Handler
  Description     :
  Input           :
  Return          :
********************************************************/
void SERCOM1_Handler(void)
{
  Serial2.IrqHandler();
}

/********************************************************
  Function Name   : setup
  Description     :
  Input           :
  Return          :
********************************************************/
void setup()
{
  delay(3000);
  pinMode(LED_GPIO, OUTPUT);
  digitalWrite(LED_GPIO, HIGH);

  Serial.begin(115200);
  Serial2.begin(115200);
  pinPeripheral(10, PIO_SERCOM);
  pinPeripheral(11, PIO_SERCOM);
  delay(1000);

  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("****************************************");
  Serial.println("LoRa_AcSip_Arduino_TEST_LoRa1");
  Serial.println("****************************************");

  delay(250);
  Wire.begin();
  smeHumidity.begin();
  delay(250);

  delay(200);
  //  Serial2_String_Write("sip reset");
  delay(1000);
  if (Serial2.available())
  {
    Serial.print(Serial2.readString());
  }
  delay(1000);
  //  Set_Config1();
  delay(250);
  Set_ConfigABP();
  //  Set_ConfigOTAA();
  delay(250);



}

/********************************************************
  Function Name   : loop
  Description     :
  Input           :
  Return          :
********************************************************/
void loop() {
  char test[] = "mac tx ucnf 15 0167800002730020038806765ff2960a0003e8067104D2FB2E0000";
  float Temp = smeHumidity.readTemperature();
  uint16_t val = Temp * 10;
  uint8_t hex[4] = "";
  for (int i = 3; i > -1; i--)
  {
    uint8_t x = val % 16;
    val = val / 16;
    if (val < 16)
    {
      hex[i--] = x;
      hex[i] = val;
      break;
    }
    else
    {
      hex[i] = x;
    }
  }
  int index = 19;
  for (int j = 0; j < 4; j++)
  {

    if (hex[j] >= 10) {
      test[index] = char(hex[j] + 87);
    }
    else {
      test[index] = char(hex[j] + 48);
    }
    index++;
  }

  Serial2_String_Write(test);
  str1 = "";
  delay(3000);
  str1 = Serial2.readString();
  Serial.print("send uplink");
  Serial.println(str1);
}

/********************************************************
  Function Name   : Set_ConfigABP
  Description     :
  Input           :
  Return          :
********************************************************/
void Set_ConfigABP(void)
{
  String str1 = "";
  //*********************************************************************
  Serial2_String_Write("mac set_class A");
  str1 = "";
  delay(250);
  str1 = Serial2.readString();
  Serial.print("set_class A");
  Serial.println(str1);
  //  Serial2_String_Write("mac set_class A");
  //  str1 = "";
  //  delay(250);
  //  str1 = Serial2.readString();
  //  Serial.print("set_class A");
  //  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_deveui XXXXXXXXXXXXXXXX");
  str1 = "";
  delay(250);
  str1 = Serial2.readString();

  Serial.print("set_deveui");
  Serial.println(str1);
  //*********************************************************************


  //*********************************************************************
  Serial2_String_Write("mac set_devaddr XXXXXXXX");
  str1 = "";
  delay(250);
  str1 = Serial2.readString();
  Serial.print("set_devaddr");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_nwkskey XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
  str1 = "";
  delay(250);
  str1 = Serial2.readString();
  Serial.print("set_nwkskey");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_appskey XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
  str1 = "";
  delay(250);
  str1 = Serial2.readString();
  Serial.print("set_appskey");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac save");
  str1 = "";
  delay(3000);
  str1 = Serial2.readString();
  Serial.print("mac save");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac join abp");
  str1 = "";
  delay(250);
  str1 = Serial2.readString();
  Serial.print("mac join abp");
  Serial.println(str1);
}
/********************************************************
  Function Name   : Set_ConfigOTAA
  Description     :
  Input           :
  Return          :
********************************************************/

void Set_ConfigOTAA(void)
{
  String respond = "";
  //*******************************************
  Serial2_String_Write("mac set_class C");
  delay(100);
  respond = Serial2.readString();

  Serial.print("set_class A");
  Serial.println(respond);

  //  Serial2_String_Write("mac set_class C");
  //  delay(100);
  //  respond = Serial2.readString();
  //
  //  Serial.print("set_class C");
  //  Serial.println(respond);

  //*******************************************

  //*******************************************
  Serial2_String_Write("mac set_deveui XXXXXXXXXXXXXXXX");
  delay(100);
  respond = Serial2.readString();

  Serial.print("set_deveui");
  Serial.println(respond);
  //*******************************************

  //*******************************************
  Serial2_String_Write("mac set_appeui XXXXXXXXXXXXXXXX");
  delay(100);
  respond = Serial2.readString();

  Serial.print("set_appeui");
  Serial.println(respond);
  //*******************************************

  //*******************************************
  Serial2_String_Write("mac set_appkey XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
  delay(100);
  respond = Serial2.readString();

  Serial.print("set_appkey");
  Serial.println(respond);
  //*******************************************

  //*******************************************
  Serial2_String_Write("mac join otaa");
  delay(100);
  respond = Serial2.readString();

  Serial.print("mac join otaa");
  Serial.println(respond);
  //*******************************************
}

/********************************************************
  Function Name   : Set_Config1
  Description     :
  Input           :
  Return          :
********************************************************/
void Set_Config1(void)
{
  String str1 = "";
  //*********************************************************************
  Serial2_String_Write("mac set_ch_freq 0 923200000");//0
  str1 = "";
  delay(100);
  str1 = Serial2.readString();
  Serial.print("set_ch_freq 0");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_ch_freq 1 923400000");//1
  str1 = "";
  delay(100);
  str1 = Serial2.readString();
  Serial.print("set_ch_freq 1");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_ch_freq 2 922000000");//2
  str1 = "";
  delay(100);
  str1 = Serial2.readString();
  Serial.print("set_ch_freq 2");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_ch_freq 3 922200000");//3
  str1 = "";
  delay(100);
  str1 = Serial2.readString();
  Serial.print("set_ch_freq 3");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_ch_freq 4 922400000");//4
  str1 = "";
  delay(100);
  str1 = Serial2.readString();
  Serial.print("set_ch_freq 4");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_ch_freq 5 922600000");//5
  str1 = "";
  delay(100);
  str1 = Serial2.readString();
  Serial.print("set_ch_freq 5");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_ch_freq 6 922800000");//6
  str1 = "";
  delay(100);
  str1 = Serial2.readString();
  Serial.print("set_ch_freq 6");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_ch_freq 7 923000000");//7
  str1 = "";
  delay(100);
  str1 = Serial2.readString();
  Serial.print("set_ch_freq 7");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac set_rx2 2 923200000");//8
  str1 = "";
  delay(100);
  str1 = Serial2.readString();
  Serial.print("set_rx2 2");
  Serial.println(str1);

  //*********************************************************************
  Serial2_String_Write("mac save");//8
  str1 = "";
  delay(3000);
  str1 = Serial2.readString();
  Serial.print("mac save");
  Serial.println(str1);
}

/********************************************************
  Function Name   : Serial2_String_Write
  Description     :
  Input           :
  Return          :
********************************************************/
void Serial2_String_Write(char *s)
{
  while (*s)
  {
    Serial2.write(*s++);
  }
}
