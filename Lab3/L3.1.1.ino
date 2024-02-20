#include <util/atomic.h> // For the ATOMIC_BLOCK macro

#define ENCA 2 // YELLOW
#define ENCB 3 // WHITE

volatile long encoderPulses = 0;      // Store the number of encoder pulses
volatile bool lastDirectionCW = true; // true for clockwise, false for counterclockwise
volatile bool hasMoved = false;       // Flag to indicate movement

const float pulsesPerRevolution = 540.0; // Example: 20 pulses per revolution for the encoder
const float gearRatio = 1.0;            // Example: 1:1 ratio, adjust this based on your gear setup

void setup() {
  Serial.begin(9600);
  pinMode(ENCA, INPUT);   //Set pin ENCA as an input
  pinMode(ENCB, INPUT);   //Set pin ENCB as an input
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);    //No idea what this does, but it works
   
  Serial.println("Task1 Hall sensor encoder reading");    //print this line to confirm setup, and that the code is running
}

void loop() {
  if(hasMoved) {        //if the boolian value of hasMoved = true, do the following:
    long pulses;        //establish variable pulses
    bool directionCW;   //establish boolian directionCW (t/f)
    
    // Read the values in an atomic block
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
      pulses = encoderPulses;     //set pulses equal to encoderPulses
      directionCW = lastDirectionCW;    //set directionCW equal to lastDirectionCW
      hasMoved = false; // Reset the flag
    }

    // Calculate revolutions considering the gear ratio
    float revolutions = pulses / pulsesPerRevolution / gearRatio;   //Convert pulses to revolutions.
    
    // Print the results
    Serial.print("Total revolutions of motor's shaft: ");             // Print the entered string:
    Serial.print(revolutions, 4);                                     // Adjust the decimal places as needed
    Serial.print(" | Orientation of motor's shaft: ");                // Print the entered string:
    Serial.println(directionCW ? "Clockwise" : "Counterclockwise");   // Print "clockwise if directionCW = true, else print "counterclockwise"
  }
}

/*
 * Sub-Routine: void, readEncoder
 * 
 * purpose:
 * determine the boolian state of direction and count pulses
 * 
 * How:
 * if the encoder value is greater than zero, the logic will add the pulses together
 * if the encoder value is less than zero, the logic will subract the pulses.
 * 
 * the sub routine also indicates the direction the encoder is turning by changing
 * the boolian value of the direction variable to true or false. This allows the line in
 * void loop(): Serial.println(directionCW ? "Clockwise" : "Counterclockwise") to function
 * properly. 
 */
void readEncoder() {
  int b = digitalRead(ENCB);
  if(b > 0) {
    encoderPulses++;
    lastDirectionCW = true;
  } else {
    encoderPulses--;
    lastDirectionCW = false;
  }
  hasMoved = true; // Set the flag to indicate movement
}
