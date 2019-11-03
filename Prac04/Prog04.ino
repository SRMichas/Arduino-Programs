#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
boolean salta = false;
String perma = "";

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
    int len;
    if( !salta ){
      String msg = "Mensajillo",aux = "",aux2 = "";
      Serial.println(msg);
      len = msg.length();
      int off = len - 16,algo = 1;
      lcd.setCursor(0,0);
      for(int i = len - 1; i > -1; i--){
        if( off > 0 && i <= (off-1)){
            lcd.setCursor(0,1);
            aux2 = msg.substring((len-algo),len);
            lcd.print(aux2);
            lcd.setCursor(0,0);
            algo++;
        }
        aux = msg.substring(i,len);
        lcd.print(aux);
        delay(300);
        lcd.clear();
      }
      perma = aux+"\n"+aux2;
      salta = true;
   }else{
        len = perma.length();
        int n = perma.indexOf("\n");
        lcd.setCursor(0,0);
        lcd.print(perma.substring(0,n     ));
        lcd.setCursor(0,1);
        lcd.print(perma.substring(n+1,len));
    }
}
