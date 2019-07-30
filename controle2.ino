
String entrada;

char chr;

void setup() {
  Serial.begin(9600);
  entrada = "0.7";
  loop1();
}

void loop1(){
   for(int i = 0; i < entrada.length(); i++){
      Serial.write(entrada[i]);
      delay(100);
    }  
    Serial.write('*');
}

void loop2(){
  while(1){
       chr = (char) Serial.read();
       if(chr == 'B'){
          break; 
       }
    }
}

void loop3(){
   entrada = "";
   while(1){
      while(Serial.available()){
        chr = (char) Serial.read();
        if(chr == 'C')
          break;
        entrada.concat(chr);
      }

      if(chr == 'C')
          break;
   }

}

void loop() {
  loop2();
  loop3();
  delay(1000);
  loop1();
}
