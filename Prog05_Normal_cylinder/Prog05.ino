#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);

#define pi 3.1416
#define altura 8.5
#define diametro 7.4
#define TR 2
#define EC 3

void setup(){
  lcd.begin(16, 2);
  pinMode(TR, OUTPUT);
  pinMode(EC, INPUT);
  //Serial.begin(9600);
}
void loop(){
  float   disponible = 0, volumen = 0, volumen2 = 0,porcen=0,
          ocupado = 0,vueltas = 10, area = 0, radio = 0;
  radio = diametro / 2;
  area = pi * (radio * radio);
  volumen = area * altura;
  
  for(float i = 0; i < vueltas; i++){ 
    disponible += distancia();
    delay(10);
  }
  
  disponible /= vueltas;
  
  if( disponible < altura){
    ocupado = altura - disponible;
    volumen2 = area * ocupado;
    porcen = (volumen2 * 100)/ volumen;
    
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print(volumen2);
    lcd.print(" ml");
    lcd.setCursor(0,1);
    lcd.print(porcen);
    lcd.print(" %");
    
    delay(1000);
  }  
}
float distancia(){
    float distancia = 0.0,tiempo = 0.0;
    digitalWrite(TR, LOW);
    delayMicroseconds(5);
    digitalWrite(TR, HIGH);
    delayMicroseconds(10);
    tiempo = pulseIn(EC,HIGH);
    distancia = tiempo * 0.01716;
  return distancia;
}
