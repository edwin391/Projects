#include <SoftwareSerial.h>
SoftwareSerial mySerial(10,11);
char val;
volatile byte half_revolutions;
unsigned int rpm;
unsigned long timeold;
int range = 0;
int ign_ctrl = 5;
int ign2 = 6;
int start_ctrl = 7;
int acc_ctrl = 4;
int rpm_sens = 2;

void setup() {
  Serial.begin(9600);
  mySerial.begin(115200);
  attachInterrupt(0, rpm_fun, RISING);
  half_revolutions = 0;
  rpm = 0;
  timeold = 0;

  pinMode(rpm_sens, INPUT);

  pinMode(ign_ctrl, OUTPUT);
  pinMode(ign2, OUTPUT);
  pinMode(start_ctrl, OUTPUT);
  pinMode(acc_ctrl, OUTPUT);

}

void loop() {
  if (half_revolutions >= 20) 
  { 
     rpm = 30*1000/(millis() - timeold)*half_revolutions;
     timeold = millis();
     half_revolutions = 0;
     Serial.println(rpm,DEC);
   }
  if(mySerial.available() )
  {
    val = mySerial.read();
    Serial.print(val);
  }
  switch (val) {
    case 'H':
      digitalWrite(ign_ctrl, HIGH);
      digitalWrite(ign2, HIGH);
      digitalWrite(start_ctrl, HIGH);
      digitalWrite(acc_ctrl, HIGH);
      delay(900);
      digitalWrite(ign_ctrl, HIGH);
      digitalWrite(ign2, HIGH);
      digitalWrite(start_ctrl, LOW);
      digitalWrite(acc_ctrl, HIGH);
      break;
    case 'L':
      digitalWrite(ign_ctrl, LOW);
      digitalWrite(ign2, LOW);
      digitalWrite(start_ctrl, LOW);
      digitalWrite(acc_ctrl, LOW);
      break;
  }
  delay(100);
}

void rpm_fun()
 {
   half_revolutions++;
 }
