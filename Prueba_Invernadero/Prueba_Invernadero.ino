/*
 Creado: Luis del Valle (ldelvalleh@programarfacil.com)
 https://programarfacil.com
*/
 
// Declaracion de variables globales
float tempC,humedad; // Variable para almacenar el valor obtenido del sensor (0 a 1023)
#define TP A0
#define T A2 
#define H A0
#define V 13
#define A 7
 
void setup() {
  // Configuramos el puerto serial a 9600 bps
  Serial.begin(9600);
 pinMode(V,OUTPUT);
 pinMode(A,OUTPUT);
}
 
void loop() {
  // Con analogRead leemos el sensor, recuerda que es un valor de 0 a 1023
 /* int v = 10;
  for(int i=0;i<v;i++){
    tempC += analogRead(pin); 
    //delay(100);
  }
  tempC /= v;
   
  // Calculamos la temperatura con la fórmula
  tempC = (5.0 * tempC * 100.0)/1024.0; 
 
  // Envia el dato al puerto serial
  Serial.print(tempC);
  // Salto de línea
  Serial.print("\n");*/
  /*humedad = analogRead(pin);
  humedad = 100.0 - ((humedad/1023.0)*100.0);
  Serial.print("Nivel de humedad ");
  Serial.print((int)humedad);
  Serial.println("%");
  delay(200);*/
  checaTemperatura();
  /*int value = analogRead(TP);
  float millivolts = (value / 1023.0) * 5000;
  float celsius = millivolts / 10; 
  Serial.println(value);
  //Serial.println(" C");
  delay(500);*/
 // checaHumedad();
  // Esperamos un tiempo para repetir el loop
  //delay(1000);
}
void checaTemperatura(){
  int v = 10;
  //for(int i=0;i<v;i++){
    tempC = analogRead(TP);
  //}
  //tempC /= v;
   
  // Calculamos la temperatura con la fórmula
              //tempC = (5.0 * tempC * 100.0)/1024.0; 
  /*float dato1 = analogRead(A0);
  float voltios = (dato1 / 1023.0) * 5;
  tempC = voltios / 10e-3;*/
  Serial.print(tempC);
  Serial.println(" MV");
  delay(200);
  /*digitalWrite(V,HIGH);
  if( tempC >= 40){
    digitalWrite(V,HIGH);
    par();
  }
  if( tempC <= 30){
    digitalWrite(V,LOW);
  }*/
}
void checaHumedad(){
  humedad = analogRead(H);
  humedad = 100.0 - ((humedad/1023.0)*100.0);

  if( humedad > 70 && humedad < 70){
    //Rango de advertencia
    Serial.print("Humedad aumentando, se recomienda parar ");
  }
  if( humedad > 60){
    //Regado automatico
    Serial.print("Humedad muy alta, Deteniendo regado automatica ");
    
    digitalWrite(V,LOW);
  }
  
  if( humedad > 30 && humedad < 40){
    //Rango de advertencia
    Serial.print("regando... ");
  }
  if( humedad < 30){
    //Regado automatico
    Serial.print("Humedad en estado critico, Iniciando regado automatica ");
    digitalWrite(V,HIGH);
  }
  Serial.println(humedad);
  delay(500);
}
void par(){
  digitalWrite(A,HIGH);
  delay(100);
  digitalWrite(A,LOW);
}
