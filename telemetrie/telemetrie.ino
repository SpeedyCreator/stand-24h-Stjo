char i =0;
char  a =0;
char b=0;


void setup(){

 Serial.begin(9600);
 for(i=0;i<25;i++){

    Serial.println('l');}
    Serial.print('\n');
    delay(2000);
}


void loop(){

 for(i=0;i<25;i++){
     for(a=0;a<i;a++){
      if((a==9)||(a==19)||(a==24))
          Serial.println('l');
      else
          Serial.println('d');   
     }
     for(b=0;b<25-i;b++){
          Serial.println('l');
     }


     delay(2000);
  }
}
