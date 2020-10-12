//This example drives a robot in left and right arcs, driving in an overall wiggly course.
//  It demonstrates the variable control abilities. When used with a RedBot chassis,
//  each turn is about 90 degrees per drive.
//
//  Pin 8 can be grounded to disable motor movement, for debugging.

#include <Arduino.h>
#include <stdint.h>
#include "SCMD.h"
#include "SCMD_config.h" //Contains #defines for common SCMD register names and values
#include "Wire.h"
#include <SparkFun_Qwiic_Button.h>
#include "SparkFun_Qwiic_MP3_Trigger_Arduino_Library.h" //http://librarymanager/All#SparkFun_MP3_Trigger
MP3TRIGGER mp3;
SCMD myMotorDriver; //This creates the main object of one motor driver and connected slaves.
QwiicButton button;
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup()
{


  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  Serial.println("All done!");
  pinMode(8, INPUT_PULLUP); //Use to halt motor movement (ground)


  Serial.println("Starting sketch.");

  //***** Configure the Motor Driver's Settings *****//
  //  .commInter face is I2C_MODE
  myMotorDriver.settings.commInterface = I2C_MODE;

  //  set address if I2C configuration selected with the config jumpers
  myMotorDriver.settings.I2CAddress = 0x5D; //config pattern is "1000" (default) on board for address 0x5D

  //  set chip select if SPI selected with the config jumpers
  myMotorDriver.settings.chipSelectPin = 10;

  //*****initialize the driver get wait for idle*****//
  while ( myMotorDriver.begin() != 0xA9 ) //Wait until a valid ID word is returned
  {
    Serial.println( "ID mismatch, trying again" );
    delay(500);
  }
  Serial.println( "ID matches 0xA9" );

  //  Check to make sure the driver is done looking for slaves before beginning
  Serial.print("Waiting for enumeration...");
  while ( myMotorDriver.ready() == false );
  Serial.println("Done.");
  Serial.println();

  //*****Set application settings and enable driver*****//

  //Uncomment code for motor 0 inversion
  //while( myMotorDriver.busy() );
  //myMotorDriver.inversionMode(0, 1); //invert motor 0

  //Uncomment code for motor 1 inversion
  while ( myMotorDriver.busy() ); //Waits until the SCMD is available.
  myMotorDriver.inversionMode(1, 1); //invert motor 1

  while ( myMotorDriver.busy() );
  myMotorDriver.enable(); //Enables the output driver hardware
  Serial.println("Qwiic button examples");
  Wire.begin(); //Join I2C bus

  //check if button will acknowledge over I2C
  if (button.begin() == false) {
    Serial.println("Device did not acknowledge! Freezing.");
    while (1);
  }
  Serial.println("Button acknowledged.");
  //Check to see if Qwiic MP3 is present on the bus
  if (mp3.begin() == false)
  {
    Serial.println("Qwiic MP3 failed to respond. Please check wiring and possibly the I2C address. Freezing...");
    while (1);
  }

  mp3.setVolume(30); //Volume can be 0 (off) to 31 (max)

  // Clear the buffer
  display.clearDisplay();

  display.drawLine(0, 32, display.width(), 32, SSD1306_WHITE);
  display.display();
  delay(1000);

}



#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1
void loop()
{
  //Check whether the button is pressed in order to start the robot
  if (button.isPressed() == true) {
    long previousmillis = millis();
    display.clearDisplay();

    for (int16_t i = max(display.width(), display.height()) / 2; i > 0; i -= 3) {
      // The INVERSE color is used so circles alternate white/black
      display.fillCircle(display.width() / 2, display.height() / 2, i, SSD1306_INVERSE);
      display.display(); // Update screen with each newly-drawn circle
      delay(1);
    }
    mp3.playTrack(1); //Begin playing the first track on the SD card
    //pass setDrive() a motor number, direction as 0(call 0 forward) or 1, and level from 0 to 255
    myMotorDriver.setDrive( LEFT_MOTOR, 0, 0); //Stop motor
    myMotorDriver.setDrive( RIGHT_MOTOR, 0, 0); //Stop motor
    while (digitalRead(8) == 0); //Hold if jumper is placed between pin 8 and ground

    //***** Operate the Motor Driver *****//
    //  This walks through all 34 motor positions driving them forward and back.
    //  It uses .setDrive( motorNum, direction, level ) to drive the motors.


    for (int i = 0; i < 256; i++)
    {
      myMotorDriver.setDrive( LEFT_MOTOR, 1, i);
      myMotorDriver.setDrive( RIGHT_MOTOR, 1, 20 + (i / 2));
      delay(5);
    }

    while (millis() - previousmillis <= 60000)
    {
      myMotorDriver.setDrive( LEFT_MOTOR, 1, 255);
      myMotorDriver.setDrive( RIGHT_MOTOR, 1, 255);
    }
  }
  // Clear the buffer
  display.clearDisplay();

  display.drawLine(0, 32, display.width(), 32, SSD1306_WHITE);
  display.display();
  delay(1000);
  myMotorDriver.setDrive( LEFT_MOTOR, 1, 0);
  myMotorDriver.setDrive( RIGHT_MOTOR, 1, 0);

}
