int pin = 7;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
  Serial.begin(38000);
}

void loop() {
  // put your main code here, to run repeatedly:
 String val;
  if( Serial.available()>0){
    val = Serial.readString();
    if( val == "E"){
      digitalWrite(pin,HIGH);
      Serial.println("LED: ON");
    }else if( val == "A"){
      digitalWrite(pin,LOW);
      Serial.println("LED: OFF");
    }
  }
}
