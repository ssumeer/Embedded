// Program for rtc time set.
#include "Arduino.h"

#include <SoftwareSerial.h>

SoftwareSerial SIM808(12, 13);

void setup()
{
  Serial.begin(9600);
  SIM808.begin(9600); // setting up SIM808
  SetRtctime(); //uncomment to set time

}

void loop()
{
  Serial.println(dateParserForRTC(getRtctime())); // comment to set time
}

String ReadGSM() {
  char c;
  String str;
  while (SIM808.available()) {
    c = SIM808.read();
    str += c;
    delay(20);
  }
  str = "<<< " + str;
  //Serial.println(str);
  return str;
}

String SetRtctime()
{ 
  SIM808.println("AT+CCLK=\"20/05/19,21:48:00+08\"\r\n"); //set the latest time
  delay(1000);
  Serial.println(ReadGSM());
  SIM808.println("AT+CCLK?\r\n");
  delay(1000);
  Serial.println(ReadGSM());
  SIM808.println("AT+CLTS=1\r\n");
  delay(1000);
  Serial.println(ReadGSM());
  SIM808.println("AT+CLTS?\r\n");
  delay(1000);
  Serial.println(ReadGSM());
}



String getRtctime()
{
  SIM808.println("AT+CCLK?\r\n");
  delay(1000);
  String localstr = " ";
  localstr = String(ReadGSM());
  return localstr;
}

String dateParserForRTC(String str) // dateparser for gps
{
  String var = str;
  String yy = var.substring(30,32);
  String mm = var.substring(27, 29);
  String dd = var.substring(24, 26);
  String hh = var.substring(33, 35);
  String mi = var.substring(36, 38);
  String sec = var.substring(39, 41);
  String delimiter1 = " ";
  String delimiter3 = "-";
  String delimiter4 = ":";
  String finalstr = (yy + delimiter3 + mm + delimiter3 + dd + delimiter1 + hh + delimiter4 + mi + delimiter4 + sec );
  return finalstr;
}
