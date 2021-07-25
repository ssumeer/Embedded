

int enb1 = 9;
int enb2 = 9;
int input1 = 10;
int input2 = 11;
int input3 = 10;
int input4 = 11;



void setup() {
Serial.begin(9600);     
pinMode(enb1, OUTPUT);
pinMode(input1, OUTPUT);
pinMode(input2, OUTPUT);
pinMode(enb2, OUTPUT);
pinMode(input3, OUTPUT);
pinMode(input4, OUTPUT);
}

void loop() {

Serial.println("Enter speed");

if (Serial.available() ) {

                
                
int state = Serial.parseInt();

if (state == 10)

{
    analogWrite(enb1, 255); 
    analogWrite(enb2, 255);
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
    digitalWrite(input3, HIGH);
    digitalWrite(input4, LOW);  
    Serial.println(" running in full speed");

}

if (state == 1)

{
    analogWrite(enb1, 25); 
    analogWrite(enb2, 25);
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
    digitalWrite(input3, HIGH);
    digitalWrite(input4, LOW);  
    Serial.println(" running in 1 speed");
}

if (state == 0)

{
    analogWrite(enb1, 0); 
    analogWrite(enb2, 0);
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    digitalWrite(input3, LOW);
    digitalWrite(input4, LOW);  
    Serial.println(" Motor is off");

}

}

delay(1000);

}
                
