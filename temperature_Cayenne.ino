// Sensing temperature and connect to Cayenne
//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#define led1 16
#define led2 5
#define led3 4
float tempc;
// WiFi network info.
char ssid[] = "INFINITUMD20D";//wifi ssid
char wifiPassword[] = "3055301498";//wifi pasword
// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "3a47d1c0-e09e-11e8-a254-e163efaadfe8";
char password[] = "804e6815f14223606925099cbafa5645d12a4186";
char clientID[] = "af47ebe0-e5f3-11e8-8cb9-732fc93af22b";
void setup() {
Serial.begin(9600);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}
void loop() {
  Cayenne.loop();
  tempc=analogRead(A0);
  tempc=(5.0*tempc*100.0)/1024.0;
  Serial.println(tempc);
  Cayenne.virtualWrite(4,tempc);
}
CAYENNE_IN(1){
  int state1=getValue.asInt();
  digitalWrite(led1,state1);
}
CAYENNE_IN(2){
  int state2=getValue.asInt();
  digitalWrite(led2,state2);
}

CAYENNE_IN(3){
  int state3=getValue.asInt();
  digitalWrite(led3,state3);
}
