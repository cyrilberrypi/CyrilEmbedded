//Slave
#define vibPin 8
int state = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(vibPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
 }
 // Controlling the LED
 if (state == '1') {
  digitalWrite(vibPin, HIGH); // Vibrator ON
  delay(50);
  Serial.println(state);
  state = 0;
  Serial.println(state);
 }
 else if (state == '0') {
  digitalWrite(vibPin, LOW); // Vibrator OFF
  Serial.println(state);
  state = 0;
 }
  }
