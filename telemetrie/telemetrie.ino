#include <SoftwareSerial.h>

SoftwareSerial hc06(4, 3);

void setup(){
  Serial.begin(9600);
  hc06.begin(9600);
}

void loop(){
  hc06.write("Sa marche");
}
