const int BTN = 12;            
const int LED = 3;    

bool ledOn = false;

bool buttonPressed = false;
bool buttonReleased = false;

void setup() {
  pinMode(BTN, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  
  if (digitalRead(BTN)){
    buttonPressed = true;
  }

  //check if button has been released
  if (!digitalRead(BTN) && buttonPressed){
    buttonPressed = false;
    
    //toggle the state of the LED
    ledOn = !ledOn;
    if (ledOn){
      digitalWrite(LED, HIGH);
    }
    else{
      digitalWrite(LED, LOW);
    }
  }
}
