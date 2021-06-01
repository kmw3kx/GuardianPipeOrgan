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

Ok so I've already run into a couple problems about how to write the code. The code I'm taking it from sets all of the pins using a for loop. But, I can't find a way to do that with digital pins because they require a 2nd initialization to tell the pin whether to be input or output. Brute forcing it might just be the correct solution, but the idea of having the pins in an array just makes the code so much simpler.

Now that I've described the problem, the solution seems clear: do a mix

This didn't work

```python
pins = [board.D13,
        board.D12,
        board.D11,
        board.D10,
        board.D9,
        board.D8,
        board.D7,
        board.D6,
        board.D5,
        board.D4,
        board.D3,
        board.D2]


# add LED's
# ledG = digitalio.DigitalInOut(board.D1)
# ledG.direction = digitalio.Direction.OUTPUT
# n
# or do it like this

noteLEDs = []
x = 0
for pin in pins:
    noteLEDs = [digitalio.DigitalInOut(pin)]
    print(str(pin))

del pins, x  # done with that
noteLEDs.direction = digitalio.Direction.OUTPUT
```

Lets try this now: set the pins each to a variable, then set each variable to a list.

```python
pinD13 = digitalio.DigitalInOut(board.D13)
pinD12 = digitalio.DigitalInOut(board.D12)
pinD11 = digitalio.DigitalInOut(board.D11)
pinD10 = digitalio.DigitalInOut(board.D10)
pinD9 = digitalio.DigitalInOut(board.D9)
pinD8 = digitalio.DigitalInOut(board.D8)
pinD7 = digitalio.DigitalInOut(board.D7)
pinD6 = digitalio.DigitalInOut(board.D6)
pinD5 = digitalio.DigitalInOut(board.D5)
pinD4 = digitalio.DigitalInOut(board.D4)
pinD3 = digitalio.DigitalInOut(board.D3)
pinD2 = digitalio.DigitalInOut(board.D2)

pinD13.direction = digitalio.Direction.OUTPUT
pinD12.direction = digitalio.Direction.OUTPUT
pinD11.direction = digitalio.Direction.OUTPUT
pinD10.direction = digitalio.Direction.OUTPUT
pinD9.direction = digitalio.Direction.OUTPUT
pinD8.direction = digitalio.Direction.OUTPUT
pinD7.direction = digitalio.Direction.OUTPUT
pinD6.direction = digitalio.Direction.OUTPUT
pinD5.direction = digitalio.Direction.OUTPUT
pinD4.direction = digitalio.Direction.OUTPUT
pinD3.direction = digitalio.Direction.OUTPUT
pinD2.direction = digitalio.Direction.OUTPUT


noteLEDs = [pinD13,
            pinD12,
            pinD11,
            pinD10,
            pinD9,
            pinD8,
            pinD7,
            pinD6,
            pinD5,
            pinD4,
            pinD3,
            pinD2]

# Brute forced
```
### Schedule

| 1st week |  Get midi working with the circuit pythons  |  Feb. 22nd-26th |
|:--------:|:-------------------------------------------:|:---------------:|
| 2nd week | Order all of the parts we’ll need           | Mar. 1st-5th    |
| 3rd week | Design the organ pipes and the valve system | Mar. 8th-12th   |
| 4th week | Design the Shell to put the organ into      | Mar. 15th-19th  |
| 5th week | Fabrication                                 | Mar.22nd-26th   |
| 6th week | Troubleshooting (buffer week)               | Mar. 29th-Apr.2 |


#### 3rd Week

Bob Goal: Finish the design for the organ pipes. Design the Valve system.

Justyn Goal: Fix up the github, Add pictures, cad, toc. Lay out the valves once Bob Has made the valves

Evaluation: Bob really had trouble delegating work, so we only achieved designing the valve system. We finally our 3D printed Whistle prototype and that has caused us to reevaluate the design of our organ. Instead of using open flue organ pipes, we are going to use closed organ flue pipes, because they allow for a lower tone in a smaller size, and require less air pressure. And we are going to do pipes C5-G7 so they are smaller yet (longest one is 1/2 a foot!) Since they are now smaller, the silicone tubing of 1/4" might be too big now, which means we'll have to redesign the valve to fit the new size of tubing.

#### 4th Week
Justyn: Design the Organ pipes to make them stopped and tune-able by adjusting the screw on stopper. Add nozzle on the bottom to directly friction fit connect the tubes to. add brackets to the design of the organ pipes to hold them upright

Bob: Work on code; Get Servos working with midi and arduino mega.

3/17/2021

Justyn is having computer problems so I'm the only one who can do Onshape. I had to really think about how big everything was going to be, so I had to scale it down to the bottom note of F4 instead of C5. Really, I just couldn't realistically fabrcate pipes smaller than that C7 stopped pipe. I added threads on to both the cap and the top of the pipe so that the pipes can be tuned relatively easily. Hopefully. Next course of action is to define the silicone tubing size again and then remake the valve so it is smaller. Lot's of redesigning, but it will all work out.

#### 5th Week

Ok so thankfully, at the time I am writing this, my life has just gotten way less busy. All of my music stuff is done, so it's time to focus on school again. But we're also super behind on schedule. Today, I just realized that there was an extremely simple solution to this project: buy a cheap melodica and put it in the guardian. Unfortunately, we're already so deep into the organ pipes that it's pointless to just start from scratch, and besides; I prefer the flute tone of the pipes instead of the reedy tone of te melodica. That, and that the melodica wouldn't fit nicely in the robot. but that's an easy idea to save for the future!

This week, Bob is on code, and Justyn is on CAD. Thankfully, I think most of the code for the arduino mega is already on the internet so I can just borrow it. But first, we need to establish a tubing size, and then 


### CAD

[Link to Onshape](https://cvilleschools.onshape.com/documents/e358e4e3ba9e07c5ae938246/w/c6c09eac29318e33af1bc1ef/e/29cbd6e08dd43a0f8d613074)

### What Went Wrong

Why will I be unable to finish this project by the end of the year? A few reasons:

1. Lack of In-Person Lab time with my partner
2. Long turn-around on fabrication
3. The project is just insane

#### 1. Lack of In-Person Lab time with my partner

Never being able to actually see my partner face to face makes it extremely difficult to collaborate. I would try to delegate work for him to do but not being able to see him doing it and making sure he stayed on track meant that I would ultimately be the one doing it. Me also being the only one to understand the physics of sound and midi also meant it was challenging to convey what I wanted. 

I could fix this in the future by not choosing such a complicated project to do during a national pandemic. Also I started to remedy the problem by coming in on my virtual days when we started having school in person. 

#### 2. Long turn-around on fabrication

This started with me 3D printing the first test whistle. It easily took 2 weeks from submitting the file for printing to actually get it into my hands so I could test it. That day I learned the hard lesson to never print a closed cyllender. To quote my teach: 
> "closed or nearly closed cylinders are nightmares, filled with monsters and support material that wont dissolve."

This was just the starting point of design hell. Trying to print something that makes sound is incredibly difficult, because you just can't see how it will sound in CAD; you have to print it out and test it.

Thankfully I did my research and found out how whistles make noise so there was less of that, but I still had to print out 5 separate pipes before one of them actually worked. When ur not in the lab 5 days a week, it just increases the turn-around time as it would have to dissolve in the bath for at least a day after printing

The circumstances aren't just to blame; I also had to learn how to design parts that would use no support material. I did a good job with it tho, cuz my parts are now real nice.

#### 3. The project is just insane

When I was first pitching it to my teacher, he thought I just wanted to make a robot play music, so he suggested that I just use a MP3 shield and call it a day 

**Oh how easy that would've been...**

MIDI-Controlled Pipe Organs are just so cool. Something about bringing the perfection of MIDI into the physical world just sounds so cool when you hear it. But it's also just unlike anything anyone else here has tried to do, so I have to build it from the ground up. Thankfully there are projects online that are quite similar, but I was still just trying to figure out the best way to do it only a month ago. 

Now, taking all of that into consideration, by how the past couple of weeks have been going, I think I'll be able to finish it before next school year. Right now, I have two more weeks of school, plus two weeks of engineering "camp" after that. The project is nearing completion in CAD, and now I'm in stuff I have actually done before (Making the thing for it all to fit into!!)

So, if you'll excuse me, I have work to do.

-Bob K.
6/1

