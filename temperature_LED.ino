//Temperature controlling LED intensity
int intensidad=0;
float tempC;
int resistencia;
void setup()
{
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
    char dato= Serial.read();
    analogWrite(9,intensidad);
    tempC=analogRead(1);
    tempC=(5.0*tempC*100.0/1024.0);
    resistencia=analogRead(0);
    Serial.print(tempC);
    Serial.print("C");
    Serial.print("!");
    Serial.print(resistencia);
    delay(1000);
   switch(dato)
    {
    case 'C': 
      {
        intensidad=intensidad+10;
        analogWrite(9,intensidad);
        break;
      }
    case 'D': 
      {
        intensidad=intensidad-10;
        analogWrite(9,intensidad);
        break;
      }
    }       
  }
