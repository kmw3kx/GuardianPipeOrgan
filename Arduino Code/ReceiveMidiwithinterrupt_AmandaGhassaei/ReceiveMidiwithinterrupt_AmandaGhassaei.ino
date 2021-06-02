/*Receive Midi with interrupt
By Amanda Ghassaei
July 2012
<a href="https://www.instructables.com/id/Send-and-Receive-MIDI-with-Arduino/">

https://www.instructables.com/id/Send-and-Receive-...>

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
  
  cli();//stop interrupts

  //set timer2 interrupt every 128us
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 7.8khz increments
  OCR2A = 255;// = (16*10^6) / (7812.5*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
  // Set CS11 bit for 8 prescaler
  TCCR2B |= (1 << CS11);   
  // enable timer compare interrupt
  TIMSK2 |= (1 << OCIE2A);
  
  sei();//allow interrupts
  
}


ISR(TIMER2_COMPA_vect) {//checks for incoming midi every 128us
  do{
    if (Serial1.available()){
      commandByte = Serial1.read();//read first byte
      noteByte = Serial1.read();//read next byte
      velocityByte = Serial1.read();//read final byte
       Serial.println(commandByte, BIN);
        Serial.println(noteByte, BIN);
        Serial.println(velocityByte, BIN);
    }
  }
  while (Serial1.available() > 2);//when at least three bytes available
}

void loop(){
  //do whatever here
}
