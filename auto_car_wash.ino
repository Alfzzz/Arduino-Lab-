//Controlling Carwash Station with multiple sensors
#include<Servo.h>
//Ultrasonic
int obstacle1=5;
int obstacle2=6;
int obstacle3=7;
int obstacle4=8;
int obstacle5=9;
int isobs1=HIGH;
int isobs2=HIGH;
int isobs3=HIGH;
int isobs4=HIGH;
int isobs5=HIGH;

Servo servo1;
Servo servo2;
void setup() {
  // put your setup code here, to run once:
  pinMode(obstacle1,INPUT);
  pinMode(obstacle2,INPUT);
  pinMode(obstacle3,INPUT);
  pinMode(obstacle4,INPUT);
  pinMode(obstacle5,INPUT);
  servo1.attach(10);
  servo2.attach(11);
  Serial.begin(9600);
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  isobs1=digitalRead(obstacle1);
  isobs2=digitalRead(obstacle2);
  isobs3=digitalRead(obstacle3);
  isobs4=digitalRead(obstacle4);
  isobs5=digitalRead(obstacle5);
  Serial.println(digitalRead(obstacle1));
  if(isobs1==LOW||isobs2==LOW||isobs3==LOW||isobs4==LOW||isobs5==LOW){
    int pos;
  for(pos=0;pos<=90;pos+=1){
    servo1.write(pos);
    delay(15);
  }
  }
    delay(1000);
}
