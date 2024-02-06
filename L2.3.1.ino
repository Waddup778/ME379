
#define pot A0
#define buzzer 7

int sensorValue = 0;
int frequency = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pot, INPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
}

void readPot() {
  sensorValue = analogRead(pot);

  Serial.print("Potentiometer = ");  // Beginning of message
  Serial.print(sensorValue);         // potentiometer reading in decimal
  Serial.print(" dec,   ");          // decimal indicator in message
  Serial.print(sensorValue, BIN);    // potentiometer reading in binary
  Serial.println(" bin ");           // binary indicator in message, puts a linefeed at end

  delay(20);
}
// the loop function runs over and over again forever
void loop() {
  //readPot();
  sensorValue = analogRead(pot);

  frequency = map(sensorValue, 0, 1023, 500, 2000);

  tone(buzzer, frequency);
}
