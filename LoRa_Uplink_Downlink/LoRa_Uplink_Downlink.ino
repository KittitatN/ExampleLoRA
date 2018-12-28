#include "Arduino.h"
#include "wiring_private.h"


void        Set_Config1             (void);
void        SERCOM1_Handler         (void);
void        Serial2_String_Write    (char *s);
void        Set_Config1             (void);
void        Set_ConfigABP_A         (void);
void        Set_ConfigABP_A         (void)

Uart Serial2(&sercom1, 11, 10, SERCOM_RX_PAD_0, UART_TX_PAD_2);

void SERCOM1_Handler(void)
{
  Serial2.IrqHandler();
}

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

/********************************************************
  Function Name   : Set_ConfigABP_A
  Description     :
  Input           :
  Return          :
********************************************************/

void Set_ConfigABP_A(void)
{
  String str1 = "";
  //*********************************************************************
  Serial2_String_Write("mac set_class A");
  str1 = "";
  delay(250);
  str1 = Serial2.readString();
  Serial.print("set_class A");
  Serial.println(str1);

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
  Function Name   : Set_ConfigABP_c
  Description     :
  Input           :
  Return          :
********************************************************/

void Set_ConfigABP_C(void)
{
  String str1 = "";
  //*********************************************************************
  Serial2_String_Write("mac set_class C");
  str1 = "";
  delay(250);
  str1 = Serial2.readString();
  Serial.print("set_class C");
  Serial.println(str1);

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

unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 15000;

/********************************************************
  Function Name   : setup
  Description     :
  Input           :
  Return          :
********************************************************/
void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  Serial.begin(115200);
  Serial2.begin(115200);
  pinPeripheral(10, PIO_SERCOM);
  pinPeripheral(11, PIO_SERCOM);
  delay(1000);
  if (Serial2.available())
  {
    Serial.print(Serial2.readString());
  }
  delay(1000);
  //  Set_ConfigABP_A();
  Set_ConfigABP_C();

  delay(250);
  startMillis = millis();
}
void loop() {
  String str4 = "";
  currentMillis = millis();
  // SEND INTERVAL 15 SECOND --> EDIT PARAMETER preiod TO CHANGE TIME INTERVAL LINE 259
  if (currentMillis - startMillis >= period)
  {
    // SEND UPLINK DATA
    Serial2_String_Write("mac tx ucnf 15 ABCDEF");
    startMillis = currentMillis;
  }
  // COUNT FOR SEND UPLINK
  if ((currentMillis - startMillis) / 1000 > 0)
    Serial.println((currentMillis - startMillis) / 1000);
  str4 = Serial2.readString();
  Serial.println(str4);
}

