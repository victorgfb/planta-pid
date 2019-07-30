
String entrada;

char chr;

void setup() {
  Serial.begin(9600);
  entrada = "0.7";
}

void loop() {

    for(int i = 0; i < entrada.length(); i++){
      Serial.write(entrada[i]);
      delay(100);
    }

    Serial.write('*');

    entrada = "2.3";
//    
//    while(!Serial.available())
//
//    while(Serial.available()){
//      chr = Serial.read();
//      entrada.concat(chr);
//    }

}
