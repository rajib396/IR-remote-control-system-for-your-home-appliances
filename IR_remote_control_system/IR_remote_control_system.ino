/*
----------------------Unique_Electronic-------------------------------------------
My youtube channel link - https://www.youtube.com/channel/UCK6HlyCjssslr956vJsCFPQ
My email - rm10078@gmail.com
*/



#include <IRremote.h>
#include<EEPROM.h>

const int IRPIN = 2;    //D2 is now IR sensor signal input pin.
const int l0=13;
const int l1=12;
const int l2=11;

  int l0_s;
  int l1_s;
  int l2_s;

void setup(){
pinMode(l0,OUTPUT);
pinMode(l1,OUTPUT);
pinMode(l2,OUTPUT);

Serial.begin(9600);
Serial.println("Enabling IRin");
IrReceiver.begin(IRPIN);
Serial.println("Enabled IRin");

  l0_s=EEPROM.read(0);
  l1_s=EEPROM.read(1);
  l2_s=EEPROM.read(2);
}
void loop()
{
  digitalWrite(l0,EEPROM.read(0));
  digitalWrite(l1,EEPROM.read(1));
  digitalWrite(l2,EEPROM.read(2));
if (IrReceiver.decode()){
Serial.println(IrReceiver.decodedIRData.decodedRawData, DEC); //HEX,DEC,BIN
switch (IrReceiver.decodedIRData.decodedRawData) {
      case 4278222720:
        l0_s = !l0_s;
        EEPROM.update(0,l0_s);
        break;
      case 4027547520:
        l1_s = !l1_s;
        EEPROM.update(1,l1_s);
        break;
      case 3860430720:
        l2_s = !l2_s;
        EEPROM.update(2,l2_s);
        break;
      default:
        break;
}

IrReceiver.resume();
}
//delay(200);
}
