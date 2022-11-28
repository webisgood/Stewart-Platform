// To include the Servo library
#include <Servo.h>

// Creating servo objects
Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;
Servo Servo5;
Servo Servo6;

// Servo Pin numbers
int servoPin1 = 5;
int servoPin2 = 6;
int servoPin3 = 9;
int servoPin4 = 11;
int servoPin5 = 10;
int servoPin6 = 3;


void setup() {
  // Servo pins setup
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  Servo3.attach(servoPin3);
  Servo4.attach(servoPin4);
  Servo5.attach(servoPin5);
  Servo6.attach(servoPin6);
}

void loop() {
  
  int i = 45;
  int theta = 15;

  // To move odd and even motors in CW direction by angle 45 deg
  while(i <= 45+theta) {
    Servo1.write(i);
    Servo2.write(90+i);
    Servo3.write(i);
    Servo4.write(90+i);
    Servo5.write(i);
    Servo6.write(90+i);

    delay(75);

    i++;
  }

  // To move odd and even motors in CCW direction by angle 90 deg 
  while(i >= 45-theta) {
    Servo1.write(i);
    Servo2.write(90+i);
    Servo3.write(i);
    Servo4.write(90+i);
    Servo5.write(i);
    Servo6.write(90+i);

    delay(75);

    i--;
  }

  // To move odd and even motors in CW direction by angle 45 deg to return back to the mean position
  while(i <= 45) {
    Servo1.write(i);
    Servo2.write(90+i);
    Servo3.write(i);
    Servo4.write(90+i);
    Servo5.write(i);
    Servo6.write(90+i);

    delay(75);

    i++;
  }
}
