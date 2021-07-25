char mystr[5] = "Hello"; //String data
const int redled=12 ;
void setup() {
  // Begin the Serial at 9600 Baud
   pinMode (redled, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.write(mystr,5); //Write the serial data
  digitalWrite (redled, HIGH );
  delay(1000);
}
