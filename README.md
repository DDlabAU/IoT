# ESP Boards
Lab'et har en række boards, der ved hjælp af wifi-chips, ESP8266 og ESP32, kan skabe forbindelse til internettet. Denne funktion bruges ofte til, at sende inputs/outputs mellem enheder over en server. I dette repository er der eksempelkode til størstedelen af disse boards. Nedenfor findes vejledning i at installere nødvendige drivere, biblioteker og i at vælge en passende platform at kommunikere igennem.

## Boards
I lab'et har vi følgende boards til udlån.

* [WeMos D1 mini](https://wiki.wemos.cc/products:d1:d1_mini#technical_specs)
* [Adafruit Feather Huzzar](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266/overview)
* [NodeMCU](http://www.nodemcu.com/index_en.html)
* [Sparkfun ESP32 Thing](https://learn.sparkfun.com/tutorials/esp32-thing-hookup-guide)

Alle disse boards kan ved hjælp af esp-chippen skabe forbindelse til internettet (Sparkfun ESP32 Thing kan endda også forbinde til andre enheder gennem Bluetooth Low Energy - BLE).

Medmindre boardet skal bruges til BLE-kommunikation, kan I vælge frit mellem de listede boards. De forskellige boards varierer i størrelse og mulighed for at forbinde til eksterne batterier. Spørg derfor en ansat for at finde det board, der egner sig bedst til jeres projekt.

## Installation
For at kunne bruge et esp-board, skal I gøre følgende:
1. Downloade board-information
2. Installere drivere

### 1: Download board-information  
Åben indstillingerne i Arduino IDE'et ved at trykke ```File``` -> ```Preferences```. Indtast denne url: ```http://arduino.esp8266.com/stable/package_esp8266com_index.json``` i feltet ved navn "Aditional Boards Manager URLs" og tryk "OK".

Åben så Boards Manager ved at klikke ```Tools``` -> ```Board:...``` -> ```Boards Manager```. Søg på "esp" og installer pakken ved navn esp8266 by "ESP8266 Community".

### 2: Installer drivere  
Tjek først, om der er brug for at installere en driver, ved at følge instruktionerne nedenfor. Nyere versioner af styresystemet på macbooks skulle efter sigende ikke have brug for at installere drivere. Det kan også være at man i forbindelse med et andet projekt har installeret den nødvendige driver. 

Du finder ud af om det er nødvendigt således: Vælg først det korrekte board ```WeMos D1 R1``` under ```Tools``` -> ```Board:...```. Hvis der kommer en port frem under ```Tools``` -> ```Port``` når du tilslutter boardet, har du ikke brug for at installere en driver. Hvis der ikke kommer en port frem, skal du følge trinnene nedenfor. (Ved MacOS Catalina, kan du møde en fejlmeddelelse der siger at en bestemt fil ved navn python3 ikke kan læses, i dette tilfælde kan det være nødvendigt at installere python3 på computeren. Ellers spørg en ansat i labbet.)

Download og installer driveren fra følgende link: [http://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx](http://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx)  
**Husk at genstarte din computer inden du tester om det virker.**

Hvis du bruger en macbook og ovenstående link ikke virker, så prøv dette link: [https://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html#high-sierra](https://kig.re/2014/12/31/how-to-use-arduino-nano-mini-pro-with-CH340G-on-mac-osx-yosemite.html#high-sierra)  
**Husk igen at genstarte inden du tester om det virker.**


## Platforme
Som sagt kan alle lab'ets esp-boards forbinde til internettet via trådløse netværk. Med denne internetforbindelse bliver det, blandt andet, muligt at:
*  forbinde arduinoen til andre esp-baserede arduino-boards
* forbinde (op til flere boards) trådløst til en p5js sketch, både som inputs og outputs
* forbinde til web-services som for eksempel IFTTT (if this then that), der så kan koble jeres projekt med eksisterende digitale platforme og services
* bruge esp-boardet til at lave et wifi-hotspot, der kan fungere som server for hjemmesider til telefoner og computere der forbinder til det

### Forbind boards til hinanden eller P5js: MQTT
Der findes mange platforme, der muliggører en forbindelse mellem boards og p5js. I lab'et anbefaler vi MQTT, som vi også bruger til vores workshops, da det både er letvægt, skalerbart og forholdsvist simpelt.

MQTT er en kommunikationsprotokol, hvormed man via en server, en mqtt broker, snakker med forbundne enheder. Sådan en broker kan man enten selv installere og styre, evt. på en raspberry pi, eller man kan benytte gratis online brokers.
Hvis I er interesserede i at installere og styre jeres egen broker kan I tage et kig på [brokeren Mosquitto](https://mosquitto.org/).  

En nem måde til hurtigt at komme igang med mqtt er med en online broker. Her har vi med stor succes benyttet os af [brokeren Shiftr.io](https://shiftr.io/), som vi også benytter i vores mqtt eksempler.

Uanset hvilken af de to I vælger, skal I først installere et arduino-bibliotek.

Hvis I er interessede i at læse mere om mqtts essentielle funktioner og mere tekniske aspekter af protokollen, er der en [god gennemgang på HiveMQs (udviklere af en tredje broker) hjemmeside](https://www.hivemq.com/mqtt-essentials/).  


#### Installation
Hvis I vil bruge MQTT er det nødvendigt at installere et arduino-bibliotek. Der findes mange forskellige mqtt-bilioteker, men desværre virker de allesammen forskelligt. Hvis I vil anvende de eksempler vi har lagt op, er det derfor vigtigt at I sørger for at installere det samme bibliotek som vi bruger: "MQTT" af "Joel Gaehwiler".

Det installerer I således:
Gå ind i ```Sketch``` -> ```Include Library``` -> ```Manage Libraries```, søg på "mqtt" og installer biblioteket ved navn "MQTT" af Joel Gaehwiler".

![billede af korrekt mqtt bibliotek](./assets/mqtt-bibliotek.png "Det korrekte mqtt bibliotek")


### IFTTT: If This Then That
[If This Then That](https://ifttt.com/) er en platform, der agerer som mellemmand mellem et væld af etablerede platforme, som f.eks. facebook, gmail, vejrtjenester og gps-data fra jeres telefoner.
I kan se eksempler på, hvordan man forbinder til IFTTT i mappen "ifttt".  

### Webserver
Man kan også bruge sit board som en simpel webserver, som man enten forbinder til via et fælles trådløst netværk eller via et lokalt trådløst netværk som boardet selv hoster.
Det kan man for eksempel bruge til, at forbinde til det esp-boardet man bruger i sit design, samt lave ændringer i dets opførsel fra et interface i browseren, og dermed undgå at lave ændringer i selve koden på boardet.
Man kan også bruge det lokale netværk til at servere hjemmesider, der ligger på boardet, til alle de enheder der forbinder til netværket.  
Se eksempler på hvordan man bruger boardet som webserver i mappen "webserver".
