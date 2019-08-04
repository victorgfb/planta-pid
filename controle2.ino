
String entrada;

char chr;
float erro[2] = {0,0};
float x = 0;

void setup() {
  Serial.begin(9600);
  enviaDados();
}

void enviaDados(){
   x =  1967.74* erro[0] - 1851.25963*erro[1] + 0.723625*x;

  String aux = String(x);
   for(int i = 0; i < aux.length(); i++){
      Serial.write(aux[i]);
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

  erro[1] = erro[0];
  erro[0] = 1 - entrada.toFloat();
   
}

void loop() {
  enviaDados();
  delay(1000);
  esperaRecebimento();
  recebe();
}
