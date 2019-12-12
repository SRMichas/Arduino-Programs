
#define ENA 10
#define IN1 9
#define IN2 8
void setup() {
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
}

void loop() {
  adelante();
  delay(2000);
  atras();
  delay(2000);
  parar();
  delay(2000);
}
void adelante(){
    digitalWrite (IN1, HIGH);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, 255); 
}
void atras(){
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, HIGH);
    analogWrite (ENA, 255); 
}
void parar(){
    digitalWrite (IN1, LOW);
    digitalWrite (IN2, LOW);
    analogWrite (ENA, 0); 
}
