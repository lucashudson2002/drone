#include <ESP32Servo.h> 

#define ESC1 23
#define ESC2 19
#define ESC3 17
#define ESC4 16

Servo esc1;
Servo esc2;
Servo esc3;
Servo esc4;

void setup()
{
  Serial.begin(115200);

	esc1.setPeriodHertz(50);
  esc1.attach(ESC1);
  esc2.setPeriodHertz(50);
  esc2.attach(ESC2);
  esc3.setPeriodHertz(50);
  esc3.attach(ESC3);
  esc4.setPeriodHertz(50);
  esc4.attach(ESC4);

  esc1.writeMicroseconds(2000);
  esc2.writeMicroseconds(2000);
  esc3.writeMicroseconds(2000);
  esc4.writeMicroseconds(2000);
  delay(5000);
  esc1.writeMicroseconds(1000);
  esc2.writeMicroseconds(1000);
  esc3.writeMicroseconds(1000);
  esc4.writeMicroseconds(1000);
  delay(5000);
}

void loop() {
  if(Serial.available()){
    int val = Serial.readStringUntil('\n').toInt();
    Serial.println(val);
    esc1.writeMicroseconds(val);
    esc2.writeMicroseconds(val);
    esc3.writeMicroseconds(val);
    esc4.writeMicroseconds(val);
  }
  delay(10);
}

