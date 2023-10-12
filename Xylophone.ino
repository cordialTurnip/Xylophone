

#include "MeOrion.h"
#include <SoftwareSerial.h>
#include <Wire.h>
#include "MeUltrasonicSensor.h"
#include <AccelStepper.h>

int dirPin = mePort[PORT_1].s1;
int stpPin = mePort[PORT_1].s2;
AccelStepper stepper(AccelStepper:: DRIVER, stpPin, dirPin);
MeUltrasonicSensor ultraSensor(PORT_5);

//7/8 inch steps


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper.setMaxSpeed(50);
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Distance:  ");
  Serial.print(ultraSensor.distanceCm());
  Serial.println("  cm");
  delay(100);
}
