
#include <OneWire.h>

OneWire  ds(2);  // on pin 2 (a 4.7K resistor is necessary)

unsigned long tiempoahora;
unsigned long tiempoanterior;

byte data[12];
float celsius;

void setup()
{
  Serial.begin(9600);
  ds.reset();
  ds.skip();
  ds.write(0x44, 0); // start conversion
  tiempoanterior = 0;
}

void loop()
{
  tiempoahora = millis();
  
  if ((tiempoahora - tiempoanterior) > 1000) {
    ds.reset();
    ds.skip();
    ds.write(0xBE);         // Read Scratchpad
    for (unsigned char i = 0; i < 9; i++) {           // we need 9 bytes
      data[i] = ds.read();
    }
    int16_t raw = (data[1] << 8) | data[0];
    byte cfg = (data[4] & 0x60);
    // at lower res, the low bits are undefined, so let's zero them
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    //// default is 12 bit resolution, 750 ms conversion time
    celsius = (float)raw / 16.0;
    Serial.print("*");
    Serial.println(celsius);
    ds.reset();
    ds.skip();
    ds.write(0x44, 0); // start conversion
    tiempoanterior = tiempoahora;
  }

  // Agregamos el caracter # para indicar que es un dato
  Serial.print("#");
 
  // Leemos la entrada analógica A0 y enviamos el resultado por el puerto serial
  Serial.println(analogRead(A0));
  
  // Esperamos un tiempo de 100 milisegundos
  delay(100);
   
}
