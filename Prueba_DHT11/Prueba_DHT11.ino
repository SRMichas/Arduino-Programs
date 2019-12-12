#include <DHT11.h>

#define DHT11_PIN 7
#define manosoPin A0
DHT11 dht11(DHT11_PIN);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
 
}

void loop() {
float temperatura, humedad;
float temp = analogRead(manosoPin);
 temp = ((5.0/1024.0)*temp)*100;

if(dht11.read(humedad,temperatura) == 0)
{
  Serial.print(String(temperatura)+" C    ");
  Serial.println(String(temp)+" MAÑOSO ");
  
}
}
