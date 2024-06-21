uint8_t getID() {
  // Getting ready for Reading PICCs
  if ( ! mfrc522.PICC_IsNewCardPresent()) { 
    return 0;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) {   
    return 0;
  }

  // Store NUID into nuidPICC array
  for (byte i = 0; i < 4; i++) {
    nuidPICC[i] = mfrc522.uid.uidByte[i];
  }
    
  UIDCard ="";
  Serial.println(F("Scanned PICC's UID:"));
     
  for ( uint8_t i = 0; i < mfrc522.uid.size; i++) {
    UIDCard += String(mfrc522.uid.uidByte[i], HEX);
  }
    
  UIDCard.toUpperCase(); //Capital
  Serial.print("UID:");
  Serial.println(UIDCard);
  Serial.println("End Reading");
  
  mfrc522.PICC_HaltA(); // Stop reading
  Serial.println("ready....");
  return 1;
}
