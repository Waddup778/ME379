/*
 * Title: Buzzer Control
 * 
 * Written By: C. Abbey
 * Course: ME 379
 * Section: 801
 * 
 * Date: FEB 6, 2024
 * 
 * ********** DESCRIPTION **********
 * This arduino program is to be used with an active buzzer
 * to produce frequencies between 500 and 2000 Hz
 * 
 * ********** I/O FUNCTION **********
 * Inputs:
 * Pin A0: potentiometer
 * 
 * Outputs:
 * pin  7: Buzzer (positive lead)
 */
 
#define pot A0    //define variable 'pot' assigned to pin A0
#define buzzer 7  //define variable 'buzzer' assigned to pin 7

int sensorValue = 0;    //store zero value to variable SensorValue
int frequency = 0;      //store zero value to variable frequency

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pot, INPUT);      //define pin named 'pot' as an input
  pinMode(buzzer, OUTPUT);  //define pin named 'buzzer' as output
  
  Serial.begin(9600);       //begin seding data to serial monitor at baud rate of 9600
}

void readPot() {
  sensorValue = analogRead(pot);    //read the voltage of the potentiometer, store value in sensorValue variable

  Serial.print("Potentiometer = ");  // Beginning of message
  Serial.print(sensorValue);         // potentiometer reading in decimal
  Serial.print(" dec,   ");          // decimal indicator in message
  Serial.print(sensorValue, BIN);    // potentiometer reading in binary
  Serial.println(" bin ");           // binary indicator in message, puts a linefeed at end

  delay(20);                         //wait 20 milliseconds
}
// the loop function runs over and over again forever
void loop() {
  //readPot(); //Uncomment for diagnostics 
  sensorValue = analogRead(pot); //Read the value of the potentiometer, store value in sensorValue variable

  frequency = map(sensorValue, 0, 1023, 500, 2000);   //map the input values from the sensorValue variable to correspond to frequencies of 500 to 2000 Hz

  tone(buzzer, frequency);    //send the frequency to the buzzer pin using the tone function
}
