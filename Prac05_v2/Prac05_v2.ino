#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);

#define pi 3.1416
#define altura 14.7
#define diametroM 9.5
#define diametrom 7

void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop(){
  float   disponible = 0, volumen = 0, volumen2 = 0,porcen=0,
          porcen2 = 0,ocupado = 0,vueltas = 15, termino = 0,
          radioM = 0, radiom = 0;
  
  radioM = diametroM / 2.0;
  radiom = diametrom / 2.0;

  termino = (radioM * radioM) + (radiom * radiom) + radioM * radiom;

  volumen = (pi * altura)/3 * termino;
  
  for(float i = 0; i < vueltas; i++){ 
    disponible += distancia();
  }
  
  disponible = disponible / vueltas;
  
  if( disponible < altura ){
    ocupado = altura - disponible;
    volumen2 = ( pi * ocupado )/3 * termino;
    porcen = (volumen2 * 100)/ volumen;
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print(volumen2);
    lcd.print(" ml");
    lcd.setCursor(0,1);
    lcd.print(porcen);
    lcd.print(" %");
    
    Serial.print("Disponible: ");
    Serial.print(disponible);
    Serial.print(" Ocupado: ");
    Serial.print(ocupado);
    /*Serial.print(" Termino: ");
    Serial.print(termino);*/
    Serial.print(" Volumen: ");
    Serial.print(volumen);
    Serial.print(" Volumen2: ");
    Serial.print(volumen2);
    Serial.print(" ");
    Serial.print(porcen);
    Serial.println("%");
    /*lcd.setCursor(0,0);
    lcd.print(altura);
    lcd.setCursor(5,0);
    lcd.print(disponible);
    lcd.setCursor(11,0);
    lcd.print(ocupado);
    lcd.setCursor(0,1);
    lcd.print(volumen);
    lcd.setCursor(7,1);
    lcd.print(volumen2);*/
  
    delay(1000);
  }else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("NO SE PUEDE");
    Serial.println("NO SE PUEDE");
  }
  
  
}

float distancia(){
    float distancia = 0.0,tiempo = 0.0;
    pinMode(2, OUTPUT); 
    digitalWrite(2, LOW);       
    delayMicroseconds(5);       
    digitalWrite(2, HIGH);      
    delayMicroseconds(10);      
    pinMode(3, INPUT);
    tiempo = pulseIn(3,HIGH);
    distancia = tiempo*0.01715;
  return distancia;
}
