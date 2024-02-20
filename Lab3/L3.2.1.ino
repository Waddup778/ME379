#include <util/atomic.h> // For the ATOMIC_BLOCK macro

#define ENCA 2 // YELLOW
#define ENCB 3 // WHITE
#define PWM 5
#define IN2 7
#define IN1 8

#define clk 9
#define counterclk 10

int pwmVal, pwm, pwr, dir;

volatile int posi = 0; // specify posi as volatile: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/


bool clkbutt = false;
bool cclkbutt = false;

void setup() {
  Serial.begin(9600);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
  
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);

  pinMode(clk, INPUT);
  pinMode(counterclk, INPUT);
  
  Serial.println("Task2 L298N control DC motor");
  
}

void loop() {

  // Read the position in an atomic block to avoid a potential
  // misread if the interrupt coincides with this code running
  // see: https://www.arduino.cc/reference/en/language/variables/variable-scope-qualifiers/volatile/
  int pos = 0; 
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    pos = posi;
  }

  //pwmVal = 0; // sample pwm value to move the motor

  /*
   * Probably you want add a button reading here and update 
   * pwm value
   */
   clkbutt = digitalRead(clk);
   cclkbutt = digitalRead(counterclk);
   if (clkbutt){
    pwmVal = 120;
   }

   if (cclkbutt){
    pwmVal = -120;
   }
  
  if(pwmVal>0)
  {
    dir = 1;
  }
  else if (pwmVal <0)
  {
    dir = -1;
  }
  pwr =fabs(pwmVal);
  // signal the motor
  setMotor(dir,pwr,PWM,IN1,IN2);

  Serial.print("PWM value: ");
  Serial.print(pwr);
  Serial.print(" | Directon: ");
  Serial.print(dir);
  Serial.println();
}

/*
 * Probably your function to read buttons and assign pwm values
 */

void setMotor(int dir, int pwmVal, int pwm, int in1, int in2){
  analogWrite(pwm,pwmVal);
  if(dir == 1){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
  }
  else if(dir == -1){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
  }
  else{
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
  }  
}

void readEncoder(){
  int b = digitalRead(ENCB);
  if(b > 0){
    posi++;
  }
  else{
    posi--;
  }
}
