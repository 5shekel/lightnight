# nightlight
piezo to DMX/RS485  
using 
* teensy 3.2  
* 12 peizo elemnts (with 10M ohm resistor)  
* RS485 module  
* 3 4x400W DMX dimmer boxes.  

===connection===  
we use an off the shef 4 channel DMX dimmer box<br>
![](http://i.imgur.com/bcd8Gnz.png)

A/data+ -> 3 -> red <br>
B/data- -> 2 -> yellow <br>
ground  -> 1 -> black <br>

connecting to arduino using the MAX485 module of ebay  
![](http://i.imgur.com/T6gYmme.png)

===library===
* https:https://code.google.com/p/tinkerit/wiki/DmxSimple
* example - TBD

===more info===
https://arduino-info.wikispaces.com/SoftwareSerialRS485Example


more at http://telavivmakers.org/index.php/Lightnight
