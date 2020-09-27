# **PerformingRobots**
## **September14**
**Description**: I created an arduino-based circuit with 2 switches and 3 LEDs. Pressing the top switch makes the 3 LEDs light up in an alternating pattern for 5 times(loops.) The middle LED is on when the others are off and vice versa. Pressing the bottom switch makes the LEDs turn on and off consecutively starting from the one at the top until the one at the bottom, and then from the bottom to the top.
<br/>
**ScreenShot of Circuit**
![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/September14/2020-09-12%20(5).png)
<br/>
**Problems and Solutions:**
In the beginning, connecting the switches to the Arduino and making them control the LEDs was confusing. Eventually, however, I managed to connect everything properly. The main challenge or problem that I faced was that I had connected the switches to different pins but had then connected both pins to the same resistor and ground connection. This caused some inconsistency issues whereby one switch would sometimes perform the job of the other. To fix this, I added a new resisitor/ ground connection and connected it to one of the pins.
## **September 28**
### **OLED display/ QWIIC Button:**
</br>
 For this assignment, my aim was to create a program that uses the arduino IDE to display the number of times the QWIIC button was pressed on an OLED display
 </br>
 The program uses a modular function "printonOLED()" to print whatever string it is fed onto the OLED screen. THe rpogram is designed such that when it first runs, it displays the message "READY" to the user, displays the message "PRESSED" when the button is pressed and, finally, to present the message "button presses:" and then print the number of times the button presses were detected. 
 </br>
 When the program is first started, the "READY" message is displayed:
 
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/September%2028/20200927_154004.jpg)
 </br>
 When the button is pressed, the "PRESSED" message is displayed:
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/September%2028/20200927_154020.jpg)
 </br>
 When the button is left (after being pressed at least once), a message of the following form is displayed:
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/September%2028/20200927_154845.jpg)
 </br>
 
 ### **Problems and Challenges:**
 </br>
 The main issue I faced was in printing the variable "numtimespressed". Due to the variable being an integer, the function "printonOLED()" was not accepting it as input. Possible solutions included creating a new function that prints integers, but that seemed like the longer path to take. Instead, I decided to convert the integer variable "numtimespressed" into a string using the "String()" function so that the "printonOLED()" function accepts it. Another issue I had was that I forgot to insert the display.display() function and that resulted in a very messy OLED display with random pixels all around. finally, the last problem I had was in trying to fit the words on the OLED display. The screen was cutting the word "presses" into 2 lines and that did not look neat. I therefore decided to add a couple of spaces between the word "button" and "presses" so that they are displayed on different lines.
 
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/September%2028/20200927_155333.jpg)
