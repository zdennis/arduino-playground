 /*
+-------+-------+
|       |       |
|   1   |   3   |
|       |       |--
+-------+-------+--
|       |       |--
|   2   |   4   |--
|       |       |
+-------+-------+
*/

// Button Grounds
const int buttonGround1 = 12;
const int buttonGround2 = 7;
const int buttonGround3 = 13;
const int buttonGround4 = 9;

// LED Grounds
const int ledGround1    = 10;
const int ledGround2    = 11;
const int ledGround3    = 2;
const int ledGround4    = 8;

// RGB Pins
const int redLED        = 3;
const int greenLED      = 6;
const int blueLED       = 5;

// Color definitions
int red[] = {255, 0, 0};
int green[] = {0, 255, 0};
int blue[] = {0, 0, 255};
int purple[] = {255, 0, 150};
int yellow[] = {255, 255, 0};
int dark[] = {0, 0, 0};

void setup(){
  // Switch grounds
  pinMode(buttonGround1, INPUT);
  pinMode(buttonGround2, INPUT);
  pinMode(buttonGround3, INPUT);
  pinMode(buttonGround4, INPUT);

  // LED Grounds
  pinMode(ledGround1, OUTPUT);
  pinMode(ledGround2, OUTPUT);
  pinMode(ledGround3, OUTPUT);
  pinMode(ledGround4, OUTPUT);

  // RGB Pins
  pinMode(redLED,   OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED,  OUTPUT);

  //Serial.begin(9600);           // set up Serial library at 9600 bps
  //Serial.println("Starting...");  // prints hello with ending line break     
}

const int ON = LOW;
const int OFF = HIGH;

int counter = 0;
int interval = 40;

int state = 0;

void loop(){
  int btn1 = digitalRead(buttonGround1);
  int btn2 = digitalRead(buttonGround2);
  int btn3 = digitalRead(buttonGround3);
  int btn4 = digitalRead(buttonGround4);

  setFourLEDs(dark, dark, dark, dark);

 // delay(100);
  if(btn1 == HIGH){
    setLED(ledGround1, red);
//    setFourLEDs(red, dark, dark, dark);
  }
  if(btn2 == HIGH){
    setLED(ledGround2, green);
//    setFourLEDs(dark, green, dark, dark);
  }
  if(btn3 == HIGH){
    setLED(ledGround3, blue);
  //  setFourLEDs(dark, dark, blue, dark);
  }
  if(btn4 == HIGH){
    setLED(ledGround4, yellow);
//    setFourLEDs(dark, dark, dark, yellow);
  }

  
//  int old_state = state;
//  
//  if(counter == interval*4){
//    counter = 0;
//  }
  
//    setLED(ledGround1, red);
//    setLED(ledGround2, red);
//    setLED(ledGround3, red);
//    setLED(ledGround4, red);
//  
//  if(counter >= 0 && counter < interval){
//    state = 1;
//    setLED(ledGround1, red);
//    setLED(ledGround2, green);
//    setLED(ledGround3, blue);
//  } else if(counter >= interval*1 && counter <= interval*2){
//    state = 2;
//    setLED(ledGround1, green);
//    setLED(ledGround2, blue);
//    setLED(ledGround3, red);
//  } else if(counter >= interval*2){
//    state = 3;
//    setLED(ledGround1, blue);
//    setLED(ledGround2, red);
//    setLED(ledGround3, green);
//  }
  
 // if(old_state != state){
    //Serial.begin(9600);           // set up Serial library at 9600 bps
  //  Serial.println("color change occurred");  // prints hello with ending line break     
 // }
  
 // Serial.print(digitalRead(buttonGround1));
//     Serial.println("button press occurred");  // prints hello with ending line break     
//  }
  
 // delay(1000);
 // counter += 1;
}

void setLED(int ledPin, int rgbColor[]){
  digitalWrite(ledPin, ON);
  
  analogWrite(redLED, rgbColor[0]);
  analogWrite(greenLED, rgbColor[1]);
  analogWrite(blueLED, rgbColor[2]);
  
  delayMicroseconds(1100);
  digitalWrite(ledPin, OFF);
}

void setFourLEDs(int colorOne[], int colorTwo[], int colorThree[], int colorFour[]){
  setLED(ledGround1, colorOne);
  setLED(ledGround2, colorTwo);
  setLED(ledGround3, colorThree);
  setLED(ledGround4, colorFour);
}

