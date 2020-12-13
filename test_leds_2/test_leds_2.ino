/*
  test_leds_2
  Flashes two LEDs alternately.
*/

// Pin 13 is where the on-board LED is connected on most
// Arduino boards (incouding Teensy 3.0/3.1)
// give it a name:
int boardLed = 13;

// Pin where LED 1 is connected
int led1 = 14;
// Pin where LED 2 is connected
int led2 = 15;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(boardLed, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  delay(800);               // wait for a second
  digitalWrite(led2, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(led2, LOW);    // turn the LED off by making the voltage LOW
  delay(800);               // wait for a second
}
