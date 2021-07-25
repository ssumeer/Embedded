char mystr[10]; //Initialized variable to store recieved data
String data;
void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  data = Serial.readBytes(mystr,5);
  Serial.println(mystr); 
  if (data == "Hello");
  {
    Serial.println("data came");
  }
   //Read the serial data and store in var
  //Print data on Serial Monitor
  delay(1000);
}
