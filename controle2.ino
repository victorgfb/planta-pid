
String entrada;

char chr;

void setup() {
  Serial.begin(9600);
  entrada = "0.7";
  enviaDados();
}

void enviaDados(){
   for(int i = 0; i < entrada.length(); i++){
      Serial.write(entrada[i]);
      delay(100);
    }  
    Serial.write('*');
}

void esperaRecebimento(){
  while(1){
      if(Serial.available()){
         chr = (char) Serial.read();
         if(chr == 'B'){
            break; 
         }
      }
    }
}

void recebe(){
   entrada = "";
   while(1){
      if(Serial.available()){
        chr = (char) Serial.read();
        if(chr == 'C')
          break;
        entrada.concat(chr);
      }
   }
}

void loop() {
  esperaRecebimento();
  recebe();
  delay(1000);
  enviaDados();
}
