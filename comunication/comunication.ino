/**/
#include "SoftwareSerial.h"
SoftwareSerial emeteur(2,3);
int b1 = 5 ;
int b2 = 7 ;
int b3 = 8 ;
int b4 = 10 ;
boolean etatB1 ;
void setup() {;
  pinMode(2 , OUTPUT);
  pinMode(3 , OUTPUT);
  emeteur.begin(9600);
  Serial.begin(9600);  
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(b1) == LOW){
      emeteur.print("Batteri");
      emeteur.print("*z");
      Serial.println("Batteri");
      delay(1000);
      emeteur.print("Aucun probleme");
      emeteur.print("*z");
      Serial.println("Aucun probleme");
  }
  if (digitalRead(b2) == LOW){
    emeteur.print("Direction");
    emeteur.print("*z");
    Serial.println("Direction");
    delay(1000);
    emeteur.print("Aucun probleme");
    emeteur.print("*z");
    Serial.println("Aucun probleme");
      
  }
  if (digitalRead(b3) == LOW){
    emeteur.print("");
    emeteur.print("*z");
    Serial.println("Batteri");
    delay(1000);
    emeteur.print("Aucun probleme");
    emeteur.print("*z");
    Serial.println("Aucun probleme");
  }
  if (digitalRead(b4) == LOW){
    emeteur.print("Batteri");
    emeteur.print("*z");
    Serial.println("Batteri");
    delay(1000);
    emeteur.print("Aucun probleme");
    emeteur.print("*z");
    Serial.println("Aucun probleme");
  }
   /*
  etatB1 = digitalRead(b1) ;
  Serial.println(etatB1);
  delay(500);
  etatB1 = 0; */
  
}
