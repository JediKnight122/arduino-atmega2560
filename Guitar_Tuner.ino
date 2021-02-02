int einlesen = 0;
boolean entscheidung = true;

void setup() {
  pinMode (6, OUTPUT);
  TCCR3A = 0;
  TCCR3B = 0;
  OCR3A = 65000;
  TCCR3B = 12;
  TIMKS3 = 2;
  pinMode (PORTA, INPUT);



}

void loop() {
  einlesen = digitalRead(PORTA);


  // E
  if (einlesen >= 1 ) {
    OCR3A = 24390;
    TCCR3B = 10;
  }

  //A
  else if (einlesen >= 2) {
    OCR3A = 18181;
    TCCR3B = 10;
  }
  //d
  else if (einlesen >= 3) {

    OCR3A = 13698;
    TCCR3B = 10;

  }
  //g
  else if (einlesen >= 4) {
    OCR3A = 10204;
    TCCR3B = 10;
  }

  //h
  else if (einlesen >= 5) {
    OCR3A = 65040;
    TCCR3B = 9;
  }

  //e'
  else if (einlesen >= 6) {
    OCR3A = 48632;
    TCCR3B = 9;
  }
}

ISR (TIMER3_COMPA_vect) {
  if (entscheidung == true) {
    digitalWrite(2, HIGH);
    entscheidung = false;
  }
  else {
    digitalWrite(2, LOW);
    entscheidung = true;
  }
}

