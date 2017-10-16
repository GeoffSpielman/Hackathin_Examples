const int BTN = 2;                // pushbutton pin
const int ARDUINO_LED =  13;      // the LED pin built into the arduino
const int BREADBOARD_LED = 10;    // the LED on the breadboard

int buttonState = 0;

//this code runs once
void setup() {
  //create connection to Serial Monitor (Tools -> Serial Monitor or press Ctrl + Shift + M)
  Serial.begin(9600);
  //declare both LED pins as an outputs and button pin as an input
  pinMode(ARDUINO_LED, OUTPUT);
  pinMode(BREADBOARD_LED, OUTPUT);
  pinMode(BTN, INPUT);
}

//this code runs continuously
void loop() {
  
  //read in the stae of the button (HIGH = 1, LOW = 0)
  buttonState = digitalRead(BTN);
  
  if (buttonState == HIGH) {
    //set the LED pins to HIGH
    digitalWrite(ARDUINO_LED, HIGH);
    digitalWrite(BREADBOARD_LED, HIGH);
    //print the word ON to the serial monitor (your screen)
    Serial.println("ON");
  } 
  else {
    digitalWrite(ARDUINO_LED, LOW);
    digitalWrite(BREADBOARD_LED, LOW);
    Serial.println("OFF");
  }
}
