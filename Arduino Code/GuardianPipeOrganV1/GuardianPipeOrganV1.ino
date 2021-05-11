
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

#define DIFF_ANGLE ON_ANGLE-OFF_ANGLE
//Since the note on and off values are going to be simply constrained to 0 and 1,
//It's easiest to have it write the base off angle, and add the difference if it's on, i.e. 1
int note, velocity;

String fromSerial;

char input[10];

int incomingByte = 0; // for incoming serial data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //For communicating with the computer
  Serial1.begin(115200); //For communicating with the circuit python
  for (int i = 0; i < NUM_NOTES; i++)
  {
    servos[i].attach(i + FIRST_PIN);
    /*
    Serial.print("Servo ");
    Serial.print(i);
    Serial.print(" attached to pin ");
    Serial.println(i + FIRST_PIN);
    servos[i].write(90);
    */
  }
  Serial.println("All Servos Attached");
  /*
  for (int n = 0; n < NUM_NOTES; n++)
  {
    Serial.print("Testing servo ");
    Serial.println(n);
    servos[n].write(180);
    delay(500);
    servos[n].write(90);
    delay(500);
  }
  */
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
    
    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        Serial.println(token);
        
        token = strtok(NULL, " ");
        delay(10);
    }
  }
}
