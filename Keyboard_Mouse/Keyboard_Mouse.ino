#include <Keyboard.h>
#include <Mouse.h>

const int TOGGLE_BTN = 2;
const int LEFT_BTN = 12;
const int RIGHT_BTN = 11;              
const int LED = 10;    

bool toggleOn = false;

//this code runs once
void setup() {
  //create connection to Serial Monitor (Tools -> Serial Monitor or press Ctrl + Shift + M)
  Serial.begin(9600);
  //declare pins
  pinMode(TOGGLE_BTN, INPUT);
  pinMode(LEFT_BTN, INPUT);
  pinMode(RIGHT_BTN, INPUT);
  pinMode(LED, OUTPUT);

  Keyboard.begin();
  Mouse.begin();
}

//this code runs continuously
void loop() {
  
  if (digitalRead(TOGGLE_BTN)){
    //invert the state of the boolean variable
    toggleOn = !toggleOn;
    if (toggleOn){
      digitalWrite(LED, HIGH);
    }
    else{
      digitalWrite(LED, LOW);
    }
  }
  
  if (toggleOn) {
    if (digitalRead(LEFT_BTN)){
      Keyboard.print("LB\n"); //Keyboard.println() doesn't actually put text on the next line?
      //keyboard doesn't respond instantaneously, allow 2 millisecond delay
      delay(2);  
    }
    else if (digitalRead(RIGHT_BTN)){
      //motion onscreen is always relative to the cursor's current location
      Mouse.move(1, 2, 0); // parameters: xVal, yVal, scroll wheel
      //mouse doesn't respond instantaneously, allow 2 millisecond delay
      delay(2);
    }
  }
}
