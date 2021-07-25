// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin1 = 13; 
int servoPin2 = 12; 
// Create a servo object 
Servo Servo1;
Servo Servo2; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin1); 
   Servo2.attach(servoPin2); 
}
void loop(){ 
   // Make servo go to 0 degrees 
    Servo1.write(0); 
   Servo2.write(0); 
   delay(500);
   Servo1.write(30); 
   Servo2.write(40); 
   delay(500);
   // Make servo go to 90 degrees 
   //Servo1.write(0   delay(500); 
   Servo1.write(0); 
   Servo2.write(0); 
   delay(500);
    Servo1.write(30); 
   Servo2.write(40);
   delay(500);
}
