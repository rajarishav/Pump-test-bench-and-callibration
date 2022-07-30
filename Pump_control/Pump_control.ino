#include <Servo.h> 
Servo myservo;
void setup() {
   myservo.attach(D3);
  Serial.begin(115200);
  }

void loop() {
  for(int i = 1000; i<=2000; i++){
       myservo.writeMicroseconds(i);
       delay(500);
       Serial.println(i);
  }
}
