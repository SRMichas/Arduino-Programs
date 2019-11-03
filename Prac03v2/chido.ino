int r1=11,a1=10,v1=9,r2=7,a2=6,v2=5,obj = 2,vu1=12, vu2 = 8;
boolean ignora = true, salta = false;

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
  pinMode(obj,INPUT);
  Serial.begin(9600);
  attachInterrupt(0, cambia, RISING); //Interrupcion para manejar la pulsacion del boton
}

void loop() {
    int pins[] = {v2,r1,vu1,vu1,vu1,vu1,vu1,vu1,r1,r1,r1,a1,a1,v1,v2,r2,vu2,vu2,vu2,vu2,vu2,vu2,r2,r2,r2,a2,a2,v1};
    int states [] = {HIGH,HIGH,HIGH,LOW,HIGH,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH,LOW,HIGH,LOW,HIGH,HIGH,LOW,HIGH,LOW,HIGH,LOW,LOW,HIGH,LOW,HIGH,LOW,LOW};
    int delays [] = {800,1,800,800,800,800,800,2500,1000,1000,500,1000,500,500,500,1,800,800,800,800,800,2500,1000,1000,1000,1000,750,350};
    double cm = 0;
       for(int i = 0;i<(sizeof(pins) / sizeof(pins[0]));i++){
        cm = Distancia(); //Obtiene la distancia
        Serial.println(cm);
        if( pins[i] == vu1){ //Pregunta por el Pin de la vuelta 1
          if( !salta ){ //Bandera para saltar la lectura cuando lo haya hecho la primera vez
                  cm = Distancia(); //Obtiene la distancia
                  salta = true;     //activa la bandera para saltar esta rutina
              }
              if( cm >= 1 && cm <= 5 ){           //Que el objeto este entre 1 y 5 centimetros
                  digitalWrite(pins[i],states[i]); 
                  delay(delays[i]);
              }else if( i == 2)   //Inicio de la ruta alterna cuando no esta activada la flecha
                  delay(2500);
        }else if( pins[i] == vu2){  //Pregunta por el Pin de la vuelta 2
          if( !ignora ){            //Bandera para saber si hay que dar vuelta
                  digitalWrite(pins[i],states[i]);
                  delay(delays[i]);
              }else if( i == 16)  //Inicio de la ruta alterna cuando no esta activada la flecha
                  delay(2500);
        }else{
          digitalWrite(pins[i],states[i]);
                delay(delays[i]);
         }
       }
      ignora = true;
      salta = false;
}
long Distancia(){
  //Limpia el Trigger para eliminar Interferencias y lo apaga durante 2 Micro Segundos
  pinMode(4, OUTPUT);         
  digitalWrite(4, LOW);       
  delayMicroseconds(2);       
  // Prende el Trigger Durante 10 Micro Segundos y luego la Apaga
  digitalWrite(4, HIGH);      
  delayMicroseconds(10);      
  digitalWrite(4, LOW);
  /* Activa el Echo y lee el tiempo en que viaja la Onda para luego multiplicarlo 
   * por 0.01723 para transformarlo a cm
   */
  pinMode(3, INPUT);
  long data = pulseIn(3,HIGH) * 0.01723;
  return data;
  
}
void cambia(){
    ignora = false; 
}
