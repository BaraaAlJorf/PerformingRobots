#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SparkFun_Qwiic_Button.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
QwiicButton button;
//create the variable numtimespressed to store the number of times the button is pressed
int numtimespressed = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("Qwiic button examples");
  Wire.begin(); //Join I2C bus

  //check if button will acknowledge over I2C
  if (button.begin() == false) {
    Serial.println("Device did not acknowledge! Freezing.");
    while (1);
  }
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  Serial.println("Button acknowledged.");
  Serial.println("Button acknowledged.");
  //prints the message "READY" in the beginning
  printonOLED("READY");

}

void loop() {
  //if button is pressed, program prints "PRESSED" on the OLED
  if (button.isPressed()) {
    printonOLED("PRESSED");
    numtimespressed++;
  }
  //if button is not pressed, program prints the number of times the button was pressed on the OLED
  //numtimespressed should not be 0(or else it would overwrite the READY message)
  if (!(button.isPressed()) && (numtimespressed != 0)) {
    //conversion of the integer variable to a string is necessary for the print function
    String Numtimespressed = String(numtimespressed) ;
    //spaces added between the words "button" and "presses" to fit onto OLED screen more neatly
    printonOLED("button    presses:" + Numtimespressed);
  }
}
//this function prints the input string i onto the OLED
void printonOLED(String i) {
  display.clearDisplay();
  display.setTextSize(2);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setCursor(0, 0);            // Start at top-left corner
  display.println(i);
  display.display();
}
