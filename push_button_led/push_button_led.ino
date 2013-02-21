/*
2x2 RGB LED Control
This is for control of Sparkfun's 2x2 RGB Button Pad.
http://www.sparkfun.com/commerce/product_info.php?products_id=9277

Aaron Goselin (Nakor)
Oct 27, 2010

This code is in the public domain.
*/

// Button Grounds
const int buttonMatrix1 = 13;
const int buttonMatrix2 = 2;
const int buttonMatrix3 = 11;
const int buttonMatrix4 = 8;
// LED Grounds
const int ledGnd1 = 12;
const int ledGnd2 = 7;
const int ledGnd3 = 10;
const int ledGnd4 = 9;
// RGB pins
const int redLED = 3;
const int greenLED = 6;
const int blueLED = 5;

// Colour definitions
int red[] = {255, 0, 0};
int green[] = {0, 255, 0};
int blue[] = {0, 0, 255};
int purple[] = {255, 0, 150};
int yellow[] = {255, 255, 0};
int dark[] = {0, 0, 0};

void setup() 
{ 
// Switch Grounds
pinMode(buttonMatrix1, INPUT);
pinMode(buttonMatrix2, INPUT);
pinMode(buttonMatrix3, INPUT);
pinMode(buttonMatrix4, INPUT);

// Led grounds
pinMode(ledGnd1, OUTPUT);
pinMode(ledGnd2, OUTPUT);
pinMode(ledGnd3, OUTPUT);
pinMode(ledGnd4, OUTPUT);

// RGB pins
pinMode(redLED, OUTPUT);
pinMode(greenLED, OUTPUT);
pinMode(blueLED, OUTPUT);

// Serial if you need it 
//Serial.begin(115200);
}

void loop() {

// Pass in the colour of your buttons 1, 2, 3, and 4.
ledColour(yellow, red, purple, green);

// Uniform colour. Pass in the colour array of your choice.
//ledColourU(purple);

// Dark is just off. Use dark to turn any LED off.
//ledColour(dark, dark, dark, dark);

/*
// Check for button presses and output states
// Enable if you want to test your buttons
Serial.print(digitalRead(buttonMatrix1));
Serial.print("\t");
Serial.print(digitalRead(buttonMatrix2));
Serial.print("\t");
Serial.print(digitalRead(buttonMatrix3));
Serial.print("\t");
Serial.println(digitalRead(buttonMatrix4));
*/

}

// Control individual LEDs
// Pass in a colour array for each LED
void ledColour(int led1[], int led2[], int led3[], int led4[])
{
analogWrite(redLED, led1[0]);
analogWrite(greenLED, led1[1]);
analogWrite(blueLED, led1[2]);
// Flicker control
delay(2);
digitalWrite(ledGnd1, LOW);
// Flicker control
delayMicroseconds(1100);
digitalWrite(ledGnd1, HIGH);

analogWrite(redLED, led2[0]);
analogWrite(greenLED, led2[1]);
analogWrite(blueLED, led2[2]);
// Flicker control
delay(2);
digitalWrite(ledGnd2, LOW);
// Flicker control
delayMicroseconds(1100);
digitalWrite(ledGnd2, HIGH);

analogWrite(redLED, led3[0]);
analogWrite(greenLED, led3[1]);
analogWrite(blueLED, led3[2]);
// Flicker control
delay(2);
digitalWrite(ledGnd3, LOW);
// Flicker control
delayMicroseconds(1100);
digitalWrite(ledGnd3, HIGH);

analogWrite(redLED, led4[0]);
analogWrite(greenLED, led4[1]);
analogWrite(blueLED, led4[2]);
// Flicker control
delay(2);
digitalWrite(ledGnd4, LOW);
// Flicker control
delayMicroseconds(1100);
digitalWrite(ledGnd4, HIGH);

}

// Uniform colour
// This doesn't appear to work well with mixed colours.
void ledColourU(int colour[])
{
analogWrite(redLED, colour[0]);
analogWrite(greenLED, colour[1]);
analogWrite(blueLED, colour[2]);
digitalWrite(ledGnd1, LOW);
digitalWrite(ledGnd2, LOW);
digitalWrite(ledGnd3, LOW);
digitalWrite(ledGnd4, LOW); 
}
