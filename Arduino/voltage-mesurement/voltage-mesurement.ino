int analogInput = A3;
int Twelvevolt = 4;
int fivevolt = 5;
float vout = 0.0;
float vin = 0.0;
int value = 0;
void setup(){
   pinMode(analogInput, INPUT);
   pinMode(Twelvevolt,OUTPUT);
   pinMode(fivevolt,OUTPUT);
   Serial.begin(9600);
}
void loop(){
   // read the value at analog input
   //Serial.println(getInputVoltageValue());
   digitalWrite(Twelvevolt, HIGH);
   Serial.println(getInputVoltageValue());
  // String TwelvevoltValue= String(getInputVoltageValue());
   //Serial.println(TwelvevoltValue);
   digitalWrite(Twelvevolt, LOW);
   
//   digitalWrite(fivevolt, HIGH);
//    String fivevoltValue= String(getInputVoltageValue());
//   Serial.println(fivevoltValue);
//   digitalWrite(fivevolt, LOW);
   
  
}
String getInputVoltageValue()
{
  value = analogRead(analogInput);
  vout = (value) * (25.0 / 1023.0); // see text
  String localstr = " ";
  localstr = String(vout);
  
  return localstr;
}
