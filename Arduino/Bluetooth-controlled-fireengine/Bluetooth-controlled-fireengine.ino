#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11); // RX, TX
String voiceData;
int motor_input1=9;
int motor_input2=8;
int motor_input3=5;
int motor_input4=6;

//comment below line for using digital output from fire sensor
int fireSensorPin = A0; // input pin for the firesensor analog output
//uncomment below line for using digital output from fire sensor
//int fireSensorPin = 4; // input pin for the firesensor digital output
int fireSensorValue = 0; 
int pumpMotorPin = 8; // output pin of pump motor
int led = 13; // Output pin for LED
int buzzer = 12; // Output pin for Buzzer

void setup() {
Serial.begin(9600);
bluetooth.begin(9600);
pinMode(motor_input1, OUTPUT);   //RIGHT MOTOR
pinMode(motor_input2, OUTPUT);   //RIGHT MOTOR
pinMode(motor_input3, OUTPUT);   //LEFT MOTOR
pinMode(motor_input4, OUTPUT);   //LEFT MOTOR
pinMode(fireSensorPin, INPUT) ;
pinMode(led, OUTPUT);
pinMode(buzzer,OUTPUT);
pinMode(pumpMotorPin, OUTPUT); 
digitalWrite(pumpMotorPin, LOW); // motor is off on start
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
  
//comment below two lines for using digital output from fire sensor
fireSensorValue = analogRead(fireSensorPin); 
Serial.println(fireSensorValue);
//uncomment below two lines for using digital output from fire sensor
//fireSensorValue = digitalRead(fireSensorPin); 
//Serial.println(fireSensorValue);
if (fireSensorValue < 100)
{
Serial.println("Fire Detected");
digitalWrite(led,HIGH);// turns led on
digitalWrite(buzzer,HIGH);// turns buzzer on
digitalWrite(pumpMotorPin, HIGH); // turns pump on
delay(500); 
digitalWrite(pumpMotorPin, LOW); // turns pump off
delay(1000);
}
else 
{
Serial.println("Fire Not Detected");
digitalWrite(led,LOW);// turns led off
digitalWrite(buzzer,LOW);// turns buzzer off
digitalWrite(pumpMotorPin, LOW); // turns pump off
delay(1000);
}

//if (fireSensorValue == 1)
//{
//Serial.println("Fire Detected");
//digitalWrite(led,HIGH);// turns led on
//digitalWrite(buzzer,HIGH);// turns buzzer on
//digitalWrite(pumpMotorPin, HIGH); // turns pump on
//delay(500); 
//digitalWrite(pumpMotorPin, LOW); // turns pump off
//delay(1000);
//}
//else 
//{
//Serial.println("Fire Not Detected");
//digitalWrite(led,LOW);// turns led off
//digitalWrite(buzzer,LOW);// turns buzzer off
//digitalWrite(pumpMotorPin, LOW); // turns pump off
//delay(1000);
//}

}
