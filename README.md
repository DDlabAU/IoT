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
  * Test at tingene virker ved at oploade en blink sketch til boardet
    * Den kan i finde under File -> Examples -> 01. Basics -> Blink
    * Husk at vælge det rigtige board: Tools -> Board -> WEMOS D1 mini
  
