void setup()
{
  //initialization of pins for Input/ Output
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  
}

void loop()
{
 //checks whether the bottom switch is pressed
 int switch1reading = digitalRead(2);
 //if switch is pressed, LEDs light up in a consecutive pattern
 if(switch1reading == HIGH)
 {	digitalWrite(10, HIGH);
  	delay(500);
  	digitalWrite(10, LOW);
  	digitalWrite(11, HIGH);
  	delay(500);
  	digitalWrite(11, LOW);
  	digitalWrite(12, HIGH);
  	delay(500);
  	digitalWrite(12, LOW);
  	delay(500);
  	digitalWrite(12, HIGH);
  	delay(500);
  	digitalWrite(12, LOW);
  	digitalWrite(11, HIGH);
  	delay(500);
  	digitalWrite(11, LOW);
  	digitalWrite(10, HIGH);
  	delay(500);
  	digitalWrite(10, LOW);
 }
 //checks whether the top switch is pressed
 int switch2reading = digitalRead(3);
 // if switch is pressed, LEDs light up in alternating pattern 5 times
 if(switch2reading == HIGH)
 {
   	//loops 5 times
   for(int i=0;i<5;i++)
   	{
   		digitalWrite(10, HIGH);
   		digitalWrite(12,HIGH);
   		delay(500);
   		digitalWrite(10,LOW);
   		digitalWrite(12,LOW);
   		digitalWrite(11,HIGH);
   		delay(500);
   		digitalWrite(11, LOW);
    }
 }
}
