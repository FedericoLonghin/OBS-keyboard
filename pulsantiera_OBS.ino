#define t_pres 100
#include "Keyboard.h"
#include "Wire.h"
byte saa1064 = 0x70 >> 1; // define the I2C bus address for our SAA1064 (pin 1 to GND)
int numeri[18] = {
  63, 6, 91, 79, 102, 109, 125, 7, 127, 111, 119, 124, 57, 94, 121, 113, 0, 84
};

char tasti[11]={0xF1,0xF2,0xF3,0xF4,0xF5,0xF6,0xF7,0xF8,0xF9,0xFA,0xFB};
char lettere[15]={'Q','W','E','R','T','Y','U','I','O','P','A',223,'D','F','G'};
enum pulsanti {
  p1 = 13,
  p2 = 8,
  p3 = 12,
  p4 = 9,
  p5 = 11,
  p6 = 10
};


int prog, prew, pag, valUnita;


void setup() {
  Keyboard.begin();
  Wire.begin(); // start up I2C bus
  delay(500);
  initDisplay();
  pinMode(p1, INPUT_PULLUP);
  pinMode(p2, INPUT_PULLUP);
  pinMode(p3, INPUT_PULLUP);
  pinMode(p4, INPUT_PULLUP);
  pinMode(p5, INPUT_PULLUP);
  pinMode(p6, INPUT_PULLUP);
  clearDisplay();
  Serial.begin(9600);
  scriviDisplay();
}


void loop() {
  controllaTasti();
}


void commuta() {
  switch (pag) {
    case 0:
    case 1:
      prew = pag * 4 + valUnita;
      digita(prew);
      break;
    case 2:
        if (valUnita == 4) {
        digita(8 + valUnita);

      }
      else{
        prew = pag * 4 + valUnita;
        digita(8 + valUnita);

      }

      break;
  }
  scriviDisplay();
}

void commuta(int inutile) {
  prew = pag * 4 + valUnita;


  scriviDisplay();
}



// ''''''''''''''''
