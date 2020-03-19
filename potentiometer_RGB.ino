//Controlling RGB LED color with a potentiometer and push Button
int red=13;
int blue=11;
int green=12;
int button1=1;
int pot=7;
int state1=0;
int val=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(1,INPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state1= digitalRead(button1);
  val=analogRead(pot);
  if(state1==HIGH){
    if(0<=val<=127){
     analogWrite(red,LOW);
     analogWrite(green,LOW);
     analogWrite(blue,LOW);
    }
    if(128<=val<=255){
     analogWrite(red,HIGH);
     analogWrite(green,LOW);
     analogWrite(blue,LOW);
    }
    if(256<=val<=383){
     analogWrite(red,LOW);
     analogWrite(green,HIGH);
     analogWrite(blue,LOW);
    }
    if(384<=val<=511){
     analogWrite(red,LOW);
     analogWrite(green,LOW);
     analogWrite(blue,HIGH);
    }
    if(512<=val<=639){
     analogWrite(red,HIGH);
     analogWrite(green,LOW);
     analogWrite(blue,HIGH);
    }
    if(640<=val<=767){
     analogWrite(red,LOW);
     analogWrite(green,HIGH);
     analogWrite(blue,HIGH);
    }
    if(768<=val<=895){
     analogWrite(red,238);
     analogWrite(green,130);
     analogWrite(blue,238);
    }
    if(896<=val<=1023){
     analogWrite(red,HIGH);
     analogWrite(green,HIGH);
     analogWrite(blue,LOW);
    }
  }  
}
