#include <SoftwareSerial.h>
SoftwareSerial SIM808(12, 13); // gsm module connected here
//char copy[50];
String val = "hello";
  
//char *message = "device";
 //char charBuf[50];
String f1001 = "+919790736990"; 
//String f1002 = "+918250001320"; 
//String f1003 = "09790736990"; 
 
void setup() {
  Serial.begin(9600);
  SIM808.begin(9600); // original 19200. while enter 9600 for sim900A 
 
  
  //SIM808.listen();
  sendsms(val, f1001); // you can use a variable of the type String
  //Serial.println();
  Serial.println("message sent."); 
//SIM808.listen();
//  sendsms(message, f1002); // you can also write any message that you want to send.
//  Serial.println(string2char(message));
//  Serial.println("message sent."); 
//SIM808.listen();
//  sendsms(message, f1003); // you can also write any message that you want to send.
//  Serial.println(message);
//  Serial.println("message sent."); 
}
 
void loop() {
}
 void sendData(String val)
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
     
     
     
          
    // String location=getGPSlocation();
     String message = 'val';   
     sim808.sendSMS('DataNumber','message');
     
/*

Location:32.123 84.345 DATA:1|2|3|4|5

*/

  //Serial.println(" Gathering data");
     
}

 
void sendsms(String val, String number)
{
String mnumber = "AT+CMGS=\""+number+"\"\r\n";
//String dataToBeSent = val;
//dataToBeSent.toCharArray(copy, 50);
 Serial.println("Initializing..."); 
  delay(1000);

  SIM808.println("AT\r\n"); //Once the handshake test is successful, i t will back to OK
   delay(1000);
  Serial.println(ReadGSM());
  delay(1000);
   SIM808.println("AT+CMGF=1\r\n");
   delay(1000);                   
 SIM808.println(mnumber); // recipient's mobile number, in international format
 Serial.println(mnumber);
  delay(1000);   
  SIM808.println(val); // message to send
  Serial.println(val);
  delay(1000);
  Serial.println(ReadGSM());
  delay(500); 
  SIM808.write(0X1A);

  delay(500);
  Serial.println(ReadGSM());
  delay(1000); 
   // SIM808.write(0x0D);
   //SIM808.write(0x0A);
 // delay(1000);                                  // give module time to send SMS
 // SIM900power();  
}

char* string2char(String command){
    if(command.length()!=0){
        char *p = const_cast<char*>(command.c_str());
        return p;
    }
}

String ReadGSM() {
  char c;
  String str;
  //Serial.println(GSMport.available());
  while (SIM808.available()) {
    c = SIM808.read();
    str += c;
    delay(20);
  }
  str = "<<< " + str;
  //Serial.println(str);
  return str;
}



  
