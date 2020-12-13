#include <AFMotor.h>
#include <Servo.h> 

Servo servo_1;
Servo servo_2;
int pos = 0;  

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char bt='S';
void setup()
{
  Serial.begin(9600);
  servo_1.attach(9);
  servo_2.attach(10);
  pinMode(10,OUTPUT); 
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  Stop();
}


void loop() {
digitalWrite(10, LOW);   
bt=Serial.read();

if(bt=='F')
{
 forward(); 
}

if(bt=='B')
{
 backward(); 
}

if(bt=='L')
{
 left(); 
}

if(bt=='R')
{
 right(); 
}

if(bt=='S')
{
 Stop(); 
}

if(bt=='D'){
for (int i=0;i<=3;i++){
   servo_1.write (0); // Servo will move to 45 degree angle.
  delay (250);
  servo_1.write (180);  // servo will move to 90 degree angle.
  delay (250);
  if (i==3){
   servo_2.write (0); // Servo will move to 45 degree angle.
  delay (250);
  servo_2.write (90);// servo will move to 90 degree angle.
  delay (250);
  servo_2.write (0);
  delay(250);
  }
}
}

}
void forward()
{
     motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward()
{
     motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void left()
{
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
void right()
{
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
