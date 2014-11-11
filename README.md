ElectronicDice4Arduino
======================

An electronic dice for an Arduino board, it also works on Intel's Galileo development board(Gen.1)!


--  Hardware that you will need  --
1 x Arduino or conpatibles, equivalent board. (First of all. :)) 
7 x LEDs (2.1v <= Vf(Red) or higher Vf is required(Blue))
7 x apropriate carbon resisitors for current limitting. (I used 1kOhms each.) recommended If will be 20-40mA.
1 x Universal board designed for Arduino series.
1 x (40*2) pin header. (If you are not intended to put other shield on this.)
or (8, 8, 6, 6)length pin socket with long legs.  (If you are about to put other shield above on this!)
1 x tact switch(#1) for rolling dice.
1 x apropriate pull-down resistor to improve switch detection stability.  (I used 330 Ohms one.)
1 x apropriate resistor for digital input from power pin. (to avoid damaging board, I used 10k one.)
1 x tact switch(#2) for reset.
apropriate length of electronic wire. (recommends AWG#22, heat-resistance type.)
solders.

-- Wiring guide --
Arduino pin#      Dice alignment(where the LED and resistor to be putted and soldered.)
2                 top-right (on the Universal board)
3                 top-center
4                 top-left
5                 middle-center
6                 bottom-right
7                 bottom-center
8                 bottom-left
--
ArduinoPin# / other         connect to where
5V                          tact switch #1
tact switch #1              pull-down resistor
pull-down reg.              GND on Arduino side
switch#1 leg(resistor side) 10kOhm resistor
10k resistor                #12 on Arduino side
tact switch #2 leg          GND on Arduino side
tact switch #2 opposite leg RESET on Arduino side


--  Licenses  --
The MIT License (MIT)

Copyright (c) 2014 Akio Fujimoto.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
