/*
  test_led
  Turns on an LED on for one second, then off, repeatedly.
*/

// Pin 13 is where the on-board LED is connected on most
// Arduino boards (incouding Teensy 3.0/3.1)
// give it a name:
int boardLed = 13;

// Pin where LED 1 is connected
int led = 14;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for 200 milliseconds
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(800);               // wait for 800 milliseconds
}
