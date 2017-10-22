const int BTN = 12;            
const int LED = 3;

int ledBrightness = 0;
int ledBrightnessIncrement = 3;
const int LED_INCREMENT_DELAY = 20;
unsigned long lastIncrementTime;

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
  lastIncrementTime = millis();
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
      //if the button was pressed (not released), swap the sign on the increment
      if (currentReading){
          ledBrightnessIncrement = -1 * ledBrightnessIncrement;
      }
  }
  //update the prevReading for the next iteration of the loop
  prevReading = currentReading;


  //check if enough time has passed since the last time the brightness was modified
  if ((millis() - lastIncrementTime) > LED_INCREMENT_DELAY){
      
      ledBrightness += ledBrightnessIncrement;

      //keep value between limits
      if (ledBrightness > 255){
          ledBrightness = 255;
      }
      else if (ledBrightness < 0){
          ledBrightness = 0;
      }

      //write the new value and update the last increment time
      analogWrite(LED, ledBrightness);
      lastIncrementTime = millis();
  }
}
