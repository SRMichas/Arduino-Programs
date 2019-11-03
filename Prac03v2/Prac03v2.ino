int r1=13,a1=12,v1=11,vu1=10,r2=9,a2=8,v2=7,vu2=6,Ec=2,Tr=3,obj = 1;
boolean ignora = false;
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
  Serial.begin(9600);
}

void loop() {
int pins[] = {v2,r1,vu1,vu1,vu1,vu1,vu1,vu1,r1,r1,r1,a1,a1,v1,v2,r2,vu2,vu2,vu2,vu2,vu2,vu2,r2,r2,r2,a2,a2,v1};
int states [] = {HIGH,HIGH,HIGH,LOW,HIGH,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH,LOW,HIGH,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH,LOW,LOW};
int delays [] = {800,1,800,800,800,800,800,2500,1000,1000,500,1000,500,500,500,1,800,800,800,800,800,2500,1000,1000,1000,1000,750,350};

   for(int i = 0;i<(sizeof(pins) / sizeof(pins[0]));i++){
    double cm = readUltrasonicDistance(Tr, Ec) / 100.0;
  
    if(pins[i] == vu1 || pins[i] == vu2){
      if(cm >= 1 && cm <= 2 && !ignora){
        digitalWrite(pins[i],states[i]);
        delay(delays[i]);
      }else{
        ignora = true;
        if( i == 2 ) 
          delay(2000);
      }
    }else{
      ignora = false;
      digitalWrite(pins[i],states[i]);
      delay(delays[i]);
    }
  }
  
}
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds *0.01723
  return (pulseIn(echoPin, HIGH)*0.01723);
  
}
int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   
   distanceCm = duration * 10 / 292/ 2;   //convertimos a distancia, en cm
   return distanceCm;
}