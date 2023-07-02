#include <PS4Controller.h>
#include <ps4_int.h>

#include "MotorBehaviour.h"

#define NITRO_SPEED 255
#define NORMAL_SPEED 160
int speedControlUp = NORMAL_SPEED;
int speedControlDown = NORMAL_SPEED;
int speedControlLeft = NORMAL_SPEED;
int speedControlRight = NORMAL_SPEED;



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
    bool GoForward = (speedControlUp > 150) && ((speedControlLeft + speedControlRight) < 10);
    bool GoBackwards = (speedControlDown > 150) && ((speedControlLeft + speedControlRight) < 10);
    bool GoLeft = (speedControlLeft > 150) && ((speedControlUp + speedControlDown) < 10);
    bool GoRight = (speedControlRight > 150) && ((speedControlUp + speedControlDown) < 10);

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

      int speed = map(PS4.L2Value(), 0, 255, 0, 180);
      Serial.println("la velocidad es " + (String)speed);
    }
    if (PS4.R2()) {
      int speed = PS4.R2Value();
      Serial.println("la velocidad es " + (String)speed);
    }

    if (PS4.LStickX()) {
      speedControlRight = map(PS4.LStickX(), 5, 127, 0, NORMAL_SPEED);
      if (speedControlRight < 0) speedControlRight = 0;
      speedControlLeft = map(PS4.LStickX(), -5, -128, 0, NORMAL_SPEED);
      if (speedControlLeft < 0) speedControlLeft = 0;
      /*Serial.println("right speed: " + (String)speedControlRight);
      Serial.println("left speed: " + (String)speedControlLeft);*/
    }
    if (PS4.LStickY()) {
      speedControlUp = map(PS4.LStickY(), 5, 127, 0, NORMAL_SPEED);
      if (speedControlUp < 0) speedControlUp = 0;
      speedControlDown = map(PS4.LStickY(), -5, -128, 0, NORMAL_SPEED);
      if (speedControlDown < 0) speedControlDown = 0;
      /* Serial.println("Up speed: " + (String)speedControlUp);
      Serial.println("Down speed: " + (String)speedControlDown);*/
    }
    if (GoForward) Serial.println("going comando");
    if (GoBackwards) Serial.println("going to B");
    if (GoLeft) Serial.println("Non political manner");
    if (GoRight) Serial.println("always come back");
  }

  delay(100);
}
