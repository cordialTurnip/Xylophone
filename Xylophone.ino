#include "MeOrion.h"
#include <SoftwareSerial.h>
#include <Wire.h>
#include "MeUltrasonicSensor.h"
#include <AccelStepper.h>
#include <elapsedMillis.h>

int dirPin = mePort[PORT_1].s1;
int stpPin = mePort[PORT_1].s2;
int goalPosition = 0;
int bpm = 100;
//quarter note and half note delay
int qN = round(60000 / bpm);
int hN = round (qN * 2);
//note distances from start
bool isAtPosition = note == int(stepper.currentPosition());

int note[] = {0,16,32,48,64,80,96};
int littleStar[] = {note[0],qN,note[0],qN,note[4],qN,note[4],qN,note[5],qN,note[5],qN,note[4],hN,note[3],qN,note[3],qN,note[2],qN,note[2],qN,note[1],qN,note[1],qN,note[0],hN,note[5],qN,note[5],qN,note[3],qN,note[3],qN,note[2],qN,note[2],qN,note[1],hN,note[5],qN,note[5],qN,note[3],qN,note[3],qN,note[2],qN,note[2],qN,note[1],hN};

MeDCMotor motor1(M1);
AccelStepper stepper(AccelStepper:: DRIVER, stpPin, dirPin);
MeUltrasonicSensor ultraSensor(PORT_5);

void tapKey(int note, int noteLength){
  stepper.moveTo(note);
  stepper.run();
  if (isAtPosition){
  motor1.run(-100);
  delay(50);
  motor1.run(0);
  delay(noteLength);
  }
}

void playSong(int song[]){
int songLength = sizeof(littleStar);
for (int i = 0; i < songLength; i+=2){
  tapKey(littleStar[i],littleStar[i+1]);
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper.setMaxSpeed(4000);
  stepper.setAcceleration(30000);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (ultraSensor.distanceInch() < 12){
  playSong(littleStar);
    }
}
