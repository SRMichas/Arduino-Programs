int v1=13,a1=12,r1=11,v2=9,a2=8,r2=7;
void setup() {
  pinMode(r1, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(v1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(v2, OUTPUT);
}

void loop() {
  /*int pins[] = {r1,v2,v2,v2,v2,a2,a2,r2,r1,v1,
  v1,v1,v1,a1,a1,r2};*/
  int pins[] =      {r2, v1, v1, v1, v1, a1, a1, r1, r2,                  //Primera Seccion
                    v2, v2, v2, v2, a2, a2, r1};                          //Segunda Seccion
  int states [] =   {HIGH, HIGH, LOW, HIGH, LOW, HIGH, LOW, HIGH, LOW,    //Primera Seccion
                    HIGH, LOW, HIGH, LOW, HIGH, LOW, LOW};                //Segunda Seccion
  int delays [] =   {800, 3000, 1000, 1000, 500, 1000, 500, 500, 500,     //Primera Seccion
                    3000, 1000, 1000, 1000, 1000, 750, 350};              //Segunda Seccion
  
  for(int i = 0;i<16;i++){
    digitalWrite(pins[i],states[i]);
    delay(delays[i]);
  }

}
