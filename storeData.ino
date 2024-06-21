 void storeData(){
  //equate with your Server address (computer's IP address) and your directory application
  address ="http://"+server_addr+directory_addr+UIDCard+device_addr;
  //address ="http://staff.smktiannajiyah.sch.id/backend/api/v1/rfid/reader_rfid?uid="+UIDCard+"&sn=1642675574822";
      
  HTTPClient http;
  http.begin(client, address);
  int httpCode = http.GET();        //Send the GET request
  //Serial.print("Response Code: "); 
  Serial.println(address);
  payload = http.getString();//Get the response payload from server
  Serial.print("Returned data from Server:");
  Serial.println(payload);    //Print request response payload
  http.end();   //Close connection
  delay(1000);
}
