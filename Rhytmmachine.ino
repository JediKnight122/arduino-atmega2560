int bitMusterTabelle[16];

bitMusterTabelle[0]= 0x9;
bitMusterTabelle[1]=0x0;
bitMusterTabelle[2]=0x0D;
bitMusterTabelle[3]=0x04;
bitMusterTabelle[4]=0x0A;
bitMusterTabelle[5]=0x00;
bitMusterTabelle[6]=0x09;
bitMusterTabelle[7]=0x00;
bitMusterTabelle[8]=0x09;
bitMusterTabelle[9]=0x00;
bitMusterTabelle[10]=0x0C;
bitMusterTabelle[11]=0x04;
bitMusterTabelle[12]=0x0A;
bitMusterTabelle[13]= 0x00;
bitMusterTabelle[14]= 0x08;
bitMusterTabelle[15]= 0x00;



int counter = 0;
boolean schalter;
void setup() {
  TCCR3A = 0;
  TCCR3B = 0;
  OCR3A = 15625;
  TIMSK3 = 0;
  TCCR3B = 10;
  pinMode(PORTA, OUTPUT);
  pinMode(1, INPUT);

}

void loop() {
  schalter = digitalRead(1);
if (schalter==1){
TIMSK3=2;
}

else {
  TIMSK3=0;
  PORTA=0;
  x=0;
}
}

ISR (TIMER3_COMPA_vect) {
  counter++;

  if (schalter == 1) {
    digitalWrite(PORTA, bitMusterTabelle[counter]);
    if (x==15){
      x=0;
    }
  }
  else {
    digitalWrite(PORTA, 0x00);
  }

}

