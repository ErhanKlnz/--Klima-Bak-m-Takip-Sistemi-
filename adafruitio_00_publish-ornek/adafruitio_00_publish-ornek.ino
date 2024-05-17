// Adafruit IO Publish Example
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

// this int will hold the current count for our sketch
const int veriPini=34; 
float toz=0; 
float yenitoz=0;
int led=32; 

// set up the 'counter' feed
AdafruitIO_Feed *deneme = io.feed("deneme");

void setup() {

Serial.begin(9600); //Verileri okuyabilmek için seri portu başlatıyoruz.
pinMode(led,OUTPUT);
pinMode(veriPini, INPUT);


  // wait for serial monitor to open
  while(! Serial);

  Serial.print("Connecting to Adafruit IO");

  // connect to io.adafruit.com
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

}

void loop() {

  // io.run(); is required for all sketches.
  digitalWrite(led,LOW); 
  delayMicroseconds(280);
  toz=analogRead(veriPini); 
  delayMicroseconds(40);
  digitalWrite(led,HIGH);
  delayMicroseconds(9860);
  delay(1000);
  if (toz>36.455)
  yenitoz=(float(toz/1024)-0.0356)*120000*0.035;
  Serial.println(yenToz);

  io.run();

  // save count to the 'counter' feed on Adafruit IO
 
  Serial.print("sending -> ");
  Serial.println(yeniToz);
  deneme->save(yeniToz);

  // increment the count by 1
  

  // Adafruit IO is rate limited for publishing, so a delay is required in
  // between feed->save events. In this example, we will wait three seconds
  // (1000 milliseconds == 1 second) during each loop.
  delay(3000);

}
