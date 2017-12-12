#include <ESP8266WiFi.h>
extern "C" {
  #include <espnow.h>
}

int ledStatus = false;

struct DATA_STRUCTURE {
  uint16_t primeData;
  uint32_t time;
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
  Serial.print("Recieved from ESP MAC: "); Serial.print(MACmaestro);

  DATA_STRUCTURE DS;
  memcpy(&DS, data, sizeof(DS));

      Serial.print(". data: "); Serial.print(DS.primeData);
      Serial.print(". time: "); Serial.println(DS.time);

    //analogWrite(PinLED,DS.primeData);
    led(DS.primeData);
    });

}

void led(int delayTime) {
  ledStatus =! ledStatus;
  digitalWrite(LED_BUILTIN, ledStatus);
  delay(delayTime);
}
