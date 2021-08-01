/*
----------------------Unique_Electronic-------------------------------------------
My youtube channel link - https://www.youtube.com/channel/UCK6HlyCjssslr956vJsCFPQ
My email - rm10078@gmail.com
*/



#include <IRremote.h>
const int IRPIN = 2;    //D2 is now IR sensor signal input pin.
void setup(){
Serial.begin(9600);
Serial.println("Enabling IRin");
IrReceiver.begin(IRPIN);
Serial.println("Enabled IRin");
}
void loop()
{
if (IrReceiver.decode()){
Serial.println(IrReceiver.decodedIRData.decodedRawData, DEC); //HEX,DEC,BIN
IrReceiver.resume();
}
delay(200);
}
