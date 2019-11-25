# ESP Boards

Dette er DD Labs guide til hvordan man starter med at bruge den Arduino-kompatible WiFi-chip kaldet ESP. Denne chip eksisterer i mange former og i lab'et har vi følgende:
* [WeMos D1 mini](https://wiki.wemos.cc/products:d1:d1_mini#technical_specs)
* [Adafruit Feather Huzzar](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266/overview)
* [NodeMCU](http://www.nodemcu.com/index_en.html)
* [Sparkfun ESP32 Thing](https://learn.sparkfun.com/tutorials/esp32-thing-hookup-guide)


## Installation

For at kunne bruge et esp-board, er I nødt til at gøre følgende:
1. Downloade board-information
2. Installere drivere

### 1: Download board-information  
Åben indstillingerne i Arduino IDE'et ved at trykke ```File``` -> ```Preferences```. Indtast dette url: ```http://arduino.esp8266.com/stable/package_esp8266com_index.json``` i feltet ved navn "Aditional Boards Manager URLs" og tryk "OK".

Åben så Boards Manager ved at klikke ```Tools``` -> ```Board:...``` -> ```Boards Manager```. Søg på "esp" og installer pakken ved navn esp8266 by ESP8266 Community".

### 2: Installer drivere  
Tjek først om der er brug for at installere en driver. Nyere versioner af styresystemet på macbooks skulle efter sigende ikke have brug for at installere drivere.

Du finder ud af om det er nødvendigt således: Vælg først det korrekte board ```WeMos D1 R1``` under ```Tools``` -> ```Board:...```. Hvis der kommer en port frem under ```Tools``` -> ```Port``` når du tilslutter boardet har du ikke brug for at installere en driver. Hvis der ikke kommer en port frem, skal du følge trinnene nedenfor.

Download og installer driveren fra følgende link: [http://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx](http://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx)
Husk at genstarte din computer inden du tester om det virker.

Hvis du bruger en macbook og ovenstående link ikke virker, så prøv dette link: [https://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html#high-sierra](https://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html#high-sierra)  
Husk igen at genstarte inden du tester om det virker.



* Opdater jeres arduino IDE til nyeste version
* Installation
  * Driver:
    * Hent fra: http://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx
      * Der er flere macs der kan have problemer. Virker ovenstående driver ikke, så kan man hente den der passer til ens styresystem [her](https://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html#high-sierra). Det er primært High Sierra der har problemer.
    * Genstart jeres computer efter installation
  * Board:
    * Først skal Arduino IDE'et have et link, så den ved hvorfra den kan installere boardet:
      *  File -> Preferences -> Additional Boards Manager URLs: -> Indsæt her http://arduino.esp8266.com/stable/package_esp8266com_index.json -> Tryk OK
    * Derefter skal selve boardet installeres:
      * Tools -> Board -> Boards Manager -> Søg på "esp8266" -> Installer den nyeste version af "esp8266 by ESP8266 Community"
  * Test at det virker ved at oploade en blink sketch til boardet
    * Den kan i finde under File -> Examples -> ESP8266 -> Blink
    * Husk at vælge det rigtige board: Tools -> Board -> WeMos D1 R2 &Mini

## Platforme

Alle disse boards kan ved hjælp af esp-chippen forbinde til internettet (Sparkfun ESP32 Thing kan endda også forbinde til andre enheder gennem Bluetooth Low Energy). Med denne internetforbindelse har I mulighed for at forbinde arduinoen til andre esp-baserede arduino-boards, til web-services som for eksempel IFTTT (if this then that), trådløst til en p5js sketch og endda også benytte den som et lokalt hotspot som andre enheder kan forbinde til. Hvad I ønsker at forbinde til, vil afgøre hvilken platform der er smartest at benytte til at skabe denne forbindelse.
