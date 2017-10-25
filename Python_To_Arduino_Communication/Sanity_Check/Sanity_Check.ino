String inputString = "";
bool recMessage = false;

void setup() {
  Serial.begin(9600);

  //wait for some serial connection
   while (!Serial);
   Serial.println("--- Serial Connection Established ---");
}

void loop() {
  //consume everything in the serial buffer
  while (Serial.available())
  {    
    char inChar = Serial.read();
    if (inChar != '~'){
        inputString += inChar;
    }
    else{
        recMessage = true;
    } 
  }
  
  if (recMessage){
      Serial.print("Arduino received: ");
      Serial.println(inputString);
      inputString = "";
      recMessage = false;
  }  
}


