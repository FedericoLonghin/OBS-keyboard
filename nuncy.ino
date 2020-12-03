void controllaNuncy() {
  nuncy.update();
 //  Serial.println(nuncy.analogY);

  if (nuncy.analogX > VALMEDx + OFFSET && millis() >= pros_pres_x) {

    digita(14);
    pros_pres_x = millis() + (t_min_nuncy - (nuncy.analogX - 125));
    Serial.println("DX");
  }

  if (nuncy.analogX < VALMEDx - OFFSET && millis() >= pros_pres_x) {
    digita(15);
    pros_pres_x = millis() + ((t_min_nuncy - VALMEDx) + (nuncy.analogX));
    Serial.println("SX");
  }

  if (nuncy.analogY > VALMEDy + OFFSET && millis() >= pros_pres_y) {
    digita(16);
    pros_pres_y = millis() + (t_min_nuncy - (nuncy.analogY - 125));
    Serial.println("SU");
  }

  if (nuncy.analogY < VALMEDy - OFFSET && millis() >= pros_pres_y) {
    digita(17);
    pros_pres_y = millis() + ((t_min_nuncy - VALMEDy) + (nuncy.analogY ));
    Serial.println("GIU");
  }

  if (nuncy.zButton && millis() >= pros_pres_t) {
    digita(18);
    pros_pres_y = millis() + t_zoom;
    Serial.println("PZ");
  }

  if (nuncy.cButton && millis() >= pros_pres_t) {
    digita(19);
    pros_pres_y = millis() + t_zoom;
    Serial.println("PZ");
  }
}
