#include <PS4Controller.h>
#include <ps4_int.h>

#include "MotorBehaviour.h"
#include "rgbLights.h"

#define NITRO_SPEED 255
#define NORMAL_SPEED 160
#define STAND_BY 0

int ControlUp = STAND_BY;
int ControlDown = STAND_BY;
int ControlLeft = STAND_BY;
int ControlRight = STAND_BY;

int speedControl = NORMAL_SPEED;


void ps4ledChange(int red, int green, int blue) {
  PS4.setLed(red, green, blue);
  PS4.sendToController();
  delay(10);
}

void setup() {
  Serial.begin(115200);

  // Replace the "1a:2b:3c:01:01:01" with the MAC address
  // the controller wants to pair to
  // Note: MAC address must be unicast
  PS4.begin("00:1a:7d:da:71:0f");
  Serial.println("Ready.");
}

void loop() {
  if (PS4.isConnected()) {
    bool GoForward = (ControlUp > 150) && ((ControlLeft + ControlRight) < 10);
    bool GoBackwards = (ControlDown > 150) && ((ControlLeft + ControlRight) < 10);
    bool GoLeft = (ControlLeft > 150) && ((ControlUp + ControlDown) < 10);
    bool GoRight = (ControlRight > 150) && ((ControlUp + ControlDown) < 10);

    if (PS4.Square()) Serial.println("Square Button");
    if (PS4.Cross()) Serial.println("Cross Button");
    if (PS4.Circle()) Serial.println("Circle Button");
    if (PS4.Triangle()) Serial.println("Triangle Button");


    if (PS4.L1()) Serial.println("L1 Button");
    if (PS4.R1()) Serial.println("R1 Button");

    if (PS4.L3()) Serial.println("L3 Button");
    if (PS4.R3()) Serial.println("R3 Button");

    if (PS4.PSButton()) Serial.println("PS Button");
    if (PS4.Touchpad()) Serial.println("Touch Pad Button");

    if (PS4.L2()) {

      speedControl = STAND_BY;
    }
    if (PS4.R2()) {
      speedControl = NITRO_SPEED;
    }

    if (PS4.LStickX()) {
      ControlRight = map(PS4.LStickX(), 5, 127, 0, NORMAL_SPEED);
      if (ControlRight < 0) ControlRight = 0;
      ControlLeft = map(PS4.LStickX(), -5, -128, 0, NORMAL_SPEED);
      if (ControlLeft < 0) ControlLeft = 0;
      /*Serial.println("right speed: " + (String)ControlRight);
      Serial.println("left speed: " + (String)ControlLeft);*/
    }
    if (PS4.LStickY()) {
      ControlUp = map(PS4.LStickY(), 5, 127, 0, NORMAL_SPEED);
      if (ControlUp < 0) ControlUp = 0;
      ControlDown = map(PS4.LStickY(), -5, -128, 0, NORMAL_SPEED);
      if (ControlDown < 0) ControlDown = 0;
      /* Serial.println("Up speed: " + (String)ControlUp);
      Serial.println("Down speed: " + (String)ControlDown);*/
    }
    if (GoForward) Serial.println("going comando");
    if (GoBackwards) Serial.println("going to B");
    if (GoLeft) Serial.println("Non political manner");
    if (GoRight) Serial.println("always come back");
  }

  delay(100);
}
