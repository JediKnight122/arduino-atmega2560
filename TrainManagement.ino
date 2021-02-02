int p10 = 20;
int gleisnummer;
int weichensignal;
int anzeige_tab[] = {0, 1};
int gleis_tab[] = {0, 1};

void setup() {
  init();


}

void loop() {
  if (p10 == 0) {
    automatik();

  }
  else if (p10 == 1) {
    sensor_enable();
  }

}

void init() {


  DDRA = 0xff; //PORT A als Output für die Siebensegment Anzeige
  DDRL = 0xff; //PORT L als Output für die Weichensignale

  cli();
  EICRA = 15;
  EIMSK = 3;
  sei();
}

void ausgabe() {
  PORTA = anzeige_tab[gleisnummer];
  PORTL = gleis_tab[weichensignal];
}

void sensor_enable() {
  EIMSK = 3;
}

void automatik() {
  EIMSK = 0;
  zeit_5sec();
  gleisnummer++;
}

ISR(INT0_vect) {
  gleisnummer = 1;
}

void zeit_5sec() {

}

