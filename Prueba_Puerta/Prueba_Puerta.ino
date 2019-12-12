int FC1 = 4, FC2 = 5, ENA = 10, IN1 = 9, IN2 = 8, V = 3;
boolean flag = false;
void setup() {
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (FC1,INPUT);
  pinMode (FC2,INPUT);
  pinMode (V,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int v1 = digitalRead(FC1),v2 = digitalRead(FC2);
  Serial.print("FC1 : ");
  Serial.print(v1);
  Serial.print(" FC2: ");
  Serial.println(v2);
  if( !flag ){
    if( v1 == HIGH && v2 == LOW){
      adelante();
      digitalWrite(V,HIGH);
    }
    if(v1 == LOW && v2 == HIGH){
      parar();
      flag = true;
    }
  }else{
    if( v1 == LOW && v2 == HIGH){
      digitalWrite(V,LOW);
      atras();
    }
    if(v1 == HIGH && v2 == LOW){
      parar();
      flag = false;
    }
  }
  
  delay(500);
}
void adelante(){
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, 200); 
}
void atras(){
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    analogWrite (ENA, 200); 
}
void parar(){
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, 0);
}
