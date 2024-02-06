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

#define Motor1a 5
#define Motor1b 4
#define Motor2a 3
#define Motor2b 2
#define Button 8

int step_period = 2; // Inter-step interval

void setup() {

    pinMode(Motor1a, OUTPUT);
    pinMode(Motor1b, OUTPUT);
    pinMode(Motor2a, OUTPUT);
    pinMode(Motor2b, OUTPUT);
    
    pinMode(Button, INPUT);

    // Initialize motor off 
    digitalWrite(Motor1a, LOW);
    digitalWrite(Motor1b, LOW);
    digitalWrite(Motor2a, LOW);
    digitalWrite(Motor2b, LOW);
}

void loop() {
    int buttonState = digitalRead(Button);
    
    if (buttonState == HIGH)
    {
        counterclockWise();
    }
    else
    {
        clockWise();
    }

}

void clockWise() {
    digitalWrite(Motor1a, HIGH);
    digitalWrite(Motor1b, LOW);
    digitalWrite(Motor2a, LOW);
    digitalWrite(Motor2b, LOW);
    delay(step_period);

    digitalWrite(Motor1a, LOW);
    digitalWrite(Motor1b, HIGH);
    digitalWrite(Motor2a, LOW);
    digitalWrite(Motor2b, LOW);
    delay(step_period);

    digitalWrite(Motor1a, LOW);
    digitalWrite(Motor1b, LOW);
    digitalWrite(Motor2a, HIGH);
    digitalWrite(Motor2b, LOW);
    delay(step_period);

    digitalWrite(Motor1a, LOW);
    digitalWrite(Motor1b, LOW);
    digitalWrite(Motor2a, LOW);
    digitalWrite(Motor2b, HIGH);
    delay(step_period);
}

void counterclockWise() {
    digitalWrite(Motor1a, LOW);
    digitalWrite(Motor1b, LOW);
    digitalWrite(Motor2a, LOW);
    digitalWrite(Motor2b, HIGH);
    delay(step_period);

    digitalWrite(Motor1a, LOW);
    digitalWrite(Motor1b, LOW);
    digitalWrite(Motor2a, HIGH);
    digitalWrite(Motor2b, LOW);
    delay(step_period);

    digitalWrite(Motor1a, LOW);
    digitalWrite(Motor1b, HIGH);
    digitalWrite(Motor2a, LOW);
    digitalWrite(Motor2b, LOW);
    delay(step_period);

    digitalWrite(Motor1a, HIGH);
    digitalWrite(Motor1b, LOW);
    digitalWrite(Motor2a, LOW);
    digitalWrite(Motor2b, LOW);
    delay(step_period);
}
