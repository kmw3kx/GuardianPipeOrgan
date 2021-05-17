
/*
  Bob Kammauff & Justyn Reyes
  Midi Output - Guardian Pipe Organ
  3/25
*/

#include <Servo.h>
#include <stdio.h>
#include <string.h>
 

#define NUM_NOTES 32
#define FIRST_PIN 22
Servo servos[NUM_NOTES];

#define OFF_ANGLE 90
#define ON_ANGLE 120

#define FIRST_NOTE 53 //corresponds to F3
#define LAST_NOTE 84 //corresponds to C6

//If input falls outside this range, data gets thrown out

int note, velocity;

String fromSerial;

char input[10];

int incomingByte = 0; // for incoming serial data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //For communicating with the computer
  
  for (int i = 0; i < NUM_NOTES; i++)
  {
    servos[i].attach(i + FIRST_PIN);
    
    Serial.print("Servo ");
    Serial.print(i);
    Serial.print(" attached to pin ");
    Serial.println(i + FIRST_PIN);
    servos[i].write(90);
    
  }
  Serial.println("All Servos Attached");
  
  for (int n = 0; n < NUM_NOTES; n++)
  {
    Serial.print("Testing servo ");
    Serial.println(n);
    servos[n].write(180);
    delay(250);
    servos[n].write(90);
    delay(250);
  }
  
  Serial.println("Done");
}

void loop() {
  // put your main code here, to run repeatedly:
  // send data only when you receive data:
  while (Serial.available() > 0)
  {
    fromSerial = Serial.readStringUntil('\n');
    Serial.println(fromSerial); //Echoes back what was received
    fromSerial.toCharArray(input, fromSerial.length());
    // Returns first token
    char *token = strtok(input, " ");
    note = atoi(token);
    token = strtok(NULL, " ");
    velocity = atoi(token);
    // Keep printing tokens while one of the
    // delimiters present in str[].
    if (note >= FIRST_NOTE and note <= LAST_NOTE) //If note is in range
    {
      Serial.print("Note is: ");
      Serial.println(note, DEC);
      Serial.print("Vel is: ");
      Serial.println(velocity, DEC);
      if(velocity > 0)
      {
        servos[note - FIRST_NOTE].write(ON_ANGLE);
      } else
      {
        servos[note - FIRST_NOTE].write(OFF_ANGLE);
      }
      
    }
    
    
  }
}
