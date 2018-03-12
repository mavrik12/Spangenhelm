#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

//
// Codename: Spangenhelm
// AUTHOR: William Yocom
// VERSION: 0.0.01
// PURPOSE: basic Speed meter
// DATE: 2018.3.6
//

//Display Info
//  128x64
// Blue and yello

//Adafruit Metro Mini
//

#include <SPI.h>
#include <Wire.h>
#include <arduino.h>

// Make the LED Flash on the Board
int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode (led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH); //turns led on high
  delay(8000); // 1 sec delay
  digitalWrite(led, LOW); // Off
  delay(2000); //wait 1 sec
}
