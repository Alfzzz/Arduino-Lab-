int intensidad=0;
void setup()
{
  pinMode(9,OUTPUT);//Seleccionamos el pin 13 como salida
  Serial.begin(9600);//Inicializamos el valor de transmisión.
}

void loop()
{
  while (Serial.available())//Declaramos un sentencia, Mientras el puerto Serial este disponible se empieza el ciclo 
  {
    char dato= Serial.read();
    //Declaramos una variable de tipo carácter y Seo lee la variale enviada desde el Bluetooth.
    analogWrite(9,intensidad);
    //Indicamos que en el puerto 13 la señal será baja por lo que el LED estará apagado.
    switch(dato)
    {
    case 'C': //Si en el caso de ser A la varible enviada, entonces:
      {
        intensidad=intensidad+10;//La señal será alta, encenderá el LED.
        Serial.println(intensidad);
        analogWrite(9,intensidad);//Se mostrará un mensaje.
        break;//El caso se detiene.
      }
    case 'D': //Si en el caso de ser A la variable enviada, entonceS:
      {
        intensidad=intensidad-10;//la señal será baja por lo que el LED estará apagado.
        Serial.println(intensidad);
        analogWrite(9,intensidad);//Se mostrará un mensaje.
        break;
      }
    }       
  }}
