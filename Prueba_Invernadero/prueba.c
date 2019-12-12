#define H A1
#define T A0
int ENA = 13, IN1 =12,IN2=11;
int FC1 = 10, FC2 = 9,V = 8,B=7;
float hum,temp;
boolean flag = false;
void setup()
{
  pinMode(A1,INPUT);
  pinMode(T,INPUT);
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(FC1,INPUT);
  pinMode(FC2,INPUT);
  pinMode(V,OUTPUT);
  pinMode(B,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //chkHum();
  chkTemp();
  delay(1000);
}
void chkHum(){ 
  /*hum = analogRead(H);
  hum = 100.0 - ((hum/1023.0)*100.0);*/
  hum = analogRead(A1);
  hum = 100.0 - ((hum/1023.0)*100.0);

  if( hum > 65){
	Serial.print("Maximo -> Dejar de Regar ");
	digitalWrite(B,LOW);
  }
  if( hum > 40 && hum < 65){
  	flag = false;
  }
  if( hum > 30 && hum < 40){
  	if( flag ){
  		Serial.print("Regando... ");
  	}
  }
  if( hum < 30){
  	Serial.print("Critico -> Regado Automatico ");
  	digitalWrite(B,HIGH);
  	flag = true;
  }
  Serial.print(hum);
  Serial.println(" % ");
}
void chkTemp(){
  temp = analogRead(T); 
  temp = ((5.0/1024.0)*temp)*100-50;
  int v1 = digitalRead(FC1), v2 = digitalRead(FC2);
  
  if( temp >= 40){
  	if( v1 == HIGH && v2 == LOW){
  		Serial.print("Abriendo... ");
  		digitalWrite(V,HIGH);
  		adelante();
  	}
  	if( v1 == LOW && v2 == HIGH){ 
  		Serial.print("Techo Abierto ");
  		parar();
  		//digitalWrite(V,LOW);
  	}
  }
  if( temp <= 30){
  	if( v1 == LOW && v2 == HIGH){
  		Serial.print("Cerrando... ");
      	digitalWrite(V,LOW);
  		atras();
  	}
  	if( v1 == HIGH && v2 == LOW){
  		Serial.print("Techo Cerrado ");
  		parar();

  	}
  }
  Serial.print(temp);
  Serial.println(" C ");
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