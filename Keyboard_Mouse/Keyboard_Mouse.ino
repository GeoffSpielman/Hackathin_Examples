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
}

//this code runs continuously
void loop() {
  
  if (digitalRead(TOGGLE_BTN)){
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
      Serial.println("Read left button");  
    }
    else if (digitalRead(RIGHT_BTN)){
      Serial.println("Read right button");
    }
  }
}
