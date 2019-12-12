int pin = 7;
void setup(){
  pinMode(pin,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  String val;
  if( Serial.available()){
    val = Serial.readString();
    if( val == "E"){
      digitalWrite(pin,HIGH);
      Serial.println("LED: ON");
    }else if( val == "A"){
      digitalWrite(pin,LOW);
      Serial.println("LED: OFF");
    }
  }else
    Serial.println("AAA");
}
