#include <EEPROM.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
 
String texto_fila;
 
void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
}
 
void loop() {
  lcd.clear();
  if( Serial.available() > 0 ){
    texto_fila = Serial.readString();
    Serial.print("1");
    guarda();
  }else{
    recupera();
  }
  imprimeBien();
}
void imprimeBien(){
  // Obtenemos el tamaño del texto
  int tam_texto=texto_fila.length();
  int val = 0;
  int caux = 1, caux2 = 1;
 
  // Mostramos entrada texto por la izquierda
  for(int i=tam_texto; i>0 ; i--)
  {
    String texto = "",texto2 = "";
    if( val > 15){
      texto = texto_fila.substring(i-1);
      texto2 = texto_fila.substring(tam_texto - caux);
      caux++;
    }else{
      texto = texto_fila.substring(i-1);
    }
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(texto);
    lcd.setCursor(0,1);
    lcd.print(texto2);
    delay(420);
    val++;
  }
  
  int chido = (tam_texto - caux) + 1;
  // Desplazamos el texto hacia la derecha
  for(int i=1; i<=16;i++)
  {
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.print(texto_fila);
    if( tam_texto > 16){
      lcd.setCursor(0,1);
      String tex2 = texto_fila.substring(chido-caux2);
      lcd.print(tex2);
    }
    delay(420);
    caux2++;
  }
   for(int i=0; i<16;i++)
  {
    lcd.clear();
    lcd.setCursor(i, 1);
    lcd.print(texto_fila);
    delay(420);
   }
}
 void guarda(){
  int longitud = texto_fila.length();
  char bytes[longitud], car;
  texto_fila.toCharArray(bytes,longitud);
  for( int i = 0; i < longitud; i++){
    car = texto_fila[i];
    EEPROM.write(i,car);
  }
  car = '\0';
  EEPROM.write(longitud,car);
}
void recupera(){
  texto_fila = "";
  byte ch;
  int leidos = 0;
  ch = EEPROM.read(leidos);
  while( ch != '\0'){
    texto_fila += char(ch);
    leidos++;
    ch = EEPROM.read(leidos);
  }
}
