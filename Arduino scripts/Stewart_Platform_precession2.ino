#include <Servo.h>

Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;

int servoPin1 = 5;
int servoPin2 = 6;
int servoPin3 = 9;
int servoPin4 = 11;
int servoPin5 = 10;
int servoPin6 = 3;

void setup() {
  // put your setup code here, to run once:
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  Servo3.attach(servoPin3);
  Servo4.attach(servoPin4);
  Servo5.attach(servoPin5);
  Servo6.attach(servoPin6);
}

void loop() {
  int i = 45;

  // To initially bring M1, M2 to 0 deg; M3, M4 to 45 deg; M5, M6 to 90 deg
  while(i <= 90) {
    Servo1.write(90-i);
    Servo2.write(90+i);
    Servo3.write(45);
    Servo4.write(135);
    Servo5.write(i);
    Servo6.write(180-i);

    delay(75);
    i++;
  }

  int counter = 0;

  // Operating the 3 servos with a phase difference of 45 deg between each servo
  // In this case the farther adjacent vertex and the given vertex operate in same phase
  while(counter < 5) {
    i = 0;
    while(i <= 45) {
      Servo1.write(i);
      Servo2.write(180-i);
      Servo3.write(45+i);
      Servo4.write(135-i);
      Servo5.write(90-2*i);
      Servo6.write(90+2*i);

      delay(75);
      i++;
    }

    i = 0;
    while(i <= 45) {
      Servo5.write(i);
      Servo6.write(180-i);
      Servo1.write(45+i);
      Servo2.write(135-i);
      Servo3.write(90-2*i);
      Servo4.write(90+2*i);

      delay(75);
      i++;
    }

    i = 0;
    while(i <= 45) {
      Servo3.write(i);
      Servo4.write(180-i);
      Servo5.write(45+i);
      Servo6.write(135-i);
      Servo1.write(90-2*i);
      Servo2.write(90+2*i);

      delay(75);
      i++;
    }

    counter++;
  }

  i = 0;

  // To bring back the servos to mean position
  while(i <= 45) {
    Servo1.write(i);
    Servo2.write(180-i);
    Servo3.write(45);
    Servo4.write(135);
    Servo5.write(90-i);
    Servo6.write(90+i);

    delay(75);
    i++;
  }
}
