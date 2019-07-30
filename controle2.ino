
String inputString = "";

void setup() {
  Serial.begin(9600);
}

void loop() {
    String entrada = "0.5";

    for(int i = 0; i < entrada.length() +1; i++){
      Serial.write(entrada[i]);
    }

    delay(3000);
}
