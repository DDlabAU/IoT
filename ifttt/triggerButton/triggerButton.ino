// Adafruit IO Digital Input Example
//
// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

/************************ Example Starts Here *******************************/

// set button pin
int buttonPin = 5;

// button state
boolean current = false;
boolean last = false;

// set up the 'digital' feed
AdafruitIO_Feed *digital = io.feed("triggerButton");

void setup() {

  // set button pin as an input
  pinMode(buttonPin, INPUT_PULLUP);

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while (Serial == false);

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  io.run();

  // grab the current state of the button.
  // we have to flip the logic because we are
  // using INPUT_PULLUP.
  if (digitalRead(buttonPin) == LOW) {
    current = true;
  } else {
    current = false;
  }

  // Send til IO hvis den nuværende værdi er false og den tidligere true.
  // Det betyder at knappen lige er blevet sluppet og vi reagerer så på trykket.
  if (current == false && last == true) {
    digital->save("Trigger");
    Serial.println("Trigger");

  }

  // store last button state
  last = current;

}
