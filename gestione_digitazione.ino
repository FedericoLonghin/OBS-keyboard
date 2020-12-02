void digita(char lettera) {
 // Keyboard.press(KEY_LEFT_GUI);
 // Keyboard.press(224+lettera);
  if(lettera!=lettere[11]) Keyboard.press(0x82);
  Keyboard.press(lettere[lettera-1]);
  delay(100);
  Keyboard.releaseAll();
}
