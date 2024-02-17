/*
Servo Sweep - Lab 2 Task 1

Written By: C. Abbey
Course: ME 379
Section: 801

Date: JAN 30, 2024

********** Description **********
The purpose of this code is to take analog input from a potentiometer
and use it to control the position of a servo.

========== I/O Function ==========

Pin A0: Analog input from potentiometer
Pin  9: Digital output to the servo motor

********** Components **********
(1) 10k Potentiometer - pin A0
(1) Servo motor - pin 9
*/

// ***** Import Libraries *****
#include <Servo.h>  //import the functions contained in the servo library

// ***** Define pins and variables *****
const int potPin = A0;    //define the variable potPin as pin A0
int sensorValue = 0;      //store a zero value to the variable sensorValue

// ***** From the servo Library, activate the class object myservo *****
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position

// ***** Initial setup functions *****
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object

  Serial.begin(9600); //begin sending serial data at a baud rate of 9600
}

// ***** Function to read/test the potentiometer output *****
/* Function: 
 *  This sub-routine is responsible for reading the value of the potentiometer
 *  and printing the information to the serial terminal. The function saves the 
 *  reading as the variable sensorValue which can be used by other functions.
 *  ****************************************************************************
 * Return: void
 * *****************************************************************************
 * Inputs: None
 * *****************************************************************************
 * Outputs: sensorValue - potentiometer reading between 0 and 1023
 */
void readPot() {
  sensorValue = analogRead(potPin);   //read potentiometer voltage, save to the variable sensorValue

  Serial.print("Potentiometer = ");  // Beginning of message
  Serial.print(sensorValue);         // potentiometer reading in decimal
  Serial.print(" dec,   ");          // decimal indicator in message
  Serial.print(sensorValue, BIN);    // potentiometer reading in binary
  Serial.println(" bin ");           // binary indicator in message, puts a linefeed at end

  delay(20);    //wait 20 milliseconds
}

// ***** Main function *****
void loop() {
  readPot();    //get the potentiometer voltage reading from the function readPot()
  pos = map(sensorValue, 0, 1023, 0, 180);    //map the values read from potentiometer to positial values of the servo
    
  myservo.write(pos);   //dot constructor to call the write() function from the object myserver to send the position to the servo

}
