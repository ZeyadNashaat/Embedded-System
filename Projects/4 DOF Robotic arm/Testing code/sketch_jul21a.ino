#include<Servo.h>
Servo base;
Servo left;
Servo right;
Servo claw;
const int pot1=A1;
const int pot2=A2;
const int pot3=A3;
const int pot4=A4;
 
void setup() {
  // put your setup code here, to run once:
  base.attach(3);
  left.attach(5);
  right.attach(6);
  claw.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  int potval1=analogRead(pot1);
  int potval2=analogRead(pot2);
  int potval3=analogRead(pot3);
  int potval4=analogRead(pot4);
  int BaseAngle=map(potval1,0,1023,0,180);
  int LeftAngle=map(potval2,0,1023,0,180);
  int RightAngle=map(potval3,0,1023,0,180);
  int ClawAngle=map(potval4,0,1023,0,180);

  base.write(BaseAngle);
  left.write(LeftAngle);
  right.write(RightAngle);
  claw.write(ClawAngle);
  delay(100);
}
