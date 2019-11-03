#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

#define TR 2
#define EC 3
#define pi 3.1416
#define altura 7.5 //15.6
#define diametroM 11.4 //9.5
#define diametrom 9 //7

void setup() {
  lcd.begin(16, 2);
  pinMode(TR, OUTPUT);
  pinMode(EC, INPUT);
  //Serial.begin(9600);
}

void loop() {
  //float TR = 2, EC = 3;
  float disponible = 0,volumen = 0, volumen2 = 0,porcen=0,
          porcen2 = 0,ocupado = 0,vueltas = 15, termino = 0,
          radioM = 0, radiom = 0, disp2 = 0;
  radioM = diametroM / 2.0;
  radiom = diametrom / 2.0;
  termino = (radioM * radioM) + (radiom * radiom) + radioM * radiom;
  volumen = (pi * altura)/3 * termino;

  for (int i = 0; i < vueltas; ++i)
  {
    disponible += distancia();
    delay(10);
  }
  disponible /= vueltas;

  if( disponible < altura ){
    ocupado = altura - disponible;
    volumen2 = ( pi * ocupado)/3 * termino;
    porcen = ( volumen2 * 100) / volumen;
    lcd.clear();

    lcd.setCursor(0,0);
    lcd.print(volumen2);
    lcd.print(" ml");
    lcd.setCursor(0,1);
    lcd.print(porcen);
    lcd.print(" %");

   /* Serial.print("Disp: ");
    Serial.print(disponible);
    Serial.print("  Ocup: ");
    Serial.print(ocupado);
    Serial.print("  Term: ");
    Serial.print(termino);
    Serial.print("  Vol: ");
    Serial.print(volumen);
    Serial.print("  Vol2: ");
    Serial.print(volumen2);
    Serial.print("  ");
    Serial.print(porcen);
    Serial.println("%");*/
    delay(1500);
  }
  
}
float distancia() {
  float res = 0, tiempo = 0;
  digitalWrite(TR, LOW);
  delayMicroseconds(10);
  digitalWrite(TR, HIGH);
  delayMicroseconds(10);
  tiempo = pulseIn(EC, HIGH);
  res = tiempo * 0.01716;
  return res;
}
