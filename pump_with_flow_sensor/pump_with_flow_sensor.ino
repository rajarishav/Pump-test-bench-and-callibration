//BLDC pump swipe PPM, throtle value, with flow sensor
#include <Servo.h> 
Servo myservo;
int X;
int Y;
float TIME = 0;
float FREQUENCY = 0;
float WATER = 0;
float TOTAL = 0;
float LS = 0;
const int input = D2;
void setup()
{
myservo.attach(D3);  
Serial.begin(115200);
pinMode(input,INPUT);
myservo.writeMicroseconds(1000);
}
void loop()
{
  for(int i = 1100; i<=2000; i++){
      myservo.writeMicroseconds(i);
      X = pulseIn(input, HIGH);
      Y = pulseIn(input, LOW);
      TIME = X + Y;
      FREQUENCY = 1000000/TIME;
      WATER = FREQUENCY/89;
      LS = WATER/60;
if(FREQUENCY >= 0)
{
if(isinf(FREQUENCY))
{
Serial.print("0,0.00----");
Serial.println(i);
}
else
{
TOTAL = TOTAL + LS;
Serial.print(i);
Serial.print(",");
Serial.println(WATER);

}
}
delay(1000);
  }
}
