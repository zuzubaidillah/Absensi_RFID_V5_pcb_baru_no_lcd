void fixBlank(){
  if(payload == ""){
    Serial.print("Resend... ");
    l=0;
    while(payload == ""){ 
      Serial.print("Loading...");
      storeData();
      ++l;
      if (payload != ""){
        l=0;
        Serial.print("Succes");
        break;
      }
      else if (l == 3){
        l=0;
        Serial.print("Please wait for minutes...");
        break;
      }
    }
  }
}
