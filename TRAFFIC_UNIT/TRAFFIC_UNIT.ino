#include <SoftwareSerial.h>
SoftwareSerial R1(6, 7);
SoftwareSerial R2(4, 5);
SoftwareSerial R3(2, 3);
SoftwareSerial R4(0, 1); //RX=0 TX=1

const int L1 = 8;
const int L2 = 9;
const int L3 = 10;
const int L4 = 11;
const char pass[]="1234567890ab";

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
R1.begin(9600);
R2.begin(9600);
R3.begin(9600);
R4.begin(9600);
digitalWrite(L1,LOW);
digitalWrite(L2,LOW);
digitalWrite(L3,LOW);
digitalWrite(L4,LOW);

}

void loop() {
  int i,count;
 while(1)
{
  R1.listen();
  if(R1.available())
  {
    count=0;
    for(i=0;i<12;i++)
    {
      if(pass[i]== R1.read())
      count++;
    }
    if(count>=11)
    {
      digitalWrite(L1,HIGH);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
    }
  }
  
  R2.listen();
  if(R2.available())
  {
    count=0;
    for(i=0;i<12;i++)
    {
      if(pass[i]== R2.read())
      count++;
    }
    if(count>=11)
    {
      digitalWrite(L2,HIGH);
      digitalWrite(L1,LOW);
      digitalWrite(L3,LOW);
      digitalWrite(L4,LOW);
    }
  }
  
  R3.listen();
  if(R3.available())
  {
    count=0;
    for(i=0;i<12;i++)
    {
      if(pass[i]== R3.read())
      count++;
    }
    if(count>=11)
    {
      digitalWrite(L3,HIGH);
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L4,LOW);
    }
  }
  
  R4.listen();
  if(R4.available())
  {
    count=0;
    for(i=0;i<12;i++)
    {
      if(pass[i]== R4.read())
      count++;
    }
    if(count>=11)
    {
      digitalWrite(L4,HIGH);
      digitalWrite(L1,LOW);
      digitalWrite(L2,LOW);
      digitalWrite(L3,LOW);
    }
  }
  
}
}
