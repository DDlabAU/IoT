#include <ESP8266WiFi.h>
extern "C" {
  #include <espnow.h>
}

int ledStatus = false;

struct DATA_STRUCTURE {
  uint16_t finger1;
  uint16_t finger2;
  uint16_t finger3;
  uint16_t finger4;
  uint16_t finger5;
  uint8_t unit;
  uint32_t times = 0;
};

void setup () {
  Serial.begin(115200);

  if (esp_now_init()!=0){
    Serial.println("Failed ESP_NOW INIT");
    ESP.restart();
    delay(1);
  }

  Serial.print("Access Point (softAPmac) MAC of this ESP: "); Serial.println(WiFi.softAPmacAddress());
  Serial.print("Station MAC (STA MAC) of this ESP: "); Serial.println(WiFi.macAddress());

  esp_now_set_self_role(2);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop () {
  esp_now_register_recv_cb([](uint8_t *mac, uint8_t *data, uint8_t len) {

  char MACmaestro[6];
  sprintf(MACmaestro, "%02X:%02X:%02X:%02X:%02X:%02X",mac[0],mac[1],mac[2],mac[3],mac[4],mac[5]);
  Serial.print("Recieved from ESP MAC: "); Serial.println(MACmaestro);

  DATA_STRUCTURE DS;
  memcpy(&DS, data, sizeof(DS));

      Serial.print(". finger 1: "); Serial.print(DS.finger1);
      Serial.print(". finger 2: "); Serial.print(DS.finger2);
      Serial.print(". finger 3: "); Serial.print(DS.finger3);
      Serial.print(". finger 4: "); Serial.print(DS.finger4);
      Serial.println(". finger 5: "); Serial.print(DS.finger5);
      Serial.print(". number of data received: "); Serial.print(DS.times);
      Serial.print(". from unit number: "); Serial.println(DS.unit);

    //analogWrite(PinLED,DS.primeData);
    led();
    });

}

void led() {
  ledStatus =! ledStatus;
  digitalWrite(LED_BUILTIN, ledStatus);
  //delay(5);
}
