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
  pwm.setPWM(1, 0, 400);//225
  pwm.setPWM(2, 0, 450);//200
  
  pwm.setPWM(4, 0, 280);
  pwm.setPWM(5, 0, 325);
  pwm.setPWM(6, 0, 450);
  
  pwm.setPWM(8, 0, 380);
  pwm.setPWM(9, 0, 450);
  pwm.setPWM(10, 0, 350);
  
  pwm.setPWM(12, 0, 400);
  pwm.setPWM(13, 0, 300);
  pwm.setPWM(14, 0, 350);
}

void  startPos()
{
    pwm.setPWM(0, 0, 330);
    pwm.setPWM(4, 0, 380);
}
int   b;
int   up;
int   down;
void  stepOne(int *s)
{
  b = up = 0;
  down = 70;
  
  while (up++ <= 70)
    pwm.setPWM(5, 0, 325 + up);
  while (b++ <= 100)
  {
    pwm.setPWM(4, 0, 280 - b);
    delay(2);
  }
  while (down-- >= 0)
    pwm.setPWM(5, 0, 325 + down);
  *s = 0;
}
int i;
int k;
void  shiftOne()
{
  i = 0;
  k = 0;
  
  while (i++ <= 80)
  {
    pwm.setPWM(0, 0, 330 + (i * 2));
    pwm.setPWM(8, 0, 380 - i);
    pwm.setPWM(6, 0, 450 + i);
    pwm.setPWM(12, 0, 400 - i);
    delay(2);
  }
  while (k++ <= 20)
    {
      pwm.setPWM(8, 0, 300 - k);
      delay(2);
    }
}
int   up2;
int   down2;
int   x;
void  stepTwo()
{
  up2 = 0;
  down2 = 70;
  x = 0;
  
  while (up2++ <= 70)
    pwm.setPWM(13, 0, 300 + up2);
  while (x++ <= 100)
  {
   pwm.setPWM(12, 0, 400 + x);
   delay(2);
  }
 while (down2-- >= 0)
    pwm.setPWM(13, 0, 300 + down2);
 
}
int  up3;
int  down3;
int  x3;
void  stepThree()
{
  up3 = 0;
  down3 = 70;
  x3 = 0;
  
  while (up3++ <= 70)
    pwm.setPWM(9, 0, 450 - up3);
  while (x3++ <= 100)
  {
    pwm.setPWM(8, 0, 380 + x3);
    delay(2);
  }
  while (down3-- >= 0)
  {
    //if (down3 < 0)
      //down3 *= -1;
    pwm.setPWM(9, 0, 450 + down3);
  }
}

int s;
int t;
void  shiftTwo()
{
  s = 0;
  k = 0;
  while (s++ <= 100)
  {
    pwm.setPWM(4, 0, 180 + (s * 2));
    pwm.setPWM(0, 0, 510 + (s / 4));
    pwm.setPWM(6, 0, 450 - (s / 3));
    pwm.setPWM(8, 0, 480 - s);
    pwm.setPWM(12, 0, 500 - s);
    delay(2);
  }
}

int last;
int l_up;
int l_down;
void  stepFour()
{
  last = l_up = l_down = 0;
  
  while (l_up++ <= 70)
    pwm.setPWM(1, 0, 400 - l_up);
  while (last++ <= 180)
  {
    pwm.setPWM(0, 0, 510 - last);
    delay(1);
  }
  while (l_down++ <= 70)
    pwm.setPWM(1, 0, 330 + l_down);
}
int st = 1;
void  startWalking()
{
  delay(100);
  //Step One
  stepOne(&st);
  //Shift One
  delay(100);
  shiftOne();
  //Step2
  delay(100);
  stepTwo();
  //Step3
  delay(100);
  stepThree();
  //Shift One
  delay(100);
  shiftTwo();
  delay(100);
  stepFour();
}

int w;
void  wiggle()
{
  w = 0;
  while (w++ <= 50)
  {
    pwm.setPWM(2, 0, 450 + w);
    pwm.setPWM(6, 0, 450 + w);
    pwm.setPWM(10, 0, 350 + w);
    pwm.setPWM(14, 0, 350 + w);
    delay(5);
  }
}

int   count = 0;
void loop() {
  // put your main code here, to run repeatedly:
  //contract();
  //gait();

  //Start position
  if (st == 1)
  {
    gait();
    delay(1000);
    //startPos();
    //delay(3000);
  }
  st = 0;
  //if (count < 10)
    //startWalking();
  //if (count == 11)
    //gait();
  wiggle();
  //count++;
}
