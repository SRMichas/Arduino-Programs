#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.setTimeout(50);
}

void loop() {
 String msg = Serial.readString();
  if( msg.length() > 0){
    lcd.clear();

    String aux = "",aux2 = "";
    int len = msg.length(), off = len - 16,algo = 1;
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
    aux +="\n"+aux2;
    len = aux.length();
    if((len-1) > 16){
        int n = aux.indexOf("\n");
        lcd.setCursor(0,0);
        lcd.print(aux.substring(0,n-1));
        lcd.setCursor(0,1);
        lcd.print(aux.substring(n+1,len));
    }else{
        lcd.setCursor(0,0);
       lcd.print(aux.substring(0,len-1));
    }
  }
}
