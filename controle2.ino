
String C;
int entrada = 1;// degrau
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
   C = "";
   while(1){
      if(Serial.available()){
        chr = (char) Serial.read();
        if(chr == 'C')
          break;
        C.concat(chr);
      }
   }

  erro[1] = erro[0];
  erro[0] = entrada - C.toFloat();
   
}

void loop() {
  enviaDados();
  esperaRecebimento();
  recebe();
}
