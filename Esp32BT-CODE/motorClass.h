class Motor {
private:
  int _pwmMotorA;
  int _pwmMotorB;
  int _pinMotorA;
  int _pinMotorB;
  long _freq;
  int _res;

public:
  Motor(int pwmMotorA, int pwmMotorB, int pinMotorA, int pinMotorB, long freq, int res) {
    _pwmMotorA = pwmMotorA;
    _pwmMotorB = pwmMotorB;
    _pinMotorA = pinMotorA;
    _pinMotorB = pinMotorB;
    _freq = freq;
    _res = res;

    ledcSetup(_pwmMotorA, _freq, _res);
    ledcSetup(_pwmMotorB, _freq, _res);


    ledcAttachPin(_pinMotorA, _pwmMotorA);
    ledcAttachPin(_pinMotorB, _pwmMotorB);
  }

  void MotorUp(int speed) {
    ledcWrite(_pwmMotorA, speed);
    ledcWrite(_pwmMotorB, LOW);
  }
  void MotorDown(int speed) {
    ledcWrite(_pwmMotorB, speed);
    ledcWrite(_pwmMotorA, LOW);
  }
  void MotorStop(){
    ledcWrite(_pwmMotorA, LOW);
    ledcWrite(_pwmMotorB, LOW);
  }
};