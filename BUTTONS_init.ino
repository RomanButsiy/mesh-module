
void BUTTONS_init(void) {
  HTTP.on("/ButtonsControl", HTTP_GET, []() {
  uint8_t ButtonSet = HTTP.arg("set").toInt() - 1;
  if ((ButtonSet >= 0) && (ButtonSet <= 39)) {
    if (ButtonSet == 0) {
      } 
    Serial.println("OK!");
    HTTP.send(200, "text/plain", "OK"); // Відправляємо відповідь про виконання
 
    } else {
       HTTP.send(400, "text/plain", "Out of range 1-40"); // Відправляємо відповідь про виконання
      }
  });

  HTTP.on("/WriteText", HTTP_GET, []() {
    Serial.println("OK!");
    HTTP.send(200, "text/plain", "OK"); // Відправляємо відповідь про виконання
  });
  
 }
