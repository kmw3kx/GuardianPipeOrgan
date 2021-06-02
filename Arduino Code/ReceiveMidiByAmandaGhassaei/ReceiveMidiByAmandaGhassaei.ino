/*Receive Midi
By Amanda Ghassaei
July 2012
http://www.instructables.com/id/Send-and-Receive-MIDI-with-Arduino/
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*/
byte commandByte;
byte noteByte;
byte velocityByte;
void setup(){
  Serial.begin(9600);
 Serial1.begin(31250);
 Serial.println("hi mom");
}
void checkMIDI(){
 do{
 if (Serial1.available()){
 Serial.println("Data Available");
 commandByte = Serial1.read();//read first byte
 noteByte = Serial1.read();//read next byte
 velocityByte = Serial1.read();//read final byte
 Serial.println(commandByte, BIN);
 Serial.println(noteByte, BIN);
 Serial.println(velocityByte, BIN);
 }
 }
 while (Serial1.available() > 2);//when three bytes available
}
void loop(){
 checkMIDI();
}
