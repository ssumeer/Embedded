#include <Wire.h>
//char c;
void setup() {
 Serial.begin(9600); /* begin serial for debug */
 Wire.begin(D1, D2); /* join i2c bus with SDA=D1 and SCL=D2 of NodeMCU */
}

void loop() {
 Serial.println(getSensorValuesFromNano());
}

String readi2cdata() {
  char c;
  String str;
  while (Wire.available()) {
    c = Wire.read();
    str += c;
   delay(1);
  }
  //Serial.println(str);
  return str;
}

String getSensorValuesFromNano()
{
Wire.requestFrom(8, 13); /* request & read data of size 13 from slave */
  String localstr = " ";
  localstr = String(readi2cdata())+" vfffffff";
  return localstr;
}
