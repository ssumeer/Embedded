/**
 Tiago Santos, 2014
 dark_storm@groundzero.com.pt
 http://space.groundzero.com.pt
 Code to control a RC Car
 Thanks to Bruno Santos (feiticeir0@whatgeek.com.pt) for some code
 Free to share
 **/
//Pinouts
//Ultrasound Sensor
#define trigPin 2 // Trigger  2
#define echoPin 3 //echo      3


//Motor A
int enableA = 12;  //12
int pinA1 = 11;    //11
int pinA2 = 10;    //10

///Motor B
int enableB = 9;
int pinB1 = 8;    //8
int pinB2 = 7;  //7


//Variables
long duration;
int distance;
<p>int r;</p>
void setup()
{
 Serial.begin(9600);
 /* Initialize Ultrasound Pin Modes */
 pinMode(trigPin, OUTPUT); // Trigger PIN
 pinMode(echoPin, INPUT); // Echo PIN
  
 /* Initialize Motor A Pin Modes */
  pinMode (enableA, OUTPUT);
  pinMode (pinA1, OUTPUT);
  pinMode (pinA2, OUTPUT);  
  
 /* Initialize Motor B Pin Modes */  
  pinMode (enableB, OUTPUT);
  pinMode (pinB1, OUTPUT);
  pinMode (pinB2, OUTPUT);  
}
void loop()
{
  //check the distance
  distance = checkDistance(); 
  
  Serial.println(distance);
  delay(200);
  //if distance is less that 30 cm
  if(distance < 30)
  {
    Serial.println("menor");
    //stop car, turn wheels right and go back for 500 ms. Then stop
    stopMotorA();
    //stopMotorB();
    r = random(1);
    if( r == 1)
    {
      turnRight();
    }
    else
    {
      turnLeft();
    }
    delay(100);
    goBack();
    delay(500);
    stopMotorB();
    stopMotorA();
    if( r == 1)
    {
      turnLeft();
    }
    else
    {
      turnRight();
    }
    delay(100);
    stopMotorB();
  }
  else
  {
    Serial.println("maior");
    stopMotorA();
    stopMotorB();
    goForward();
  }
  
}
//function to calcutate the distance to an obstacle
long microsecondsToCentimeters (long microseconds) {
 // The speed of sound is 340 m/s or 29 microseconds per centimeter
 // The ping travels forth and back, so, the distance is half the distance traveled
 return microseconds / 29 / 2;
}
//function to check the distance of an obstacle
long checkDistance()
{
 /* The following trigPin/echoPin cycle is used to determine the distance of the nearest
 object by bouncing soundwaves off it */
 //Trigger a HIGH pulse for 2 or more microseconds
 //Give a short LOW pulse before sending a HIGH one
 
 digitalWrite (trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite (trigPin, LOW);
 //Now, lets read the read the bounced wave
 duration = pulseIn(echoPin, HIGH);
 //calculate the distance
 distance = microsecondsToCentimeters(duration);
 
 return distance;
}
//function to go forward
void goForward()
{
  //Enable Motor A
  digitalWrite (enableA, HIGH);
  //forward
  digitalWrite (pinA1, LOW);
  digitalWrite (pinA2, HIGH);
}
//function to stop Motor A movement
void stopMotorA()
{
  digitalWrite (enableA, LOW);
}
//function to go back
void goBack()
{
  //Enable Motor A
  digitalWrite (enableA, HIGH);  
  //back
  digitalWrite (pinA1,HIGH);
  digitalWrite (pinA2,LOW);  
}
//function to stop Motor B movement
void stopMotorB()
{
  digitalWrite (enableB, LOW);
}
//function to turn the RC car right
void turnRight()
{
  //Enable Motor B  
  digitalWrite (enableB, HIGH);
  //right  
  digitalWrite (pinB1, LOW);
  digitalWrite (pinB2, HIGH);  
}
//function to turn the RC car left
void turnLeft()
{
  //Enable Motor B  
  digitalWrite (enableB, HIGH);  
  //left
  digitalWrite (pinB1,HIGH);
  digitalWrite (pinB2,LOW);  
}
