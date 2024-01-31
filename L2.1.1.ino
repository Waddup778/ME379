/*
Servo Sweep - Lab 2 Task 1

Written By: C. Abbey
Course: ME 379
Section: 801

Date: JAN 30, 2024

********** Description **********
The purpose of this code is to take analog input from a potentiometer
and use it to control the position of the servo.

========== I/O Function ==========

Pin A0: Analog input from potentiometer
Pin  9: Digital output to the servo motor

********** Components **********
(1) 10k Potentiometer
(1) Servo motor
*/

// ***** Import Libraries *****
#include <Servo.h>

// ***** Define pins and variables *****
const int potPin = A0;
int sensorValue = 0;

// ***** From the servo Library, activate the class object myserver *****
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

// ***** Initial setup functions *****
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  Serial.begin(9600);
}

// ***** Function to read/test the potentiometer output *****
void readPot() {
  sensorValue = analogRead(potPin);

  Serial.print("Potentiometer = ");  // Beginning of message
  Serial.print(sensorValue);         // potentiometer reading in decimal
  Serial.print(" dec,   ");          // decimal indicator in message
  Serial.print(sensorValue, BIN);    // potentiometer reading in binary
  Serial.println(" bin ");           // binary indicator in message, puts a linefeed at end

  delay(20);
}

// ***** Main function *****
void loop() {
  readPot();
  pos = map(sensorValue, 0, 1023, 0, 180);

  myservo.write(pos);

}
