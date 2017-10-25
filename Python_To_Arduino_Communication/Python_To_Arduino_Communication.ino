const int LED = 13;
String inputString = "";
bool recMessage = false;

void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
  pinMode(LED, OUTPUT);
}

void loop() {

    while (Serial.available())
    {    
      char inChar = (char)Serial.read();
      if (inChar != '~'){
          inputString += inChar;
      }
      else{
          recMessage = true;
      } 
    }


    if (recMessage){
        if (isDigit(inputString.charAt(0))){
            digitalWrite(LED, HIGH); 
            delay(inputString.toInt() * 1000);
            digitalWrite(LED, LOW); 
            inputString = "";
            recMessage = false;
        }    
    }
}


