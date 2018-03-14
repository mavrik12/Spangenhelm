#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <Adafruit_SSD1306.h>
#include <gfxfont.h>
#include <SPI.h>
#include <Wire.h>
//#include <arduino.h>
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


#define OLED_RESET 4
#define ADJ_PIN A0
Adafruit_SSD1306 Display(OLED_RESET);

int r = 0;
int i = 0;

void setup()   {

  Display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)

  // i'll follow the license agreement and display the Adafruit logo
  // and since they were nice enough to supply the libraries
  Display.clearDisplay();
  Display.display();
  delay (1000);

  DrawTitles();

}


void loop() {

  // get some dummy data to display


  r = rand() / 220;
  //r = analogRead(ADJ_PIN);
  //r = r / 7.98;

  Display.setTextSize(2);
  // note set the background color or the old text will still display
  Display.setTextColor(WHITE, BLACK);
  Display.setCursor(0, 33);
  Display.println(Format(r * 7.99 / 204.6, 3, 2));

  //draw the bar graph
  Display.fillRect(r, 50, 128 - r, 10, BLACK);
  Display.fillRect(3, 50, r, 10, WHITE);

  for (i = 1; i < 13; i++) {
    Display.fillRect(i * 10, 50, 2, 10, BLACK);
  }

  // now that the display is build, display it...
  Display.display();


}


void DrawTitles(void) {

  Display.setTextSize(2);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 0);
  Display.println("MARV");

  Display.setTextSize(1);
  Display.setTextColor(WHITE);
  Display.setCursor(0, 19);
  //Display.println("Measured Volts");
  Display.println("Was Here");
  Display.display();

}


String Format(double val, int dec, int dig ) {

  // this is my simple way of formatting a number
  // data = Format(number, digits, decimals) when needed

  int addpad = 0;
  char sbuf[20];
  String fdata = (dtostrf(val, dec, dig, sbuf));
  int slen = fdata.length();
  for ( addpad = 1; addpad <= dec + dig - slen; addpad++) {
    fdata = " " + fdata;
  }
  return (fdata);

}





/*
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
*/

