#include <ESP8266WiFi.h>
extern "C" {
  #include <espnow.h>
}

int ledStatus = true;
uint8_t thisDevice = 1;
uint32_t runTimes = 0;

struct DATA_STRUCTURE {
  uint16_t finger1;
  uint16_t finger2;
  uint16_t finger3;
  uint16_t finger4;
  uint16_t finger5;
  uint8_t unit;
  uint32_t times;
};

void setup () {
  Serial.begin(115200);

  if (esp_now_init()!=0){
    Serial.println("Failed ESP_NOW INIT");
    ESP.restart();
    delay(1);
  }

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.print("Access Point (softAPmac) MAC of this ESP: "); Serial.println(WiFi.softAPmacAddress());
  Serial.print("Station MAC (STA MAC) of this ESP: "); Serial.println(WiFi.macAddress());

  esp_now_set_self_role(1);

  uint8_t remoteMac[6] = {0x60, 0x01, 0x94, 0x51, 0xEC, 0xCE};
  uint8_t role = 2;
  uint8_t channel = 3;
  uint8_t key[0]={};
  uint8_t key_len = sizeof(key);

  esp_now_add_peer(remoteMac,role,channel,key, key_len);
}

void loop () {

  DATA_STRUCTURE DS;
  // DS.primeData = 1000; //analogRead(A0);
  // delay(20);
  // DS.times = millis();

  DS.finger1 = random(1023);
  DS.finger2 = random(1023);
  DS.finger3 = random(1023);
  DS.finger4 = random(1023);
  DS.finger5 = random(1023);
  DS.unit = thisDevice;
  runTimes += 1;
  DS.times = runTimes;

  // Sending data!!
  //uint8_t *da = NULL // Sends data to all ESPs
  uint8_t da[6] = {0x62, 0x01, 0x94, 0x51, 0xEC, 0xCE};
  uint8_t data[sizeof(DS)]; memcpy(data, &DS, sizeof(DS));
  uint8_t len = sizeof(data);
  esp_now_send(da, data, len);
  led();delay(100);led();


  delay(1000); // increase value if data is lost

  //did the slave receive the messages
  esp_now_register_send_cb([](uint8_t* mac, uint8_t status) {
    char MACslave[6];
    sprintf(MACslave,"%02X:%02X:%02X:%02X:%02X:%02X",mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
    Serial.print(". Sent to ESP MAC: "); Serial.print(MACslave);
    Serial.print(". Recepcion (0=0K - 1=ERROR): "); Serial.println(status);
  });


}


void led() {
  ledStatus =! ledStatus;
  digitalWrite(LED_BUILTIN, ledStatus);
  delay(500);
}
