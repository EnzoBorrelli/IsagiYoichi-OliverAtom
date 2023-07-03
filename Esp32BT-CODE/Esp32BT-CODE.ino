#include <PS4Controller.h>
#include <ps4_int.h>

#include "MotorBehaviour.h"
#include "rgbLights.h"

#define NITRO_SPEED 255
#define NORMAL_SPEED 160
#define STAND_BY 0

#define DEBUG true

int ControlUp = STAND_BY;
int ControlDown = STAND_BY;
int ControlLeft = STAND_BY;
int ControlRight = STAND_BY;

int speedControl = NORMAL_SPEED;

bool isActive = false;


void ps4ledChange(int red, int green, int blue) {
  PS4.setLed(red, green, blue);
  PS4.sendToController();
  delay(10);
}

void setup() {
  if (DEBUG) Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  // Replace the "1a:2b:3c:01:01:01" with the MAC address
  // the controller wants to pair to
  // Note: MAC address must be unicast
  PS4.begin("00:1a:7d:da:71:0f");
  if (DEBUG) Serial.println("Ready.");
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  if (PS4.isConnected()) {

    //condiciones booleanas para maquina de estados

    // direcciones principales
    bool GoForward = (ControlUp > 150) && ((ControlLeft + ControlRight) < 10);
    bool GoBackwards = (ControlDown > 150) && ((ControlLeft + ControlRight) < 10);
    bool GoLeft = (ControlLeft > 150) && ((ControlUp + ControlDown) < 10);
    bool GoRight = (ControlRight > 150) && ((ControlUp + ControlDown) < 10);

    //direcciones diagonales
    bool GoUpRight = (ControlRight < 150) && (ControlUp < 150);
    bool GoUpLeft = (ControlLeft < 150) && (ControlUp < 150);
    bool GoDownRight = (ControlRight < 150) && (ControlDown < 150);
    bool GoDownLeft = (ControlLeft < 150) && (ControlDown < 150);


    if (DEBUG) {
      if (PS4.Square()) Serial.println("Square Button");
      if (PS4.Cross()) {
        isActive = true;
        ps4ledChange(green[0], green[1], green[2]);
      }
      if (PS4.Circle()) {
        isActive = false;
        ps4ledChange(orange[0], orange[1], orange[2]);
      }
      if (PS4.Triangle()) Serial.println("Triangle Button");


      if (PS4.L1()) Serial.println("L1 Button");
      if (PS4.R1()) Serial.println("R1 Button");

      if (PS4.L3()) Serial.println("L3 Button");
      if (PS4.R3()) Serial.println("R3 Button");

      if (PS4.PSButton()) Serial.println("PS Button");
      if (PS4.Touchpad()) Serial.println("Touch Pad Button");
    }
    if (isActive) {
      if (PS4.L2()) {

        speedControl = STAND_BY;
        ps4ledChange(yellow[0], yellow[1], yellow[2]);
      }
      if (PS4.R2()) {
        speedControl = NITRO_SPEED;
        ps4ledChange(violet[0], violet[1], violet[2]);
      }

      if (PS4.LStickX()) {
        ControlRight = map(PS4.LStickX(), 5, 127, 0, NORMAL_SPEED);
        if (ControlRight < 0) ControlRight = 0;
        ControlLeft = map(PS4.LStickX(), -5, -128, 0, NORMAL_SPEED);
        if (ControlLeft < 0) ControlLeft = 0;
      }
      if (PS4.LStickY()) {
        ControlUp = map(PS4.LStickY(), 5, 127, 0, NORMAL_SPEED);
        if (ControlUp < 0) ControlUp = 0;
        ControlDown = map(PS4.LStickY(), -5, -128, 0, NORMAL_SPEED);
        if (ControlDown < 0) ControlDown = 0;
      }
      //Serial.printf("Battery Level : %d\n", PS4.Battery());

      if (GoForward) RobotUp(speedControl);
      if (GoBackwards) RobotDown(speedControl);
      if (GoLeft) RobotLeft(speedControl);
      if (GoRight) RobotRight(speedControl);
      if (GoUpRight) RobotUpRight(speedControl);
      if (GoUpLeft) RobotUpLeft(speedControl);
      if (GoDownRight) RobotDownRight(speedControl);
      if (GoDownLeft) RobotDownLeft(speedControl);
    }
    else{
      RobotStop();
    }
  }

  delay(100);
}
