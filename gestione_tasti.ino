void controllaTasti() {
  if (!digitalRead(p1)) {
    valUnita = 1;
    commuta();
    //Serial.println(1);
    delay(t_pres);
    while (!digitalRead(p1)) {}
  }
  else if (!digitalRead(p2)) {
    valUnita = 2;
    commuta();
    //Serial.println(2);
    delay(t_pres);
    while (!digitalRead(p2)) {}
  }
  else if (!digitalRead(p3)) {
    valUnita = 3;
    commuta();
    //Serial.println(3);
    delay(t_pres);
    while (!digitalRead(p3)) {}
  }
  else if (!digitalRead(p4)) {
    valUnita = 4;
    commuta();
    //Serial.println(4);
    delay(t_pres);
    while (!digitalRead(p4)) {}
  }
  else if (!digitalRead(p5)) {
    pag = (pag+1)%3;
    if(pag==2&&valUnita==4)valUnita=2;
    commuta();
    //Serial.println(5);
    delay(t_pres);
    while (!digitalRead(p5)) {}
  }
  else if (!digitalRead(p6)) {
    digita(13);
    int temp = prog;
    prog = prew;
    prew = temp;
    valUnita = prew - (4 * pag);
    commuta(1);
    //Serial.println(6);
    delay(t_pres);
    while (!digitalRead(p6)) {}
  }
}
