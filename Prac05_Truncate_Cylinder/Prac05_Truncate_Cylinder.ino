#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

#define TR 2
#define EC 3
#define pi 3.1416
#define heigth 7.5 //15.6 //Heigth of the conatiner
#define larger_diameter 11.4 //9.5	//Diameter of the larger base
#define smaller_diameter 9 //7 //Diameter of the smaller base

void setup() {
  lcd.begin(16, 2);
  pinMode(TR, OUTPUT);
  pinMode(EC, INPUT);
  //Serial.begin(9600);
}

void loop() {
  //float TR = 2, EC = 3;
  float available = 0,volume = 0, volume2 = 0,porcen=0,used = 0,turns = 15, term = 0,
          larger_radius = 0, smaller_radius = 0;
  larger_radius = larger_diameter / 2.0; //radius of the larger base
  smaller_radius = smaller_diameter / 2.0; //radius of the smaller base
  /*
  	Ecuation:
  		V = (pi * h)/3 * (LR^2 + SR^2 + LR * SR)
  */
  term = (larger_radius * larger_radius) + (smaller_radius * smaller_radius) + larger_radius * smaller_radius;
  //Volume of the container
  volume = (pi * heigth)/3 * term;


  for (int i = 0; i < turns; ++i)
  {
    available += distance();
    delay(10);
  }
  //get an average of the distance
  available /= turns;

  if( available < heigth ){ // Prevent to read a larger distance than the heigth
    used = heigth - available;
    //We calculate the volume of the liquid
    volume2 = ( pi * used)/3 * term;
    porcen = ( volume2 * 100) / volume;

    lcd.clear();
    //Print Section
    lcd.setCursor(0,0);
    lcd.print(volume2);
    lcd.print(" ml");
    lcd.setCursor(0,1);
    lcd.print(porcen);
    lcd.print(" %");

   /* Serial.print("Disp: ");
    Serial.print(available);
    Serial.print("  Ocup: ");
    Serial.print(used);
    Serial.print("  Term: ");
    Serial.print(term);
    Serial.print("  Vol: ");
    Serial.print(volume);
    Serial.print("  Vol2: ");
    Serial.print(volume2);
    Serial.print("  ");
    Serial.print(porcen);
    Serial.println("%");*/
    delay(1500);
  }
  
}
float distance() {
  float distance = 0, time = 0;
  digitalWrite(TR, LOW);
  delayMicroseconds(10);
  digitalWrite(TR, HIGH);
  delayMicroseconds(10);
  time = pulseIn(EC, HIGH);
  distance = time * 0.01716;
  return distance;
}
