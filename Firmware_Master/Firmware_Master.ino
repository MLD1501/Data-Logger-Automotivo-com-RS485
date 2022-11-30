 #include <ICSC.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5);
 
#define ADDR_MASTER  0
#define BUS_CS       3  // enable 
#define CMD_CALC    'C' // solicita 
#define CMD_RESULT  'R' // processa o recebido 
#define NUM_SLAVES   4  //Replaced by the total number of slaves
#define count(x) sizeof(x)/sizeof(*x)
 
struct CALC{

int Device_Data, Device_ID; 

};
union MEMORY{
   CALC calc;
   char b [sizeof(CALC)]; // linha de codigo que vai ser gerenciadora do "CALC"
}
memory;




ICSC bus(mySerial, ADDR_MASTER, BUS_CS);
unsigned char slave = 0;
 
 
void setup()
{
    Serial.begin(57600);
    mySerial.begin(57600);
    bus.begin();
    bus.registerCommand(CMD_RESULT, &result);
}

 
void loop()
{
//memory.calc.Status_Bomba_1 = 1;
//memory.calc.Status_eletrovalvula_1 = 1;
//memory.calc.Status_eletrovalvula_2 = 1;

  
    bus.process();
 
    if( millis() % 10 == 0 )
    {
        slave   = (slave+1 <= NUM_SLAVES) ? slave+1 : 1;
      //  memory.calc = { millis()/1000,4, operations[slave-1] };
 
        bus.send(slave, CMD_CALC, count(memory.b), memory.b ); // solicitacao dos dados apartir da contagem memoria
  //  onibus envio slave comando  contagem memoria b sobre a memoria b 
    }
   
}
 
void result(unsigned char sender, char command, unsigned char len, char *data) // quando os dados chegar 
{
   for( int i=0 ; i<len ; i++)
   {
     memory.b[i] = data[i];
  }      
    Serial.print(memory.calc.Device_ID);
    Serial.print(",");
    Serial.print(memory.calc.Device_Data);

    Serial.println();

}
