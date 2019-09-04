
void BUTTONS_init(void) {
  HTTP.on("/WriteText", HTTP_GET, []() {
    HTTP.send(200, "text/plain", "OK"); // Відправляємо відповідь про виконання
  
  Serial.println("Sending to e32_server");
  // Send a message to e32_server
  uint8_t data[] = "Hello World!";
  driver.send(data, sizeof(data));
  
  driver.waitPacketSent();
  // Now wait for a reply
  uint8_t buf[RH_E32_MAX_MESSAGE_LEN];
  uint8_t len = sizeof(buf);

  if (driver.waitAvailableTimeout(10000)) // At 1kbps, reply can take a long time
  { 
    // Should be a reply message for us now   
    if (driver.recv(buf, &len))
    {
      Serial.print("got reply: ");
      Serial.println((char*)buf);
    }
    else
    {
      Serial.println("recv failed");
    }
  }
  else
  {
    Serial.println("No reply, is e32_server running?");
  }
  });
 }
