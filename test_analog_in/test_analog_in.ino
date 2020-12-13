/*
  test_led
  Turns on an LED on for one second, then off, repeatedly.
*/

// Pin 13 is where the on-board LED is connected on most
// Arduino boards (including Teensy 3.0/3.1)
// give it a name:
int boardLed = 13;

// Pin where LED 1 is connected
int led = 2;

// Pin where analog input is connected
int a_in = A0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

float a_in_value;

// the loop routine runs over and over again forever:
void loop() {
  a_in_value = analogRead(a_in);
  Serial.print("analog input is: ");
  Serial.println(a_in_value);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(a_in_value);               // wait for 200 milliseconds
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(a_in_value);               // wait for 800 milliseconds
}
