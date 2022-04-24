#include <SoftwareSerial.h>

SoftwareSerial hc06(4, 3);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  hc06.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

}
