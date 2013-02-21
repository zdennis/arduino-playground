/*
+-------+-------+
|       |       |
|   3   |   4   |
|       |       |--
+-------+-------+--
|       |       |--
|   2   |   1   |--
|       |       |
+-------+-------+
*/

// Button Grounds
const int buttonGround1 = 12; //13;
//const int buttonGround2 = 2;
//const int buttonGround3 = 11;
//const int buttonGround4 = 8;

// LED Grounds
const int ledGround1    = 11;
const int ledGround2    = 8;
const int ledGround3    = 10;
const int ledGround4    = 2;

// RGB Pins
const int redLED        = 3;
const int greenLED      = 5;
const int blueLED       = 6;

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
//  pinMode(buttonGround2, INPUT);
//  pinMode(buttonGround3, INPUT);
//  pinMode(buttonGround4, INPUT);

  // LED Grounds
  pinMode(ledGround1, OUTPUT);
  pinMode(ledGround2, OUTPUT);
  pinMode(ledGround3, OUTPUT);
  pinMode(ledGround4, OUTPUT);

  // RGB Pins
  pinMode(redLED,   OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED,  OUTPUT);

   Serial.begin(9600);           // set up Serial library at 9600 bps
   Serial.println("Starting...");  // prints hello with ending line break     
}

const int ON = LOW;
const int OFF = HIGH;

int counter = 0;
int interval = 40;

int state = 0;

void loop(){
  int old_state = state;
  
  if(counter == interval*4){
    counter = 0;
  }
  
  if(counter >= 0 && counter < interval){
    state = 1;
    setLED(ledGround1, red);
    setLED(ledGround2, green);
    setLED(ledGround3, blue);
  } else if(counter >= interval*1 && counter <= interval*2){
    state = 2;
    setLED(ledGround1, green);
    setLED(ledGround2, blue);
    setLED(ledGround3, red);
  } else if(counter >= interval*2){
    state = 3;
    setLED(ledGround1, blue);
    setLED(ledGround2, red);
    setLED(ledGround3, green);
  }
  
  if(old_state != state){
    //Serial.begin(9600);           // set up Serial library at 9600 bps
  //  Serial.println("color change occurred");  // prints hello with ending line break     
  }
  
  Serial.print(digitalRead(buttonGround1));
//     Serial.println("button press occurred");  // prints hello with ending line break     
//  }
  
  delay(1000);
  counter += 1;
}

void setLED(int ledPin, int rgbColor[]){
  digitalWrite(ledPin, ON);
  
  analogWrite(redLED, rgbColor[0]);
  analogWrite(greenLED, rgbColor[1]);
  analogWrite(blueLED, rgbColor[2]);
  
  delayMicroseconds(1100);
  digitalWrite(ledPin, OFF);
}

