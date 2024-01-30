/*
 * LED BLINK - TWO LED'S, TWO RATES
 * 
 * WRITTEN BY: C. ABBEY
 * COURSE: ME 379
 * SECTION: 801
 * 
 * DATE: JAN 30, 2024
 * ********DESCRIPTION************
 *  This code uses the Arduino microcontroller to blink
 *  two LED's simultaneously at different rates.
 *  
 *  ======I/O FUNCTION============
 *  I/O:
 *    pin 6: used to control external LED
 *    LED_BUILTIN: used to control onboard led (could also use pin 13)
 *   
 */

// Define the I/O pins and create a variable array
const int ledPin = 6;               //Defines the pin the led is connected to
unsigned long previousMillis[2];    //Defines an array of two unsigned long integers, used to store the previous time each led changed state

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     //Initialize the onboard led as an output
  pinMode(ledPin, OUTPUT);          //Initialize the led connected to pin 6 as an output
}

void loop() {
  blink(LED_BUILTIN, 1000, 0);      //Call the blink function for the onboard led
  blink(ledPin, 250, 1);            //Call the blink function for the led connected to pin 6

}

//Define a new function to control the timing of the led's using the millis() function
// This function will take input frorm the user to determine the led to target, the interval to flash the target led, and the array index that the led is located at
void blink(int led, int interval, int array)  {
  // first define an if statement that compares the current time for each led to the interval argument entered
  // to determine if the led state has changed since the previous time
  // if the condition is true, the code below is executed
  if (((long)millis() - previousMillis[array]) >= interval)
  {
    previousMillis[array] = millis();       // update the current time in the array
    digitalWrite(led, !digitalRead(led));   // turn on or off the led
  }
  
}
