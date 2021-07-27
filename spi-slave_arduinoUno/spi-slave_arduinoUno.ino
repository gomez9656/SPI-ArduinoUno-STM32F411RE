#include<SPI.h>                           

volatile byte SlaveReceived,Slavesend;

void setup(){
  Serial.begin(9600);                     
  
  pinMode(MISO,OUTPUT);                   

  SPCR |= _BV(SPE);                       
  SPI.attachInterrupt();                  
}

ISR (SPI_STC_vect)                        
{
  SlaveReceived = SPDR;                                         
}

void loop()
{              
  Slavesend = 10;      
                              
  SPDR = Slavesend;                       
 
  Serial.println("Master STM32 to Slave Arduino");
  Serial.print("0x");
  Serial.println(SlaveReceived, HEX);                                          
                       
  delay(2000);
}
