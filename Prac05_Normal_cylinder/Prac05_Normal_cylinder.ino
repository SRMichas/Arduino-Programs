#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,10,9,8,7);

#define TR 2
#define EC 3
#define pi 3.1416
#define heigth 8.5
#define diameter 7.4

void setup(){
  lcd.begin(16, 2);
  pinMode(TR, OUTPUT);
  pinMode(EC, INPUT);
}

void loop(){
  float   availableSpace = 0, volume = 0, volume2 = 0,porcen=0,
          used = 0,turns = 10, area = 0, radius = 0;
  radius = diameter / 2;
  area = pi * (radius * radius);
  //We calculate the volume of the container
  volume = area * heigth;
  
  for(float i = 0; i < turns; i++){ 
    availableSpace += distance();
    delay(10);
  }
  //get an average of the distance
  availableSpace /= turns;
  
  if( availableSpace < heigth){ // Prevent to read a larger distance than the heigth
    used = heigth - availableSpace ;
    //We calculate the volume of the liquid
    volume2 = area * used;

    porcen = (volume2 * 100)/ volume;
    
    lcd.clear();
    //Print Section
    lcd.setCursor(0,0);
    lcd.print(volume2);
    lcd.print(" ml");
    lcd.setCursor(0,1);
    lcd.print(porcen);
    lcd.print(" %");
    
    delay(1000);
  }  
}
float distance(){
    float distance = 0.0,timel = 0.0;
    digitalWrite(TR, LOW);
    delayMicroseconds(5);
    digitalWrite(TR, HIGH);
    delayMicroseconds(10);
    timel = pulseIn(EC,HIGH);
    distance = time * 0.01716;
  return distance;
}
