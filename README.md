# **PerformingRobots**
## **September14**
**Description**: I created an arduino-based circuit with 2 switches and 3 LEDs. Pressing the top switch makes the 3 LEDs light up in an alternating pattern for 5 times(loops.) The middle LED is on when the others are off and vice versa. Pressing the bottom switch makes the LEDs turn on and off consecutively starting from the one at the top until the one at the bottom, and then from the bottom to the top.
<br/>
**ScreenShot of Circuit**
![Image](/September14/2020-09-12 (5).png)
<br/>
**Problems and Solutions:**
In the beginning, connecting the switches to the Arduino and making them control the LEDs was confusing. Eventually, however, I managed to connect everything properly. The main challenge or problem that I faced was that I had connected the switches to different pins but had then connected both pins to the same resistor and ground connection. This caused some inconsistency issues whereby one switch would sometimes perform the job of the other. To fix this, I added a new resisitor/ ground connection and connected it to one of the pins.
