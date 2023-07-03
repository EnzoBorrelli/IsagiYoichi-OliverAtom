#include "MotorDefines.h"
#include "motorClass.h"


Motor *MotorA = new Motor(PWM_MOTOR_A1, PWM_MOTOR_A2, PIN_MOTOR_A1, PIN_MOTOR_A2, FREQ, RES);
Motor *MotorB = new Motor(PWM_MOTOR_B1, PWM_MOTOR_B2, PIN_MOTOR_B1, PIN_MOTOR_B2, FREQ, RES);



void RobotUp(int speedA, int speedB) {
  MotorA->MotorUp(speedA);
  MotorB->MotorUp(speedB);
}
void RobotUpLeft(int speedA, int speedB) {
  MotorA->MotorUp(speedA);
  MotorB->MotorUp(speedB);
}
void RobotLeft(int speedA, int speedB) {
  MotorA->MotorUp(speedA);
  MotorB->MotorDown(speedB);
}
void RobotUpRight(int speedA, int speedB) {
  MotorA->MotorUp(speedA);
  MotorB->MotorUp(speedB);
}
void RobotRight(int speedA, int speedB) {
  MotorA->MotorDown(speedA);
  MotorB->MotorUp(speedB);
}

void RobotDown(int speedA, int speedB) {
  MotorA->MotorDown(speedA);
  MotorB->MotorDown(speedB);
}
void RobotDownLeft(int speedA, int speedB) {
  MotorA->MotorDown(speedA);
  MotorB->MotorDown(speedB);
}
void RobotDownRight(int speedA, int speedB) {
  MotorA->MotorDown(speedA);
  MotorB->MotorDown(speedB);
}

void RobotStop() {
  MotorA->MotorStop();
  MotorB->MotorStop();
}
