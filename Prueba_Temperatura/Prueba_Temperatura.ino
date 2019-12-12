#define T A0
float lectura,temp;
void setup() {
  pinMode(A2,INPUT);
  Serial.begin(9600);
}

void loop() {
 /* int vu = 10;
  float temp2 = 0;
  for(int i=0; i < vu;i++){
    lectura += analogRead(T);
  }
  lectura /= (float)vu;
  temp = (lectura * 500.0) / 1024.0;
  temp2 = ( (lectura / 1024.0) * 5000.0 ) / 10.0;
  
  Serial.print(lectura);
  Serial.print(" MV\t");
  Serial.print("F1: ");
  Serial.print(temp);
  Serial.print(" *C\t");
  Serial.print("F2: ");
  Serial.print(temp2);
  Serial.println(" *C\t");*/
  float val = analogRead(T);
  float mv = ( val/1024.0)*5000;
  float cel = mv/10;
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(1000);
}
