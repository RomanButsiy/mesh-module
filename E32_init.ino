

void E32_init(void) {
  E32_Serial.begin(9600, 13, 15, SWSERIAL_8N1, false, 256);
  while (!E32_Serial);
  if (!driver.init())
    Serial.println("E32 init failed");
}
