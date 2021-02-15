# GuardianPipeOrgan

[<img src = "https://images-wixmp-ed30a86b8c4ca887773594c2.wixmp.com/f/4da7ebca-186f-412e-8aa4-d7fcf4fde7b9/de98lke-fb39619d-336d-4663-add4-e0f87b19a37b.png?token=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJzdWIiOiJ1cm46YXBwOiIsImlzcyI6InVybjphcHA6Iiwib2JqIjpbW3sicGF0aCI6IlwvZlwvNGRhN2ViY2EtMTg2Zi00MTJlLThhYTQtZDdmY2Y0ZmRlN2I5XC9kZTk4bGtlLWZiMzk2MTlkLTMzNmQtNDY2My1hZGQ0LWUwZjg3YjE5YTM3Yi5wbmcifV1dLCJhdWQiOlsidXJuOnNlcnZpY2U6ZmlsZS5kb3dubG9hZCJdfQ.55sYyvbvFXvSWeLJUF-AZFiEDiaG3U3LSn7FCi4E5nI" alt = "Terrako by rongs1234 on DeviantArt" width = "" height = "">](https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.deviantart.com%2Frongs1234%2Fart%2FTerrako-862044206&psig=AOvVaw2PNPe1dH_EVHYLI62axwsY&ust=1612890263248000&source=images&cd=vfe&ved=0CAIQjRxqFwoTCMC378vi2u4CFQAAAAAdAAAAABAD)

Pardon the dust as we keep updating this README!

ins Table of Contents

### Project Pre-Planning
ins Pre-planning Document

[Link](https://docs.google.com/document/d/1uND1lurYmUpj-_9FQsYxZuwOPflugXZLaDDHEH4wFzs/edit?usp=sharing)

### Pseudocode
Link to code [here.](GuardianPipeOrganOutPseudoCode)
```python
# Bob Kammauff
# 2/4/2021
# Guardian Pipe Organ - Output
# pseudocode

# at the top here, put all of the libraries we'll be using

import time

import digitalio
import touchio
import busio
import board
import usb_midi
import neopixel


import adafruit_midi

from adafruit_midi.note_on          import NoteOn
from adafruit_midi.control_change   import ControlChange
from adafruit_midi.pitch_bend       import PitchBend

# + some others that I don't know about

# set up any serial port communication we'll need

# using some type of shift register or port thingy to get more pins
# so initialize that

# Read any incoming MIDI messages (events) over USB
# looking for note on, note off messages

# Our organ will have 32 notes starting at middle C (C4) and going up to G6
# Each time a note on value is detected, write the pin connected to that note's solonoid high
# Each time theres a note off value, write the pin low

# there will be transistors in between every solonoid to supply the correct voltage
```

## Working on the Code
So, I do not have the transistors or the shift registers or any of that fancy stuff yet; all I got is a Circuit Python and some LED's, but the coding will be the same either way. Let's set up a circuit python to read Midi Data coming from my computer to light up some led's.

The wiring is easy. a bunch of LED's and resistors. Iet's get working on the code for it.


