const int BTN = 12;            
const int LED = 3;    

bool ledOn = false;

void setup() {
  pinMode(BTN, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (digitalRead(BTN)){
    ledOn = !ledOn;
    if (ledOn){
      digitalWrite(LED, HIGH);
    }
    else{
      digitalWrite(LED, LOW);
    }
  }
}
