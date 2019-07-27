
String inputString = "";

void setup() {
  Serial.begin(9600);

}

void loop() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if(inChar != '\0'){
      Serial.write(inChar);
    }
  }
    
}
