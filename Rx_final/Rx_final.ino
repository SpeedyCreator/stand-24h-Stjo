/*Code By DRS : https://www.youtube.com/channel/UCl9vi6y04pBl-RajOrFJI8g*/
/*La communication full-duplex fonctionne correctement*/
/*Récepteur modelisé par la LED bleu*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define led1 2
#define led2 3
#define led3 4
#define led4 5


typedef struct{
  boolean b1=0;
  boolean b2=0;
  int p1=0;
}data;
data payload;


RF24 radio(7, 8); // CE, CSN
const byte addresses[][6] = {"00001", "00002"};
int ack=0;


void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  radio.begin();
  radio.setChannel(125);
  radio.openWritingPipe(addresses[1]); // 00002
  radio.openReadingPipe(1, addresses[0]); // 00001
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(5);
  /****************[ EMIT ]***************************/
  radio.stopListening();
  emitting();
  /**************************************************/
  delay(5);
  /**************[RECEPTION]************************/
  radio.startListening();
  reception();
  /***********************************************/
}

void reception(){
  if(radio.available()){
     radio.read(&payload, sizeof(payload));
     
     if(ack==0){ /*Si la communication est établie alors la fonction startcom est lancé*/
      ack=100;
      startcom();
     }
     map(payload.p1,0,1023,0,255);
     if (payload.b1 == HIGH){
        digitalWrite(led1, HIGH);
     }
     else {
        digitalWrite(led1, LOW);
     }
  }
  else{
    if(ack >1){
      ack = 0;
    }
  }
}

void emitting(){
 
}


void startcom(){ /* est lancé si la communication est établie*/
  
}
