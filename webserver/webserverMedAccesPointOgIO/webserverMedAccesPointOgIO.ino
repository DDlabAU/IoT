#include <Arduino.h>

#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

//to IP addresse objekter:
IPAddress         apIP(10, 10, 13, 37);   //Acess pointets IP addresse
IPAddress 		  NMask(255, 255, 255, 0);  //netmask (subnet) ... Man behøver ikke vide had det er...
	
// DNS server
const byte DNS_PORT = 53;
DNSServer dnsServer;

//Function declarations:
void handleRoot();
void handleToggle();
void handleNotFound();

//WIFI SETTINGS:
const char* ssid = "featherAP";
const char* key  = "OMGWTFDDLABFTW"; //hvis der skal være kode på...

//Batt:
static unsigned battPin=A0;
unsigned long ADCfiltered=1; //default to 0V
float vBatt=14;
unsigned int filterBeta=10;


//init http server on port 80:
ESP8266WebServer server(80);

//hardware stuff:
const unsigned int GPIOpin = BUILTIN_LED; // D1 hvis man bruger wemos relay shield
bool GPIOstate=true; // True=off , false=on, fordi logikken er inverteret på den indbyggede LED.


void setup() {
  Serial.begin(115200);
  WiFi.hostname("DDIOT");
  
  //opsætning af accesspoint:
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, NMask);

  //start access point...
  //Argumenterne er: (NetværksNavn , KODE , kanal)  
  //hvis koden er en tom streng: "" startes netværket uden kode.
  WiFi.softAP(ssid, ""/*key*/,10); 

  // if DNSServer is started with "*" for domain name, 
  // it will reply with the provided IP to all DNS requests
  dnsServer.setErrorReplyCode(DNSReplyCode::NoError); //lad som om alt er fint...
  dnsServer.start(DNS_PORT, "*", apIP); //giv apIP addressen som svar på alle (*) DNS forespørgsler...
 
  pinMode(GPIOpin,OUTPUT);
  digitalWrite(GPIOpin,GPIOstate);

  //Vi laver et lavpasfilter som en en slags gennemsnitsberegning af den analoge værdi på battPin
  //denne for-løkke sørger for at lave en bunke målinger som gennemsnittet kan tage udgangspunkt i:
  for(int a=0; a<=filterBeta*4; a++) ADCfiltered=((ADCfiltered*filterBeta)+analogRead(battPin))/(filterBeta+1); //low pass filtering of ADC0

  vBatt=(float)14/(float)1023*(float)ADCfiltered; //ADC (0-1023) -> voltage (0-14)

  delay(500);

  //Serial.print("ADCfiltered @:");
  //Serial.println(ADCfiltered);

  Serial.println();
  Serial.print("WiFi up!");
  Serial.print("  IPv4: ");
  Serial.println(WiFi.softAPIP());

  if (MDNS.begin("ddiot")) {
  	MDNS.addService("http", "tcp", 80);
    Serial.println("MDNS responder started, see you at http://ddiot.local");
  }

  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  server.onNotFound(handleRoot);

  server.begin();
  Serial.println("HTTP server started");

}

//only make conversions every 1/4 seconds, to make time for web stuff
unsigned long lastConversion = 0;
unsigned long conversionDelay = 250; //ms between ADC conversions
void loop() {

if (millis()> lastConversion+conversionDelay){
	for(int a=0; a<=filterBeta; a++) ADCfiltered=((ADCfiltered*filterBeta)+analogRead(battPin))/(filterBeta+1); //low pass filtering of ADC0
	vBatt=(float)14/(float)1023*(float)ADCfiltered; //ADC -> voltage
	lastConversion=millis();
	// Serial.print("ADCfiltered @:");
	// Serial.println(ADCfiltered);
	// Serial.print("vBatt @:");
	// Serial.println(vBatt);
}

//if(vBatt<11) digitalWrite(GPIOpin,LOW); //safety

server.handleClient();

dnsServer.processNextRequest();

yield();

}

//http stuff:
void handleRoot() {
  Serial.println("client trying to access /");
  //server.send(200, "text/plain", "hello from esp8266!");
  server.sendContent("HTTP/1.1 200 OK\r\n"); //send new p\r\nage
  server.sendContent("Content-Type: text/html\r\n");
  server.sendContent("\r\n");
  server.sendContent("<HTML>\r\n");
  server.sendContent("<HEAD>\r\n");
  server.sendContent("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"); //zoom to width of window
  server.sendContent("<meta name='apple-mobile-web-app-capable' content='yes' />\r\n");
  server.sendContent("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />\r\n");
  server.sendContent("<link rel='stylesheet' type='text/css' href='https://moore.dk/doorcss.css' />\r\n"); //External CSS
  server.sendContent("<TITLE>DDlab IOT demo.</TITLE>\r\n");
  server.sendContent("</HEAD>\r\n");
  server.sendContent("<BODY>\r\n");
  if(GPIOstate) server.sendContent("<H1>GPIO is HIGH. (BUILTIN_LED is off)</H1>\r\n");
  else server.sendContent("<H1>GPIO is LOW. (BUILTIN_LED is on)</H1>\r\n");
  server.sendContent("<hr />\r\n");
  server.sendContent("<H2>vBatt: ");
  server.sendContent(String(vBatt));
  server.sendContent("</H2>\r\n");
  //server.sendContent("<br />\r\n");
  server.sendContent("<br />\r\n");
  if(!GPIOstate) server.sendContent("<a class=\"red\" href=\"/toggle\"\">Shut that GPIO down!</a>\r\n");
  else server.sendContent("<a href=\"/toggle\"\">Light that GPIO up!</a>\r\n");
  server.sendContent("<br />\r\n");
  if(!GPIOstate) server.sendContent("<H3>Here's some text you only see when the GPIO is LOW...</H3>");
  server.sendContent("</BODY>\r\n");
  server.sendContent("</HTML>\r\n");


}

void handleToggle(){

	GPIOstate=!GPIOstate;
	digitalWrite(GPIOpin,GPIOstate);
	if(GPIOstate)	Serial.println("GPIO HIGH..");
	else Serial.println("GPIO LOW..");
	//reply to client with redirect to root, to update status of light in browser
	server.sendContent("HTTP/1.1 303 See Other\r\n");
  	server.sendContent("Location: /\r\n");
  	server.sendContent("\r\n"); //EOT
}