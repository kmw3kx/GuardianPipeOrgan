#include <frequencyToNote.h>
#include <MIDIUSB.h>
#include <MIDIUSB_Defs.h>
#include <pitchToFrequency.h>
#include <pitchToNote.h>

/*
Bob Kammauff & Justyn Reyes
Midi Output - Guardian Pipe Organ
3/25
*/

#include <Servo.h>

#define NUM_NOTES 32
#define FIRST_PIN 22
Servo servos[NUM_NOTES]

MIDI_CREATE_DEFAULT_INSTANCE(); //use default MIDI settings

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < NUM_NOTES; i++)
  {
    servos[i].attach(i + FIRST_PIN);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
