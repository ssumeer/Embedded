#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11); // RX, TX
String voiceData;
int motor_input1=9;
int motor_input2=8;
int motor_input3=5;
int motor_input4=6;

void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(motor_input1, OUTPUT);   //RIGHT MOTOR
  pinMode(motor_input2, OUTPUT);   //RIGHT MOTOR
  pinMode(motor_input3, OUTPUT);   //LEFT MOTOR
  pinMode(motor_input4, OUTPUT);   //LEFT MOTOR
}

void loop() 
{  
  if (bluetooth.available()){
  voiceData=bluetooth.read();

   if(voiceData=="forward"){
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, HIGH);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, HIGH);
     delay(5000);
    }
  else
    if(voiceData=="back"){
    digitalWrite(motor_input1, HIGH);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, HIGH);
    digitalWrite(motor_input4, LOW);  
    delay(5000);}
  else
   if(voiceData=="left"){
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, HIGH);
    digitalWrite(motor_input3, HIGH);
    digitalWrite(motor_input4, LOW);
    delay(800); 
    }
  else
   if(voiceData=="right"){
    digitalWrite(motor_input1, HIGH);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, HIGH);
    delay(800);   }
   if(voiceData.length()>0)
    {
      Serial.println(voiceData);
       voiceData="";
    digitalWrite(motor_input1, LOW);
    digitalWrite(motor_input2, LOW);
    digitalWrite(motor_input3, LOW);
    digitalWrite(motor_input4, LOW);
    }
  }    
  }
