int ENA = 10, IN1 = 9,IN2= 8;
int FC1 = 7, FC2 = 6;
void setup() {
  // put your setup code here, to run once:
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(FC1,INPUT);
  pinMode(FC2,INPUT);
  Serial.begin(9600);
}

void loop() {
  int v1 = digitalRead(FC1), v2 = digitalRead(FC2);
  if( v1 == HIGH)
    Serial.print("FIN 1: ON ");
  else
    Serial.print("FIN 1: OFF ");

  Serial.print("| ");

  if( v2 == HIGH)
    Serial.print("FIN 2: ON ");
    
  else
    Serial.print("FIN 2: OFF ");

  Serial.println();
  if( v1 == HIGH && v2 == LOW){
    adelante();
  }
  if( v1 == LOW && v2 == HIGH){
    atras();
  }
  /*
  if( v1 == HIGH && v2 == LOW){
        Serial.print("Abriendo..._");
        
        adelante();
      }
      if( v1 == LOW && v2 == HIGH){ 
        Serial.print("Techo Abierto_");
        atras();
      }*/
   /*if( v1 == LOW && v2 == HIGH){
        Serial.print("Cerrando..._");
        
        atras();
      }
      if( v1 == HIGH && v2 == LOW){
        Serial.print("Techo Cerrado_");
        parar();
        delay(2000);
      }*/
      Serial.println();
}
void adelante(){
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, 255); 
}
void atras(){
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, HIGH);
    analogWrite (ENA, 255); 
}
void parar(){
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, 0);
}
