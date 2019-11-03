void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(400);
  digitalWrite(13,LOW);
  delay(400);
  digitalWrite(7,HIGH);
  delay(5000); 
  digitalWrite(7,LOW);
  delay(1000);
  digitalWrite(7,HIGH);
  delay(1000);
  digitalWrite(7,LOW);
  delay(500);
  digitalWrite(8,HIGH);
  delay(1500);
  digitalWrite(8,LOW);
  delay(300);
  digitalWrite(9,HIGH);
  delay(300);
  digitalWrite(13,LOW);
  delay(300);
  digitalWrite(11,HIGH);
  delay(1000);
  //2 iteracion
  delay(5000);
  digitalWrite(11,LOW);
  delay(1000);
  digitalWrite(11,HIGH);
  delay(1000);
  digitalWrite(11,LOW);
  delay(1000);
  digitalWrite(12,HIGH);
  delay(1000);
  digitalWrite(12,LOW);
  //delay(1000);
  digitalWrite(9,LOW);
  delay(1000);  
}
