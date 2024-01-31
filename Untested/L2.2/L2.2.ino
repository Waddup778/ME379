/*
Control Stepper Motor and Determine Number of Steps

Written By: C. Abbey
Course: ME 379
Section: 801

Date: JAN 30, 2024

********** Description **********
This code can be used to control a stepper motor and to determine the number of steps 
per rotation.

========== I/O Function ==========
Pins 4 thru 7: Motor control 
pin  8: push button input

*/

const int stepsPerRevolution = 4;  // Change this according to your motor's step configuration
const int motorPins[] = {4, 5, 6, 7};  // Pins connected to IN1, IN2, IN3, IN4 of ULN2003
const int pushButtonPin = 8;  // Pin connected to the pushbutton
int stepNumber = 0;  // Current step number
int previousButtonState = LOW;  // Previous state of the pushbutton

void setup() {
  // Set motor pins as output
  for (int i = 0; i < 4; i++) {
    pinMode(motorPins[i], OUTPUT);
  }
  // Set pushbutton pin as input
  pinMode(pushButtonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(pushButtonPin);  // Read the state of the pushbutton

  // Step clockwise while holding down the pushbutton
  if (buttonState == HIGH) {
    stepClockwise();
    delay(10);  // Adjust this delay to control the speed of rotation
  }
  // Step counterclockwise when no button pressed
  else {
    stepCounterclockwise();
    delay(10);  // Adjust this delay to control the speed of rotation
  }

  // Save the current button state for comparison in the next iteration
  previousButtonState = buttonState;
}

void stepClockwise() {
  stepNumber++;
  if (stepNumber >= stepsPerRevolution) {
    stepNumber = 0;
  }
  stepMotor(stepNumber % 4);
}

void stepCounterclockwise() {
  stepNumber--;
  if (stepNumber < 0) {
    stepNumber = stepsPerRevolution - 1;
  }
  stepMotor(stepNumber % 4);
}

void stepMotor(int step) {
  // Step sequence for clockwise rotation
  switch (step) {
    case 0:  // 1010
      digitalWrite(motorPins[0], HIGH);
      digitalWrite(motorPins[1], LOW);
      digitalWrite(motorPins[2], HIGH);
      digitalWrite(motorPins[3], LOW);
      break;
    case 1:  // 0110
      digitalWrite(motorPins[0], LOW);
      digitalWrite(motorPins[1], HIGH);
      digitalWrite(motorPins[2], HIGH);
      digitalWrite(motorPins[3], LOW);
      break;
    case 2:  // 0101
      digitalWrite(motorPins[0], LOW);
      digitalWrite(motorPins[1], HIGH);
      digitalWrite(motorPins[2], LOW);
      digitalWrite(motorPins[3], HIGH);
      break;
    case 3:  // 1001
      digitalWrite(motorPins[0], HIGH);
      digitalWrite(motorPins[1], LOW);
      digitalWrite(motorPins[2], LOW);
      digitalWrite(motorPins[3], HIGH);
      break;
  }
}
