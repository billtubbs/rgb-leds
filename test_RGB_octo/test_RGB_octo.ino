/*  This is a variation on the Basic RGB LED Test provided
    by Paul Stoffregen:
    http://www.pjrc.com/teensy/td_libs_OctoWS2811.html

   Instead of lighting all your LEDs at once, this routine
   lights three at a time to conserve power while still 
   allowing you to check if all your LEDs are working.
   
   See the serial output for a log of the LEDs being lit.

  Required Connections
  --------------------
    pin 2:  LED Strip #1    OctoWS2811 drives 8 LED Strips.
    pin 14: LED strip #2    All 8 are the same length.
    pin 7:  LED strip #3
    pin 8:  LED strip #4    A 100 ohm resistor should used
    pin 6:  LED strip #5    between each Teensy pin and the
    pin 20: LED strip #6    wire to the LED strip, to minimize
    pin 21: LED strip #7    high frequency ringining & noise.
    pin 5:  LED strip #8
    pin 15 & 16 - Connect together, but do not use
    pin 4 - Do not use
    pin 3 - Do not use as PWM.  Normal use is ok.

  This test is useful for checking if your LED strips work, and which
  color config (WS2811_RGB, WS2811_GRB, etc) they require.
*/

#include <OctoWS2811.h>

// Adjust these constants to the LED strips you have connected
const int ledsPerStrip = 47;
const int numberOfStrips = 1;
const int boardLed = 13;

DMAMEM int displayMemory[ledsPerStrip*6];
int drawingMemory[ledsPerStrip*6];

// Make sure this configuration is right for your LED strips
const int config = WS2811_RGB | WS2811_800kHz;

OctoWS2811 leds(ledsPerStrip, displayMemory, drawingMemory, config);

void setup() {
  // initialize serial communication  
  Serial.begin(38400);
  
  pinMode(boardLed, OUTPUT);
  
  leds.begin();
  leds.show();
  
}

#define BLK    0x000000
#define RED    0x400000
#define GREEN  0x004000
#define BLUE   0x000040
#define YELLOW 0x404000
#define WHITE  0x404040

int a = 1, b = 2, c = 3;

void loop() {

  // Light the LED on the Teensy board to show the board
  // is working
  digitalWrite(boardLed, HIGH);

  // Turn on 3 LEDs, then pause
  leds.setPixel(a, RED);
  leds.setPixel(b, GREEN);
  leds.setPixel(c, BLUE);
  leds.show();
  delay(100);
  
  // Turn off the LED on the Teensy board so it blinks
  digitalWrite(boardLed, LOW);  
  delay(250);

  // Change LED numbers for next loop
  leds.setPixel(a, BLK);
  a = b;
  b = c;
  c = (c + 1) % (numberOfStrips*ledsPerStrip);
    
}
