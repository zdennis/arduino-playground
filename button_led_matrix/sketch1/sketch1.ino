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
const int LED_GROUND_1    = 10;
const int LED_GROUND_2    = 11;
const int LED_GROUND_3    = 2;
const int LED_GROUND_4    = 8;

// RGB Pins
const int redLED        = 3;
const int greenLED      = 6;
const int blueLED       = 5;

const int ON = LOW;
const int OFF = HIGH;

// Color definitions
int red[] = {255, 0, 0};
int green[] = {0, 255, 0};
int blue[] = {0, 0, 255};
int purple[] = {255, 0, 150};
int yellow[] = {255, 255, 0};
int dark[] = {0, 0, 0};

class LedButton {
  public:
    LedButton(int buttonPin, int buttonMode, int ledPin, int ledMode, int color[]){
      _buttonPin = buttonPin;
      _ledPin    = ledPin;
      _color     = color;

      pinMode(_buttonPin, buttonMode);
      pinMode(_ledPin, ledMode);
    }

    int isPressed(){
      return _downstate == 1 || digitalRead(_buttonPin) == HIGH;
    }

    void off(){
      setLED(_ledPin, dark);
    }

    void on(){
      setLED(_ledPin, _color);
    }

    int handlePress(unsigned long currentTime){
      int val = digitalRead(_buttonPin);
      int state = OFF;
      if(_downstate == 1 || val == HIGH ){
        _downstate = 1;
        if(val == HIGH){
          _activatedAt = currentTime >= 0 ? currentTime : 0;
        }
        setLED(_ledPin, _color);
        state = ON;
      }

      if(val == LOW && _activatedAt > 0){
        if(currentTime - _activatedAt >= 200){
          _downstate = 0;
          _activatedAt = 0;
          state = OFF;
        }
      }
      return state;
    }

  private:
    int _buttonPin;
    int _ledPin;
    int _downstate;
    int *_color;
    unsigned long _activatedAt;

    void setLED(int ledPin, int rgbColor[]){
      digitalWrite(ledPin, ON);

      analogWrite(redLED, rgbColor[0]);
      analogWrite(greenLED, rgbColor[1]);
      analogWrite(blueLED, rgbColor[2]);

      delayMicroseconds(1100);
      digitalWrite(ledPin, OFF);
    }

};

LedButton* button1;
LedButton* button2;
LedButton* button3;
LedButton* button4;

void setup(){
  button1 = new LedButton(buttonGround1, INPUT, LED_GROUND_1, OUTPUT, red);
  button2 = new LedButton(buttonGround2, INPUT, LED_GROUND_2, OUTPUT, green);
  button3 = new LedButton(buttonGround3, INPUT, LED_GROUND_3, OUTPUT, blue);
  button4 = new LedButton(buttonGround4, INPUT, LED_GROUND_4, OUTPUT, yellow);

  // RGB Pins
  pinMode(redLED,   OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED,  OUTPUT);

  Serial.begin(9600);
}

void loop(){
  unsigned long current_time = millis();
  LedButton* buttons[] = { button1, button2, button3, button4 };

  // Make sure all buttons start in an off state. We will turn
  // them on if they need to be on.
  for(int i=0; i<4 ; i++){
    buttons[i]->off();
  }

  for(int i=0; i<4 ; i++){
    if(buttons[i]->handlePress(current_time) == ON){
      break;
    }
  }

}
