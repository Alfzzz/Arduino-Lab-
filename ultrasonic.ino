//Ultrasonic Sensor
int sensor=A0;
int val=0;
int obstacle=LOW;
int distance=0;
void setup(){
  pinMode (13, OUTPUT);
  pinMode (sensor, INPUT);
  Serial.begin (9600);
  pinMode (10,OUTPUT);
  pinMode (11,OUTPUT);
  pinMode (12,OUTPUT);
}
void loop (){
  obstacle=digitalRead(sensor);
  if(obstacle==LOW){
    Serial.println("OBSTACLE");
    digitalWrite(13,HIGH); 
  }
  else{
    Serial.println("Clear");
    digitalWrite(13,LOW);
  }
  distance=analogRead(sensor);
  Serial.println(distance);
  delay(200);
  digitalWrite (10,HIGH);
  digitalWrite (11,LOW);
  digitalWrite (12,LOW);
  delay (distance-50);
  digitalWrite (10,LOW);
  digitalWrite (11,HIGH);
  digitalWrite (12,LOW);
  delay ( distance-50);
  digitalWrite (10,LOW);
  digitalWrite (11,LOW);
  digitalWrite (12,HIGH);
  delay (distance-50);
   }
