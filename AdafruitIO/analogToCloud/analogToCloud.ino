// AIO Key:
// 2241c4218395b2c49a669bcb27ae76a1d0a6a2d0

// String WLAN_SSID = "...your SSID...";
// String WLAN_PASS = "...your password...";'

// String AIO_USERNAME = "...your AIO username...";
// String AIO_KEY = "...your AIO key...";

String WLAN_SSID = "ddlabwifi";
String WLAN_PASS = "balddbaldd";

String AIO_USERNAME = "ncmikkelsen";
String AIO_KEY = "2241c4218395b2c49a669bcb27ae76a1d0a6a2d0";

void setup() {
  // Setup a feed called 'button' for publishing changes.
  // Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>
  const char BUTTON_FEED[] PROGMEM = AIO_USERNAME "/feeds/button";
  Adafruit_MQTT_Publish button = Adafruit_MQTT_Publish(&mqtt, BUTTON_FEED);
}

void loop() {
  // put your main code here, to run repeatedly:

}
