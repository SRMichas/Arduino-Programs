#include <SoftwareSerial.h>
//SoftwareSerial BT(11,10);
#define T A0
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38000);
  pinMode(T,INPUT);
  //BT.begin(38000);
  Serial.print("prueba");
}

void loop() {
  // put your main code here, to run repeatedly:
  tempe();
}
void tempe(){
  float temp = analogRead(T);
  temp = (temp * 500)*1024.0;
  
  //BT.print(temp);
  //BT.print(";");
  Serial.println(temp);
  delay(50);
}
