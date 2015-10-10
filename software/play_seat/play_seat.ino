/* 
 Controlling a servo position using a potentiometer (variable resistor) 
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;

int potpin_x = 0;  // analog pin used to connect the potentiometer
int potpin_y = 0;

int val_x, val_y;    // variable to read the value from the analog pin
int horzPos = 90;                // initialize horizontal position variable to 90 degrees
int vertPos = 90;                // initialize vertical position variable to 90 degrees

int min_tilt = 60;
int max_tilt = 120;

void setup()
{
  pinMode(horzIN, INPUT);               // let Arduino know that this is an input
  pinMode(vertIN, INPUT);               // let Arduino know that this is an input
  
  myservo1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10);
}

void loop() 
{ 
  val_x = analogRead(potpin_x);
  val_y = analogRead(potpin_y);         // reads the value of the potentiometer (value between 0 and 1023) 
  val_x = map(val_x, 0, 1023, min_tilt, max_tilt);     // scale it to use it with the servo (value between 0 and 180) 
  val_y = map(val_y, 0, 1023, min_tilt, max_tilt);

  if(val_y >= horzPos){
    val_xy_r = val_x - (val_y - vertPOS);
    val_xy_l = val_x;
  }
  
  if(val_y < horzPos){
    val_xy_r = val_x;
    val_xy_l = val_x - (vertPOS - val_y);
  }
  
  myservo1.write(val_xy_l);                  // sets the servo position according to the scaled value 
  myservo2.write(val_xy_r);
  delay(15);                           // waits for the servo to get there 
} 

