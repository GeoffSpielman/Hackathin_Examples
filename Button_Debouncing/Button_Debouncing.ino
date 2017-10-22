const int BTN = 12;            
const int LED = 3;

bool ledOn = false;

unsigned long prevChangeTime;
int prevSteadyState = 0;
int prevReading = 0;
int currentReading = 0;
unsigned long debounceTime = 50;

void setup() {
  Serial.begin(9600);
  pinMode(BTN, INPUT);
  pinMode(LED, OUTPUT);
  prevChangeTime = millis();
}

void loop() {
  
  currentReading = digitalRead(BTN);  

  //update the last time the button changed state after every flicker
  if (currentReading != prevReading){
      prevChangeTime = millis();
  }

  //check if a steady state has been reached and it is different from the previous steady state
  if (((millis() - prevChangeTime) > debounceTime) && (currentReading != prevSteadyState)){
  
      //update the button state for next time
      prevSteadyState = currentReading;

      //regular code now that the state of the button is known
      //if the button was pressed (not released), toggle the LED state
      if (currentReading){
          ledOn = !ledOn;
          if (ledOn){
            digitalWrite(LED, HIGH);
          }
          else{
            digitalWrite(LED, LOW);
          }
      }
  }
  //update the prevReading for the next iteration of the loop
  prevReading = currentReading;
}
