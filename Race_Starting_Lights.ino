int counter=0;
int taster=0;
int rennzeit=300;
boolean umschalten=true;

void setup() {
  pinMode (PORTA, OUTPUT);
  pinMode (6, INPUT);
cli();
TCCR3A=0;
TCCR3B=0;
OCR3A=62500;
TCCR3A=2;
TCCR3B=2;
sei();


}

void loop() {
  
digitalWrite(PORTA, ampelphasen[zustand]);

}

void anzeige(){
  
}

void ausgabeAmpel(){
int ampelphasen[9];
ampelphasen[0]=21;
ampelphasen[1]=10;
ampelphasen[2]=16;
ampelphasen[3]=24;
ampelphasen[4]=28;
ampelphasen[5]=30;
ampelphasen[6]=31;
ampelphasen[7]=0;
ampelphasen[8]=0; //unfertig

}

ISR (TIMER3_COMPA_vect){
schalter =  digitalRead(6);
  if (schalter==0 && zustand==0){
   zustand=1;
   umschalten=true;
  }
 if (umschalten=true){
  zustand++;  
 }

 if (zustand==8){
  rennzeit--;
  anzeige();
 }
}

