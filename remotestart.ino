//remote starter sends 12V to ign 1, ign 2, acc. 
//acc turns off during cranking
//12 volts to starter
//12 volts to acc after car is on.

#include <SoftwareSerial.h>
  

volatile byte half_revolutions;
unsigned int rpm;
unsigned long timeold;
int range = 0;
int ign_ctrl = 5;
int start_ctrl = 7;
int ign2 = 6;
int acc_ctrl = 4;
int rpm_sens = 2;


void setup() {
  Serial.begin(9600); //pin numero 2 lee las revoluciones
  attachInterrupt(0, rpm_fun, RISING);
  half_revolutions = 0;
  rpm = 0;  
  timeold = 0;
  
  pinMode(rpm_sens, INPUT);
  
  pinMode(ign_ctrl, OUTPUT);
  pinMode(start_ctrl,OUTPUT);
  pinMode(acc_ctrl, OUTPUT);
  pinMode(ign2, OUTPUT);
  

}

void loop() {
  
    if (half_revolutions >= 20) 
  { 
     rpm = 30*1000/(millis() - timeold)*half_revolutions;
     timeold = millis();
     half_revolutions = 0;
     Serial.println(rpm,DEC);
   }

switch (range) {
  case 0:    // your hand is on the sensor
    digitalWrite(ign_ctrl, HIGH);
    digitalWrite(start_ctrl, LOW);
    digitalWrite(acc_ctrl, HIGH);
    digitalWrite(ign2, HIGH);
    delay(2000);
    range = 1;
    break;
  case 1:  
if(rpm==0){
 
    digitalWrite(start_ctrl, HIGH);
    digitalWrite(acc_ctrl, LOW);
}

range = 2;
  
    break;
  case 2:  
  
    if(rpm >= 1000)
    {
    digitalWrite(acc_ctrl, HIGH);
    digitalWrite(start_ctrl, LOW);
    }
    break;
  }
  delay(1);   

}


void rpm_fun()
 {
   half_revolutions++;
 }
