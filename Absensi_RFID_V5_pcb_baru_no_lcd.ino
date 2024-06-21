#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <EEPROM.h>
ESP8266WebServer server(80);
WiFiClient client;

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 0
#define SS_PIN 16
MFRC522 mfrc522(SS_PIN, RST_PIN);

struct settings {
  char ssid[30];
  char password[30];
  char server_addr[100];
} dughie_setup = {};

//String server_addr    = "staff.smktiannajiyah.sch.id";
//String directory_addr = "/backend/api/v1/rfid/reader_rfid?uid=";
String device_addr      = "&sn=1655647022994";
String id_setup         = "3033BC81C";
  
uint8_t readsuccess;
byte nuidPICC[4];
String payload, address, message, UIDCard, SN, d[10];
int j, k, l, m;

void setup() {
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();
  pinMode(15, OUTPUT);
  
  EEPROM.begin(sizeof(struct settings) );
  EEPROM.get( 0, dughie_setup );

  readsuccess = getID();
  if (readsuccess){
    if (UIDCard == id_setup){
      for (int i = 0; i < 512; i++){
        EEPROM.write(i,0);
      }
      EEPROM.end();
      Serial.println("EEPROM Terhapus");
    }
  }

  setupWifi();
  
  //Serial.println(F("Read Uid data on a MIFARE PICC:"));
  //ShowReaderDetails();
  delay(2000);
}

void loop() {
  server.handleClient();
  digitalWrite(15, HIGH);
  readsuccess = getID();
  if (readsuccess){
    digitalWrite(15, LOW);
    setupWifi();
    storeData();
    if (payload == ""){
      fixBlank();
    }
    else {
      showData();
    }
  }
}
