
#ifndef __CONFIGFILE__
#define __CONFIGFILE__
//flag for saving data
bool shouldSaveConfig = true;
// Update these with values suitable for your network.
// CAFE BENE Setting
/*const char* wifi_ssid = "CaffeBene";
const char* wifi_password = "Misugaru";
const char* mqtt_server = "167.205.7.226";
const int   mqtt_port = 1883;
const char* mqtt_user = "/absensi:absensi";
const char* mqtt_password = "12345";*/
// Home Setting
/*char wifi_ssid[34] = "Homeauto";
char wifi_password[34] = "homeauto";
char mqtt_server[40] = "192.168.0.2";
int   mqtt_port = 1883;
char smqtt_port[5] = "1883";
char mqtt_user[40] = "/absensi:absensi";
char mqtt_password[40] = "12345";
char mqtt_keywords1[40] = "absensimachine/feedcard";
char mqtt_keywords2[40] = "absensimachine/control";
*/
// other setting
/*char wifi_ssid[34] = "Windows Phone9171";
char wifi_password[34] = "dodoldodol";
char mqtt_server[40] = "167.205.7.226";
int   mqtt_port = 1883;
char smqtt_port[5] = "1883";
char mqtt_user[40] = "/smkbm3:smkbm3";
char mqtt_password[40] = "smkbm3";
char mqtt_keywords1[40] = "absensi/service";
char mqtt_keywords2[40] = "absensi/service/update";*/

// PPTIK Setting
char wifi_ssid[34] = "MIC - Gigabit";
char wifi_password[34] = "micanjas";
char mqtt_server[40] = "167.205.7.226";
int   mqtt_port = 1883;
char smqtt_port[5] = "1883";
char mqtt_user[40] = "/absensi:absensi";
char mqtt_password[40] = "PPTIK@|PASSWORD";
char mqtt_keywords1[40] = "absensi/service";
char mqtt_keywords2[40] = "absensi/control";

// Tetring s9+ Setting 
/*char wifi_ssid[34] = "Absen123";
char wifi_password[34] = "12345678";
char mqtt_server[40] = "167.205.7.226";
int   mqtt_port = 1883;
char smqtt_port[5] = "1883";
char mqtt_user[40] = "/absensi:absensi";
char mqtt_password[40] = "PPTIK@|PASSWORD";
char mqtt_keywords1[40] = "absensi/service";
char mqtt_keywords2[40] = "absensi/control";*/

/*char wifi_ssid[34] = "MIC - Gigabit";
char wifi_password[34] = "micanjas";
char mqtt_server[40] = "167.205.7.226";
int   mqtt_port = 1883;
char smqtt_port[5] = "1883";
char mqtt_user[40] = "/absensi:absensi";
char mqtt_password[40] = "PPTIK@|PASSWORD";
char mqtt_keywords1[40] = "absensi/service";
char mqtt_keywords2[40] = "absensi/control";*/

// HUAWEI MODEM Setting
/*char wifi_ssid[34] = "HUAWEI-E5577-33CC";
char wifi_password[34] = "kayakbia5a";
char mqtt_server[40] = "167.205.7.226";
int   mqtt_port = 1883;
char smqtt_port[5] = "1883";
char mqtt_user[40] = "/absensi:absensi";
char mqtt_password[40] = "PPTIK@|PASSWORD";
char mqtt_keywords1[40] = "absensi/service";
char mqtt_keywords2[40] = "absensi/control";*/

const long interval = 2000;

uint8_t MAC_array[6];
char MAC_char[18];  
WiFiClient espClient;
PubSubClient client(espClient);
                     
#define RST_PIN  5  // RST-PIN für RC522 - RFID - SPI - Modul GPIO5 
#define SS_PIN  4  // SDA-PIN für RC522 - RFID - SPI - Modul GPIO4 
#define BUZZER  D3 // pcb merah (D3) (kalau hijau, biru D8) 
#define LED1 D8// pcb merah (kalau hijau,biru d4)
#define LED2 D4 
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

void SaveConfigCallback ();
void ReadConfigFile();

#endif
