### cpx-basic-synth v1.4
### CircuitPython (on CPX) synth module using internal speaker
### Velocity sensitive monophonic synth
### with crude amplitude modulation (cc1) and choppy pitch bend

### Tested with CPX and CircuitPython and 4.0.0-beta.7

### Needs recent adafruit_midi module

### copy this file to CPX as code.py

### MIT License.

### Copyright (c) 2019 Kevin J. Walters

### Permission is hereby granted, free of charge, to any person obtaining a copy
### of this software and associated documentation files (the "Software"), to deal
### in the Software without restriction, including without limitation the rights
### to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
### copies of the Software, and to permit persons to whom the Software is
### furnished to do so, subject to the following conditions:

### The above copyright notice and this permission notice shall be included in all
### copies or substantial portions of the Software.

### THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
### IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
### FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
### AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
### LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
### OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
### SOFTWARE.

import array
import time
import math

import digitalio
import audioio
import audiocore
import board
import usb_midi
import neopixel

import adafruit_midi

from adafruit_midi.midi_message     import note_parser

from adafruit_midi.note_on          import NoteOn
from adafruit_midi.note_off         import NoteOff
from adafruit_midi.control_change   import ControlChange
from adafruit_midi.pitch_bend       import PitchBend

import busio

uart = busio.UART(board.TX, board.RX, baudrate=115200)

# 440Hz is the standard frequency for A4 (A above middle C)
# MIDI defines middle C as 60 and modulation wheel is cc 1 by convention
A4refhz = 440  # was const(440)
midi_note_C4 = note_parser("C4")
print("C4 is " + str(midi_note_C4))
midi_note_A4 = note_parser("A4")
print("A4 is " + str(midi_note_A4))
midi_cc_modwheel = 1  # was const(1)
twopi = 2 * math.pi

# set pins for each note

# 12 = C
# 11 = C#
# 10 = D

# so more like

# 60 = C = 12
# 61 = C# = 11

# add LED's
# ledG = digitalio.DigitalInOut(board.D1)
# ledG.direction = digitalio.Direction.OUTPUT
# n
# or do it like this

# brightness 1.0 saves memory by removing need for a second buffer
# 10 is number of NeoPixels on CPX


# Turn NeoPixel on to represent a note using RGB x 10
# to represent 30 notes - doesn't do anything with pitch bend
#def noteLED(pix, pnote, pvel):





    #note30 = (pnote - midi_note_C4) % (3 * numpixels)
    #pos = note30 % numpixels
    #r, g, b = pix[pos]
    #if pvel == 0:
    #    brightness = 0
    #else:
    #    # max brightness will be 32
    #    brightness = round(pvel / 127 * 30 + 2)
    # Pick R/G/B based on range within the 30 notes
    #if note30 < 10:
    #    r = brightness
    #elif note30 < 20:
    #    g = brightness
    #else:
    #    b = brightness
    #pix[pos] = (r, g, b)

# Calculate the note frequency from the midi_note with pitch bend
# of pb_st (float) semitones
# Returns float

midi_channel = 1
midi = adafruit_midi.MIDI(midi_in=usb_midi.ports[0],
                          in_channel=midi_channel-1)

uart_Rx_buffer = [0, 0]

# Read any incoming MIDI messages (events) over USB
# looking for note on, note off, pitch bend change
# or control change for control 1 (modulation wheel)
# Apply crude amplitude modulation using speaker enable
while True:
    # msg = midi.receive()
    # if isinstance(msg, NoteOn) and msg.velocity != 0:
        # print(int(msg.note))
        # uart.write(bytes(msg.note))

    # elif (isinstance(msg, NoteOff) or isinstance(msg, NoteOn) and msg.velocity == 0):
        # print(int(msg.note))
        # print(uart.write(bytes(msg.note)))

    uart.write(bytes([uart_Rx_buffer[1]]))
    time.sleep(.5)
