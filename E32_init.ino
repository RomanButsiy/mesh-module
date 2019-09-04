

void E32_init(void) {
  E32_Serial.begin(9600); 
  while (!E32_Serial);
  if (!driver.init())
    Serial.println("init failed");
}
