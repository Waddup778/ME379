/*
 Analog_Count
 
 T.R. Consi, ME379
 Aug. 24, 2010

 Modifed by C. Abbey
 Jan. 30, 2024
 
 Reads potentiometer
 Divides value by 8
 Outputs value on 7 LED's
 Repeats endlessly
 
 LED's attached to pins 30(lsb) to 36(msb) 
 Potentiometer attached to analog input 0
 */

const int LEDPin0 = 6;      // Define LED 1 pin
const int LEDPin1 = 7;      // Define LED 2 pin 
const int LEDPin2 = 8;      // Define LED 3 pin 
const int LEDPin3 = 9;      // Define LED 4 pin

const int PotPin = A0;      // Define Pin to be used for potentiometer
int PotReading = 0;         // Set the initial value to zero

// Create an array for the loop to reference array values
int LEDs[] = {LEDPin0, LEDPin1, LEDPin2, LEDPin3};

// Define the variable ledState, sensorValue and newValue.
// sensorValue and newValue are set to intial values of zero.
int ledState;
int sensorValue = 0;  // variable to store the value coming from the sensor
int newValue = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(LEDPin0, OUTPUT);  
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(LEDPin3, OUTPUT);
  
  Serial.begin(9600);
}

/*
 * Define a new function that does not return a value (void) to process the incoming data from
 * the potentiometer, and prints it to the serial monito so values can be confirmed.
 */
void printpot(){
  sensorValue = analogRead(PotPin);
  newValue = sensorValue / 64;        // sensor value divided by 64 to convert 4 bit number 
                                      
  Serial.print("Potentiometer = ");  // Beginning of message
  Serial.print(sensorValue);         // potentiometer reading in decimal
  Serial.print(" dec,   ");          // decimal indicator in message
  Serial.print(sensorValue, BIN);    // potentiometer reading in binary
  Serial.println(" bin ");           // binary indicator in message, puts a linefeed at end
}
void loop() {
  //initilize the printpot function here
  printpot();
  
  /*
   * The following code block utilized a for loop that iterates from 0 to 3
   * to read the current binary value of the varible 'newValue' with respect to i
   * which reperesents the current digit place.
   * 
   * The loop then writes the code to the proper led by addressing the array created earlier
   * and indexing that array for the value represented by i.
   */
  for (int i = 0; i <= 3; i = i + 1) 
  {
    ledState = bitRead(newValue, i);
    digitalWrite(LEDs[i], ledState);
  }
  delay(20);

}
