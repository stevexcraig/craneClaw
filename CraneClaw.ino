// CraneClaw by steve

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo


int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);
  myservo2.attach(10);

  Serial.begin(9600);

}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 1200, 1827);     // scale it to use it with the servo (value for microseconds)
  myservo.writeMicroseconds(val);                  // sets the servo position according to the scaled value
  delay(15);
  myservo2.writeMicroseconds(val);                  // sets the servo position according to the scaled value
  delay(15);                            // waits for the servo to get there
  Serial.println(val);
}

