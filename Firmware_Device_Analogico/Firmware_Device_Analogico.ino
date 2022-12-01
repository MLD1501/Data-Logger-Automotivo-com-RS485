#include <ICSC.h>   //ICSC Library --> (Direitos autorais (c) 2013, Majenko Technologies)
 
#define ADDR_MASTER  0
#define ADDR_SLAVE   3   //Replace with the number ID of slave
#define BUS_CS       3 // porta do processador 
#define CMD_CALC    'C'
#define CMD_RESULT  'R'
#define count(x) sizeof(x)/sizeof(*x)
 
struct CALC{
int Device_Data, 
    Device_ID;     
};

union MEMORY{
   CALC calc;
   char b[sizeof(CALC)];
}
memory;
  
ICSC bus(Serial, ADDR_SLAVE, BUS_CS);
 
void setup(){
    Serial.begin(57600);
    bus.begin();
    bus.registerCommand(CMD_CALC, &time);
}
 
void loop(){
    bus.process();
}
 
void time(unsigned char sender, char command, unsigned char len, char *data){
    for( int i=0 ; i<len ; i++){
        memory.b[i] = data[i];
      }
    memory.calc.Device_Data = analogRead(A6);
    memory.calc.Device_ID = ADDR_SLAVE;
 
    //Serial.print("Analog Data");
    //Serial.print(analogRead(A0));
      
    bus.send(ADDR_MASTER, CMD_RESULT, count(memory.b), memory.b);
}
