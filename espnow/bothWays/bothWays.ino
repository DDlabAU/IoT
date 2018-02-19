#include <ESP8266WiFi.h>
extern "C" {
  #include <espnow.h>
}

struct DATA_STRUCTURE {
    uint16_t primeData;
    uint32_t time;
};

void setup() {
  Serial.begin(115200);

  if(esp_now_init()!=0){
    Serial.println("Failed esp_now_init");
    ESP.restart();
    delay(1);
  }
  Serial.print("Access Point (softAPmac) MAC of this ESP: "); Serial.println(WiFi.softAPmacAddress());
  Serial.print("Station MAC (STA MAC) of this ESP: "); Serial.println(WiFi.macAddress());

  // esp_now_set_self_role(3);

  // uint8_t remoteMac[6] = {0x60, 0x01, 0x94, 0x51, 0xEC, 0xCE};
  // uint8_t role = 3;
  // uint8_t channel = 3;
  // uint8_t key[0]={};
  // uint8_t key_len = sizeof(key);
  //
  // esp_now_add_peer(remoteMac,role,channel,key, key_len);

}

void loop() {

}
