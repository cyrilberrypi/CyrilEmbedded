//Ultrasonic sensor

#define trigPin 11
#define echoPin 12
#define ledPin 8 //13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(ledPin,OUTPUT);

}

void loop() {
  
  // put your main code here, to run repeatedly:
  long duration, distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2)/29.1;
  if (distance <15){
    digitalWrite(ledPin,HIGH);
    Serial.write('1'); // Sends '1' to the slave to turn on Vibrator
    delay(1);
 }
  else{
    digitalWrite(ledPin,LOW);
    Serial.write('0');
  }
    delay(50);
}
