## Agenda for Mini-IoT workshop med fokus på IFTTT.com som API til internettet
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
  * Biblioteker
    * Sketch -> Include Library -> Manage Libraries... ->  Find og installér "Adafruit MQTT Library" og "Adafruit IO Arduino"
  * Test at tingene virker ved at oploade en blink sketch til boardet
    * Den kan i finde under File -> Examples -> 01. Basics -> Blink
    * Husk at vælge det rigtige board: Tools -> Board -> Adafruit HUZZAH ESP8266
* Platforme
  *Blynk.com   
  * io.adafruit.com
    * Som normal bruger
    * Derefter som beta-bruger af io-delen.
  * IFTTT
    * Knyt de to brugere: io.adafruit.com -> Settings -> Connect to IFTTT.com
    * Få hurtigt overblik over hvordan feeds fungerer. De fleste af tingene der gennemgåes vil vi gøre på vores egen måde, så læs for at få en generel forståelse for feeds: https://learn.adafruit.com/adafruit-io-basics-feeds/overview
* Kode
  * AdafruitIO (AIO) informationer:
    * IO_USERNAME: jeres brugernavn på adafruit.com
    * IO_Key:  io.adafruit.com -> Settings -> VIEW AIO KEYS
  * WiFi informationer
    * WiFi_SSID: ddiot
    * WiFi_PASS: ddlabiotworkshop
* Opgaver:
  * Kombiner "publishDigital" med en IFTTT applet
  * Kombiner "receiveDigital" med en IFTTT applet
  * Kombiner "receiveAnalog" med en IFTTT applet
  * Kombiner "publishAnalog" med en IFTTT applet
    * Husk spændingsdeler på den analoge indgang da den maks kan klare 1V

## Links
Information om Feather HUZZAH boardet: https://learn.adafruit.com/adafruit-feather-huzzah-esp8266

Mere om io.adafruit: https://learn.adafruit.com/adafruit-io/overview
