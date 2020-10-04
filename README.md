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

## October 4
## Project Description:
</br>
My aim in this project was to create a robot that moves and makes sound once a button is pressed. I wanted to give the robot a little bit of a personality so I painted it and had it make high-pitched robot noises. I also added bear ears and random patches in order to make it more lively.
 
![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/October4/20201004_212900.jpg)
</br>
Initially, I wanted to figure out how to attach the circuit. To do so, I first hot-glued the motors and wheels to a piece of cardboard, and then started building up my circuit from then
 
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/October4/20201004_170520.jpg)
  
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/October4/20201004_173349.jpg)
  
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/October4/20201004_190616.jpg)
  
</br>
by this point, I was done with the structure, but I wanted to add my personal touches so I grabbed my acrylic markers and poska pens and started painting it
 
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/October4/20201004_193443.jpg)
  
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/October4/20201004_195158.jpg)
  
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/October4/20201004_211838.jpg)
  
 ![Alt Text](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/October4/20201004_212302.jpg)
</br>
Here you could find a video of the robot when the button is pressed:
 
 ![Video](https://github.com/BaraaAlJorf/PerformingRobots/blob/master/October4/20201004_212318.mp4)
## Challenges:

The main challenge I faced was to keep the robot structuraly intact. Thankfully, the glue gun was able to fix most structural problems. Additionally, my choice to give the robot a parallellogram shaped body helped prevent it from flopping over
