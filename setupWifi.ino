void setupWifi(){
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    WiFi.mode(WIFI_STA);
    WiFi.begin(dughie_setup.ssid, dughie_setup.password);
    Serial.println(dughie_setup.ssid);
    l=0;
    while(WiFi.status() != WL_CONNECTED){ 
      Serial.print("Menghubungkan");
      delay(2000);
      ++l;
      if (WiFi.status() == WL_CONNECTED){
        l=0;
        Serial.print("Connected!");
        Serial.println("Terhubung ke :");
        Serial.println(dughie_setup.ssid);
        break;
      }
      else if (l == 15){
        l=0;
        WiFi.mode(WIFI_AP);
        WiFi.softAP("WiFi-Absensi", "12345678");
        Serial.println("\n Failed to Connect.");
        break;
      }
    }
    Serial.println(WiFi.localIP());
    
    server.on("/",  handlePortal);
    server.begin();
    //delay(2000);
  }
}
