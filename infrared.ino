//Infrared Sensor
int obstacle1=5;
int obstacle2=6;
int obstacle3=7;
int obstacle4=8;
int obstacle5=9;
int isobs1=LOW;
int isobs2=HIGH;
int isobs3=HIGH;
int isobs4=HIGH;
int isobs5=HIGH;

void setup() {
  // put your setup code here, to run once:
  pinMode(obstacle1,INPUT);
  pinMode(obstacle2,INPUT);
  pinMode(obstacle3,INPUT);
  pinMode(obstacle4,INPUT);
  pinMode(obstacle5,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalRead(obstacle1);
  
  Serial.println(digitalRead(obstacle1));
  delay(2000);
}
