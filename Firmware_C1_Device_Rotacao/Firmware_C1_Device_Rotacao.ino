 //I2C SLAVE CODE
//Comunicação I2C entre dois Arduino

#include<Wire.h> 
#include <ICSC.h> // ICSC Library --> (Direitos autorais (c) 2013, Majenko Technologies) -->https://github.com/MajenkoLibraries/ICSC
 
#define ADDR_MASTER  0
#define ADDR_SLAVE   4  //Replace with the number ID of slave
#define BUS_CS       3 // porta do processador 
#define CMD_CALC    'C'
#define CMD_RESULT  'R'
#define count(x) sizeof(x)/sizeof(*x)

const int Enable_Master =  3; 

byte SlaveReceived = 0;
//byte SlaveReceived1 = 0;

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
  Serial.begin(57600);                    //Baud rate p/ comunicação Serial
  
  bus.begin();                           //Comunicação via ICSC
  bus.registerCommand(CMD_CALC, &time);
                 
  Wire.begin(8);                          //Começa a comunicação I2C com Slave Address como 8 no pino (A4, A5)
  Wire.onReceive(receiveEvent);           //Chamada de função quando o Slave recebe valor do mestre
//  Wire.onRequest(requestEvent);           //Chamada de função quando o Mestre solicita valor do Escravo
//pinMode(Enable_Master, OUTPUT);
//digitalWrite(Enable_Master,HIGH);
} 

void loop() {
  bus.process();

 if(Wire.available()){
  receiveEvent();
  }
  delay(2);
}

void receiveEvent (){                   //Função p/ receber rotação via I2C

   SlaveReceived = Wire.read();
   //Serial.println(SlaveReceived); 
}

void time(unsigned char sender, char command, unsigned char len, char *data){
    for( int i=0 ; i<len ; i++){
        memory.b[i] = data[i];
      }
    memory.calc.Device_Data = SlaveReceived;
    memory.calc.Device_ID = ADDR_SLAVE;
 
    //Serial.print("Analog Data");
    //Serial.print(analogRead(A0));
      
    bus.send(ADDR_MASTER, CMD_RESULT, count(memory.b), memory.b);
}
