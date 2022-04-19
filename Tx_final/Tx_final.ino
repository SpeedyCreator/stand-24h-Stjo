/*Code By DRS : https://www.youtube.com/channel/UCl9vi6y04pBl-RajOrFJI8g*/
/*La communication full-duplex fonctionne correctement*/
/*Transmetteurmodelisé par la LED Rouge*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define button1 2
#define button2 3
#define button3 4
#define button4 5

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
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
 
  radio.begin();
  radio.setChannel(125);
  radio.openWritingPipe(addresses[0]); // 00001
  radio.openReadingPipe(1, addresses[1]); // 00002
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(5);
  /**********[RECEPTION]***********************/
  radio.startListening();
  reception();
   /********************************************/
    delay(5);
   /****************[EMIT]**********************/
   radio.stopListening();
   emitting();
  /*************************************************/
}

void reception(){

}

void emitting(){
    payload.b1 = digitalRead(button1);
    payload.p1 = analogRead(button2);
    radio.write(&payload, sizeof(payload));
}

void startcom(){ /* est lancé si la communication est établie*/
 
}
