#include <Arduino.h>
/*
StepperTestDemo

Asif Al Zubayer Swapnil

T.R. Consi, M3479
Oct. 10, 2010

Modified By: C. Abbey
Feb. 5, 2024

Full steps a stepper motor at 1 step/step_period

Arduino PWM pin 5  Motor coil 1a
Arduino PWM pin 4  Motor coil 1b
Arduino PWM pin 3  Motor coil 2a
Arduino PWM pin 2  Motor coil 2b
 */

 //========= Variable and pin definitions ===================
#define Motor1a 5   // Assign variable Motor1a to pin 5
#define Motor1b 4   // Assign variable Motor1b to pin 4
#define Motor2a 3   // Assign variable Motor2a to pin 3
#define Motor2b 2   // Assign variable Motor2b to pin 2
#define Button 8    // Assign variable Button to pin 8

int step_period = 2; // Inter-step interval (time between  steps)

//void setup(): Code to run once to initialize the state of the system.
void setup() {

    pinMode(Motor1a, OUTPUT);   // Set variable Motor1a as an output pin
    pinMode(Motor1b, OUTPUT);   // Set variable Motor1b as an output pin
    pinMode(Motor2a, OUTPUT);   // Set variable Motor2a as an output pin
    pinMode(Motor2b, OUTPUT);   // Set variable Motor2b as an output pin
    
    pinMode(Button, INPUT);     // Set variable Button aa an input pin

    // Initialize motor off 
    digitalWrite(Motor1a, LOW);   // Define the initial state of Motor1a to be 'off' or Low (+0V)
    digitalWrite(Motor1b, LOW);   // Define the initial state of Motor2a to be 'off' or Low (+0V)
    digitalWrite(Motor2a, LOW);   // Define the initial state of Motor2a to be 'off' or Low (+0V)
    digitalWrite(Motor2b, LOW);   // Define the initial state of Motor2b to be 'off' or Low (+0V)
}

//void loop(): code to repeat
void loop() {
    int buttonState = digitalRead(Button);    //Read the state of the button (was it pressed?)
    
    if (buttonState == HIGH)    // if  button is pressed: do the following ->
    {
        counterClockWise();   // if condition is true, turn the motor counter-clockwise with func. counterclockWise()
    }
    else    
    {
        clockWise();    // if condition is false, turn the motor clockwise with func. clockWise()
    }

}

/* ===================== Function: clockWise ==========================================
 * For simplicity, create a sub-routine that turns the motor in a clockwise direction
 * 
 * inputs: None
 * 
 * What it does:
 * rotate the motor one step at a time by sending a +5V pulse to the proper pin connection
 * defined earlier in the program (lines: 32-35). The pulse time is controlled by the variable step_period.
 */
void clockWise() {
    digitalWrite(Motor1a, HIGH);  //Send +5V to coil 1a through pin defined as Motor1a
    digitalWrite(Motor1b, LOW);   //Send +0V to coil 1b through pin defined as Motor1b
    digitalWrite(Motor2a, LOW);   //Send +0V to coil 2a through pin defined as Motor2a
    digitalWrite(Motor2b, LOW);   //Send +0V to coil 2b through pin defined as Motor2b
    delay(step_period);           //Wait for n seconds defined in the variable step_period

    digitalWrite(Motor1a, LOW);  //Send +0V to coil 1a through pin defined as Motor1a
    digitalWrite(Motor1b, HIGH); //Send +5V to coil 1b through pin defined as Motor1b
    digitalWrite(Motor2a, LOW);  //Send +0V to coil 2a through pin defined as Motor2a
    digitalWrite(Motor2b, LOW);  //Send +0V to coil 2b through pin defined as Motor2b
    delay(step_period);          //Wait for n seconds defined in the variable step_period

    digitalWrite(Motor1a, LOW);  //Send +0V to coil 1a through pin defined as Motor1a
    digitalWrite(Motor1b, LOW);  //Send +0V to coil 1b through pin defined as Motor1b
    digitalWrite(Motor2a, HIGH); //Send +5V to coil 2a through pin defined as Motor2a
    digitalWrite(Motor2b, LOW);  //Send +0V to coil 2b through pin defined as Motor2b
    delay(step_period);          //Wait for n seconds defined in the variable step_period

    digitalWrite(Motor1a, LOW);  //Send +0V to coil 1a through pin defined as Motor1a
    digitalWrite(Motor1b, LOW);  //Send +0V to coil 1b through pin defined as Motor1b
    digitalWrite(Motor2a, LOW);  //Send +0V to coil 2a through pin defined as Motor2a
    digitalWrite(Motor2b, HIGH); //Send +5V to coil 2a through pin defined as Motor2b
    delay(step_period);          //Wait for n seconds defined in the variable step_period
}

/* ===================== Function: counterclockWise ==========================================
 * For simplicity, create a sub-routine that turns the motor in a counterclockwise direction
 * 
 * Returns: Void
 * 
 * inputs: None
 * 
 * What it does:
 * rotate the motor one step at a time by sending a +5V pulse to the proper pin connection
 * defined earlier in the program (lines: 32-35). The pulse time is controlled by the variable step_period.
 */
void counterClockWise() {
    digitalWrite(Motor1a, LOW);   //Send +0V to coil 1a through pin defined as Motor1a
    digitalWrite(Motor1b, LOW);   //Send +0V to coil 1b through pin defined as Motor1b
    digitalWrite(Motor2a, LOW);   //Send +0V to coil 2a through pin defined as Motor2a
    digitalWrite(Motor2b, HIGH);  //Send +5V to coil 2b through pin defined as Motor2b
    delay(step_period);           //Wait for n seconds defined in the variable step_period

    digitalWrite(Motor1a, LOW);   //Send +0V to coil 1a through pin defined as Motor1a
    digitalWrite(Motor1b, LOW);   //Send +0V to coil 1b through pin defined as Motor1b
    digitalWrite(Motor2a, HIGH);  //Send +5V to coil 2a through pin defined as Motor2a
    digitalWrite(Motor2b, LOW);   //Send +0V to coil 2b through pin defined as Motor2b
    delay(step_period);           //Wait for n seconds defined in the variable step_period

    digitalWrite(Motor1a, LOW);   //Send +0V to coil 1a through pin defined as Motor1a
    digitalWrite(Motor1b, HIGH);  //Send +5V to coil 1b through pin defined as Motor1b
    digitalWrite(Motor2a, LOW);   //Send +0V to coil 2a through pin defined as Motor2a
    digitalWrite(Motor2b, LOW);   //Send +0V to coil 2b through pin defined as Motor2b
    delay(step_period);           //Wait for n seconds defined in the variable step_period

    digitalWrite(Motor1a, HIGH);  //Send +5V to coil 1a through pin defined as Motor1a
    digitalWrite(Motor1b, LOW);   //Send +0V to coil 1b through pin defined as Motor1b
    digitalWrite(Motor2a, LOW);   //Send +0V to coil 2a through pin defined as Motor2a
    digitalWrite(Motor2b, LOW);   //Send +0V to coil 2a through pin defined as Motor2b
    delay(step_period);           //Wait for n seconds defined in the variable step_period
}
