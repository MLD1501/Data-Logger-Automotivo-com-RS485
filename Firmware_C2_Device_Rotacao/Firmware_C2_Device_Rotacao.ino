/*Sketch núcleo de cálculo de rotação*/
#include<Wire.h>
int rotacao=0, rpm1=0;


void setup(void){
Wire.begin();
Serial.begin(9600);
//attachInterrupt(1, print_rpm, LOW);
attachInterrupt(1, rpm, FALLING);
 // inicializa timer1 
  noInterrupts();           // disabilita todas as interrupções
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 31250;            // compare match register 16MHz/256/2Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();             // enable all interrupts


}

ISR(TIMER1_COMPA_vect){          // timer compare interrupt service routine
////mudar os calculos para outros tipos de ignição e qunatidade de cilindros
 ///converte pulsos da bobina em RPM
 
 rpm1=rotacao*60/2;  //4 cilindros com distribuidor 
 //rpm1=rotacao*60;   ////4 cilindros sentelha perdida      
 //rpm1=rotacao*60/3  //// 6 Cilindros
 //rp1=rotacao*60/4 ////8 Cilindros
 //////////////////////
  rotacao=0;
}

void loop(void){
  print_rpm();
}

void rpm(){
rotacao++;
}

void print_rpm(){
byte MasterSend = map(rpm1,0,10000,0,100);    // Converte o valor digital (0 a 1023) para (0 a 127) 
    Wire.beginTransmission(8);                // inicia a transmissão para o arduino escravo (8)
    Wire.write(MasterSend);                   // envia um valor POT convertido de um byte para o escravo
    Wire.endTransmission();                   // Fim da transmissão via I2C 
    Serial.println(String ("RPM ")+rpm1);
    Serial.println(String ("MasterSend ")+MasterSend);
//interrupts();   
}
