int button;

void setup() {

  pinMode(25, OUTPUT); //1= Eingang gesperrt 0=Eingang offen
  pinMode(21, INPUT); //Taster zum Zurücksetzen. Muss an 21 oder 20 sein. 21 -> INT0_vect

  cli();
  TCNT5 = 0;

  TCCR5A = 0;
  TCCR5B = 7;

  TIMSK5 = 1;

  EICRA = 10;
  EIMSK = 3;

  EICRA = 10;
  sei();
}

void loop() {



  if (TCNT5 >= 10) {
    //TCNT5 ist der externe Zaehler, der selbsständig hochzhaehlt.
    
    EIMSK = 3;
    digitalWrite(25, LOW);

  }
  else {
    
    EIMSK = 0;
    digitalWrite(25, HIGH);
  }
}


ISR(INT0_vect) {
 
    TCNT5 = 0;
  
}

