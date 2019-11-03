int r1=12,a1=11,v1=10,vu1=13,r2=4,a2=3,v2=2,vu2=5;
void setup() {
  // put your setup code here, to run once:
  pinMode(r1, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(v1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(v2, OUTPUT);
  pinMode(vu1, OUTPUT);
  pinMode(vu2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int pins[] = {v2,r1,vu1,vu1,vu1,vu1,vu1,vu1,r1,r1,r1,a1,a1,v1,v2,r2,vu2,vu2,vu2,vu2,vu2,vu2,r2,r2,r2,a2,a2,v1};
int states [] = {HIGH,HIGH,HIGH,LOW,HIGH,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH,LOW,HIGH,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH,LOW,LOW};
int delays [] = {800,2,2000,800,800,800,800,3000,1000,1000,500,800,800,1000,500,2,2000,800,800,800,800,3000,1000,1000,1000,1000,750,350};

  for(int i = 0;i<(sizeof(pins) / sizeof(pins[0]));i++){
    digitalWrite(pins[i],states[i]);
    delay(delays[i]);
  }
}
