# Connected devices/Internet of Things

#### Guide til ESP moduler
Dette er DD Labs guide til hvordan man starter med at bruge den Arduino-kompatible WiFi-chip kaldet ESP. Denne chip eksisterer i mange former og i lab'et har vi følgende:
* [WEMOS D1 mini](https://wiki.wemos.cc/products:d1:d1_mini#technical_specs)
* [Adafruit Feather Huzzar](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266/overview)
* [NodeMCU](http://www.nodemcu.com/index_en.html)
* [Sparkfun ESP32 Thing](https://learn.sparkfun.com/tutorials/esp32-thing-hookup-guide) (der er endnu ikke en guide klar til denne)

Der findes mange forskellige platforme der understøtter ESP og flere af dem kan findes her ved at klikke ind i de ovenstående mapper. Snak gerne med en ansat i lab'et om en introduktion til de forskellige muligeder.


#### Få hul igennem til ESP:
* Opdater jeres arduino til nyeste version
* Installation
  * Driver:
    * Hent fra: http://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx
    * Genstart jeres computer efter installation
  * Board:
    * Først skal arduino have et link, så den ved hvorfra den kan installere boardet:
      *  File -> Preferences -> Additional Boards Manager URLs: -> Indsæt her http://arduino.esp8266.com/stable/package_esp8266com_index.json -> Tryk OK
    * Derefter skal selve boardet installeres:
      * Tools -> Board -> Boards Manager -> Søg på "esp8266" -> Installer den nyeste version af "esp8266 by ESP8266 Community"
  * Test at tingene virker ved at oploade en blink sketch til boardet
    * Den kan i finde under File -> Examples -> 01. Basics -> Blink
    * Husk at vælge det rigtige board: Tools -> Board -> Adafruit HUZZAH ESP8266
