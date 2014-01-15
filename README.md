#arduino-yasolibs
================

Yet another set of libs for Arduino.

These libs are released under LGPL v3 licence, feel free to use them or contribute.
Source code is compliant with both Arduino IDE and Eclipse/AVR usage.

###ArduinoCore

 This is the Arduino 1.0.3 core library, easily usable within Eclipse/AVR

###GPS 
 
 This lib allows to read NMEA sentences from a GPS device connected through a (hard/soft) serial port.

###FSK600Bauds900Hz1500HzModulation
 
 This lib allows to establish a 600 Baud, 8N1 (8 databits, 1 stop bit, no parity) serial communication over a digital pin using FSK modulation (with 900Hz/1500Hz tones).
 
###FCOEV2
 
 This lib allows to easily drive FlyCamOneEcoV2 cameras (http://flycamone.com/CamOne/en/FC2410en.html), attached to digital IO pins

###LedCube

The purpose of this (or these) library(ies) is to drive LED cubes built by stacking square-shaped layers of single or multi-colored LEDs. Only one layer can be lit at a time, so POV (persistence of vision) is used to display 3D frames. LEDs of a layer are individually addressable. The cube is driven by a chain of shift registers, one of them used to address layers, the others used to address LEDs on a layer.
For the moment, only mono-colored LEDs cubes (from 1x1x1 to 8x8x8) are supported through the LedCubeMono library
