#include "MotorDefines.h"
#include "motorClass.h"


Motor *MotorA = new Motor(PWM_MOTOR_A1, PWM_MOTOR_A2, PIN_MOTOR_A1, PIN_MOTOR_A2, FREQ, RES);
Motor *MotorB = new Motor(PWM_MOTOR_B1, PWM_MOTOR_B2, PIN_MOTOR_B1, PIN_MOTOR_B2, FREQ, RES);



void RobotUp(int speed) {
  MotorA->MotorUp(speed);
  MotorB->MotorUp(speed);
}
void RobotUpLeft(int speed) {
  MotorA->MotorUp(speed);
  MotorB->MotorUp(speed);
}
void RobotLeft(int speed) {
  MotorA->MotorUp(speed);
  MotorB->MotorDown(speed);
}
void RobotUpRight(int speed) {
  MotorA->MotorUp(speed);
  MotorB->MotorUp(speed);
}
void RobotRight(int speed) {
  MotorA->MotorDown(speed);
  MotorB->MotorUp(speed);
}

void RobotDown(int speed) {
  MotorA->MotorDown(speed);
  MotorB->MotorDown(speed);
}
void RobotDownLeft(int speed) {
  MotorA->MotorDown(speed);
  MotorB->MotorDown(speed);
}
void RobotDownRight(int speed) {
  MotorA->MotorDown(speed);
  MotorB->MotorDown(speed);
}

void RobotStop() {
  MotorA->MotorStop();
  MotorB->MotorStop();
}
