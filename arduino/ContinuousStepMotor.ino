#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

// initialize the stepper library on pins 3 through 6:
Stepper myStepper(stepsPerRevolution, 3, 4, 5, 6);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

}
