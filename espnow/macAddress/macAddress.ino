#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  Serial.print("Access Point (softAPmac) MAC of this ESP: "); Serial.println(WiFi.softAPmacAddress());
  Serial.print("Station MAC (STA MAC) of this ESP: "); Serial.println(WiFi.macAddress());
}

void loop() {

}
