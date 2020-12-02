void scriviDisplay() {
  Wire.beginTransmission(saa1064);
  Wire.write(1);
  Wire.write(numeri[pag + 10]);
  Wire.write(0);
  Wire.write(numeri[prew]);
  Wire.write(numeri[prog]);

  Wire.endTransmission();
}



void initDisplay()
// turns on dynamic mode and adjusts segment current to 12mA
{
  Wire.beginTransmission(saa1064);
  Wire.write(B00000000); // this is the instruction byte. Zero means the next byte is the control byte
  Wire.write(B01000111); // control byte (dynamic mode on, digits 1+3 on, digits 2+4 on, 12mA segment current
  Wire.endTransmission();
}
void clearDisplay()
{
  Wire.beginTransmission(saa1064);
  Wire.write(1); // start with digit 1 (right-hand side)
  Wire.write(0); // blank digit 1
  Wire.write(0); // blank digit 2
  Wire.write(0); // blank digit 3
  Wire.write(0); // blank digit 4
  Wire.endTransmission();
}
