/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int LED = 13;
int fsrAnalogPin = 0;
int fsrReading;
int LEDbrightness;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  fsrReading = analogRead(fsrAnalogPin);
  
  LEDbrightness = map(fsrReading, 0, 1023, 0, 255);
  
  if(fsrReading < 3){
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
 
  delay(10);
}
