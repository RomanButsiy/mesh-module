/*
    Модуль на ESP8266 для проектування mesh-мережі, тощо.
    - Розробив Roman
    - Канал на YouTube: https://goo.gl/x8FL2o
    - Схема: https://easyeda.com/Targaryen/LoRa_Mesh_Node
*/

#include <ESP8266HTTPUpdateServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266SSDP.h>
#include <ArduinoJson.h>  // Ставимо через менеджер бібліотек
#include <time.h>
#include <SPI.h>
#include <FS.h>

//--------------------------------------------------------------------
//  Default data:
//--------------------------------------------------------------------
// Об'єкт для оновлення web сторінки
ESP8266HTTPUpdateServer httpUpdater;
// Web інтерфейс для пристрою
ESP8266WebServer HTTP(80);
// Для файлової системи
File fsUploadFile;

String configSetup = "{}";
String configJson = "{}";

void setup() {
  Serial.begin(115200);
  delay(5);
  Serial.println("");
  Serial.println("Start FS");
  FS_init();
  Serial.println("Step FileConfig");
  configSetup = readFile("config.json", 4096);
  jsonWrite(configJson, "SSDP", jsonRead(configSetup, "SSDP"));
  Serial.println(configSetup);
  Serial.println("Start WIFI");
  WIFIinit();
  Serial.println("Start Time");
  Time_init();
  Serial.println("Start SSDP");
  SSDP_init();
  Serial.println("Start WebServer");
  HTTP_init();
  LANG_init();
  BUTTONS_init();
  NRF24L01_init();
  E32_init();
  Serial.println("");
  Serial.println("Time Ready!");
  Serial.println(GetTime());
  Serial.println(GetDate());
}

void loop() {
  HTTP.handleClient();
}
