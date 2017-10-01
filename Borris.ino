/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// you can also call it with a different address you want
//Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x41);

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  150 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  
  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  yield();
}

// you can use this function if you'd like to set the pulse length in seconds
// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
void setServoPulse(uint8_t n, double pulse) {
  double pulselength;
  
  pulselength = 1000000;   // 1,000,000 us per second
  pulselength /= 60;   // 60 Hz
  Serial.print(pulselength); Serial.println(" us per period"); 
  pulselength /= 4096;  // 12 bits of resolution
  Serial.print(pulselength); Serial.println(" us per bit"); 
  pulse *= 1000;
  pulse /= pulselength;
  Serial.println(pulse);
  pwm.setPWM(n, 0, pulse);
}

void  play_dead(int *stand, int *walk)
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
  *walk = 0;
  *stand = 0;
}
int   i = 150;
void  s_ready(int *stand)
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
  *stand = 1;
}
int   lim0 = 450;
int   lim1 = 500;
int   k;
void  limb()
{
  k = 450;
  if (k <= 450)
  while (k++ <= 500)
  {
    pwm.setPWM(2, 0, k);
  }
  else if (k >= 500)
  {
    while (k-- >= 450)
      pwm.setPWM(2, 0, k);
  }
}
// servo movement coun ters
int   knee0 = 350, hip0 = 430;
void  move_f()
{
  if (knee0 >= 250)
  {
    while (knee0-- >= 250)
    {
      delay(2);
      pwm.setPWM(1, 0, knee0);
    }
  }
  if (hip0 <= 480)
  {
   while (hip0++ <= 480)
   {
    delay(2);
     pwm.setPWM(0, 0, hip0);
   }
  }
  if (knee0 <= 350)
  {
    while (knee0++ <= 350)
    {
      delay(2);
      pwm.setPWM(1, 0, knee0);
    }
  }
  if (hip0 >= 380)
  {
    while (hip0-- >= 380)
    {
      delay(2);
      pwm.setPWM(0, 0, hip0);
    }
  }
  pwm.setPWM(1, 0, 350);//225
}
int   knee1 = 375, hip1 = 280;
void  move_f1()
{

   if (knee1 >= 375)
  {
    while (knee1-- >= 375)
    {
      delay(2);
      pwm.setPWM(5, 0, knee1);
    }
  }
  if (hip1 >= 230)
  {
    while (hip1-- >= 230)
    {
      delay(2);
      pwm.setPWM(4, 0, hip1);
    }
  }
  if (knee1 <= 475)
  {
    while (knee1++ <= 475)
    {
      delay(2);
      pwm.setPWM(5, 0, knee1);
    }
  }
  if (hip1 <= 330)
  {
    while (hip1++ <= 330)
    {
      delay(2);
      pwm.setPWM(4, 0, hip1);
    }
  }
  pwm.setPWM(5, 0, 375);
}
int   knee2 = 375, hip2 = 380;
void  move_f2()
{
  if (knee2 <= 330)
  {
    while (knee2++ <= 330)
    {
      delay(2);
      pwm.setPWM(9, 0, knee2);
    }
  }
  if (hip2 <= 430)
  {
    while (hip2++ <= 430)
    {
      delay(2);
      pwm.setPWM(8, 0, hip2);
    }
  }
  if (knee2 >= 230)
  {
    while (knee2-- >= 230)
    {
      delay(2);
      pwm.setPWM(9, 0, knee2);
    }
  }
  if (hip2 >= 330)
  {
    while (hip2-- >= 330)
    {
      delay(2);
      pwm.setPWM(8, 0, hip2);
    }
  }
  pwm.setPWM(9, 0, 375);
}
int   knee3 = 375, hip3 = 400;
void  move_f3()
{
  if (knee3 >= 375)
  {
    while (knee3-- >= 375)
    {
      delay(2);
      pwm.setPWM(13, 0, knee3);
    }
  }
  if (hip3 <= 500)
  {
    while (hip3++ <= 500)
    {
      delay(2);
      pwm.setPWM(12, 0, hip3);
    }
  }
  if (knee3 <= 475)
  {
    while (knee3++ <= 475)
    {
      delay(2);
      pwm.setPWM(13, 0, knee3);
    }
  }
  if (hip3 >= 300)
  {
    while (hip3-- >= 300)
    {
      delay(2);
      pwm.setPWM(12, 0, hip3);
    }
  }
  pwm.setPWM(13, 0, 375);
}
int   stand = -1;
int   count = 0;
int   walk = -1;
int   var = 0;
void loop() {
  if (stand == -1 || count >= 5)
  {
    play_dead(&stand, &walk);
    //limb();
  }
  if (!walk)
  {
    delay(5000);
    walk = 1;
  }
  if (!stand)
    s_ready(&stand);
  if (!var)
  {
    delay(5000);
    var = 1;
  }
  if (stand && walk == 1)
  {
    move_f();
    move_f1();
    move_f2();
    move_f3();
    count++;
  }
  if (count == 5)
  {
    walk = -1;
    var = 0;
  }
}
