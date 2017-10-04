#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN 150
#define SERVOMAX 600
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  yield();
}

void  setServoPulse(uint8_t n, double pulse)
{
  double pulselen;

  pulselen = 1000000;
  pulselen /= 60;
  Serial.print(pulselen);
  pulselen /= 4096;
  Serial.print(pulselen);
  pulse *= 1000;
  pulse /= pulselen;
  pwm.setPWM(n, 0, pulse);
}

void contract()
{
  pwm.setPWM(0, 0, 370);
  pwm.setPWM(1, 0, 150);
  pwm.setPWM(2, 0, 250);
  
  pwm.setPWM(4, 0, 350);
  pwm.setPWM(5, 0, 600);
  pwm.setPWM(6, 0, 650);
  
  pwm.setPWM(8, 0, 330);
  pwm.setPWM(9, 0, 150);
  pwm.setPWM(10, 0, 150);
  
  pwm.setPWM(12, 0, 470);
  pwm.setPWM(13, 0, 600);
  pwm.setPWM(14, 0, 600);
}

void  gait()
{
  pwm.setPWM(0, 0, 430);
  pwm.setPWM(1, 0, 350);//225
  pwm.setPWM(2, 0, 450);//200
  
  pwm.setPWM(4, 0, 280);
  pwm.setPWM(5, 0, 375);
  pwm.setPWM(6, 0, 500);
  
  pwm.setPWM(8, 0, 380);
  pwm.setPWM(9, 0, 375);
  pwm.setPWM(10, 0, 300);
  
  pwm.setPWM(12, 0, 400);
  pwm.setPWM(13, 0, 375);
  pwm.setPWM(14, 0, 400);
}

void loop() {
  // put your main code here, to run repeatedly:
  //contract();
  gait();
}
