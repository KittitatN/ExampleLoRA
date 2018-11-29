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
#include <Adafruit_Sensor.h>
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
uint16_t    counter;

uint32_t   Interval_Time_Old[2];
uint16_t   Interval[2];

uint16_t   Temp_BMP280;
uint32_t   Pressure;
uint16_t   Approx_Altitude;


uint8_t     temp8[4];
uint16_t    temp16[4];
uint32_t    temp32[4];

String str1 = "";
String str2 = "";
String str3 = "";
String str4 = "";
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
  Set_Config1();
  delay(250);
  //  Set_ConfigABP();
  Set_ConfigOTAA();
  delay(250);

  Interval[0] = 3000;

}

/********************************************************
  Function Name   : loop
  Description     :
  Input           :
  Return          :
********************************************************/
void loop()
{
  double data = 0;
  //  str1 = "mac tx ucnf 15 432109";
  //  if (millis() - Interval_Time_Old[0] >= Interval[0])
  //  {
  //    Interval_Time_Old[0] = millis();
  //    Serial2.print(str1);//Sent To ACChip
  //
  //    delay(1000);
  //    Serial.println(str1);//debug Set format
  //    str4 = "";
  //    str4 = Serial2.readString();
  //    Serial.println(str4);
  //    Serial2_String_Write("mac tx ucnf 15 432109");
  //  }

  Serial2_String_Write("mac tx ucnf 14 ABCDEF");
  str1 = "";
  delay(3000);
  str1 = Serial2.readString();
  Serial.print("send uplink");
  Serial.println(str1);



  data = smeHumidity.readHumidity();
  Serial.print("Humidity   : ");
  Serial.print(data);
  Serial.println(" %");


  data = smeHumidity.readTemperature();
  Serial.print("Temperature: ");
  Serial.print(data);
  Serial.println(" celsius");
  Serial.println("");


  digitalWrite(LED_GPIO, HIGH);
  delay(100);
  digitalWrite(LED_GPIO, LOW);
  delay(100);
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
  //  Serial2_String_Write("mac set_class C");
  //  str1 = "";
  //  delay(250);
  //  str1 = Serial2.readString();
  //  Serial.print("set_class C");
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
  Serial2_String_Write("mac set_class A");
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


