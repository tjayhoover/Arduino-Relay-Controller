# Arduino-Relay-Controller
This program allows an Arduino to simulate button presses using relays.

Specifically, this is meant to be used with a 12v trigger like the ones found on AV equipment. Those devices output a steady 12v current when they are powered on, to communicate to other pieces of equipment that they are running. (A common application is found on projectors. The trigger from the projector is connected to an input on a projector screen, and when the project turns on, the screen lowers from the ceiling.) Most Arduinos run on 5v, so the 12v trigger needs to be stepped down.

When this program notices a change in the input pin (The trigger being turned on or off) the program will tell the Arduino to briefly output current on one of the pins. (For 50ms or so). I have some relays wired up that will trip. So when the 12v trigger turns on, one relay will briefly trip, triggering a button press. When it turns off, the other relay will trip, triggering a different button press.

The reason I needed this is because I have a device in a home entertainment system that does not have a 12v trigger input, but I would still like to synchonize its power cycles with the projector. The device uses 868mhz RF, but I do not know how to clone RF signals yet, so I decided to create a device that can just simulate the button presses. (I took the remote and connected the relays to its main board.)
