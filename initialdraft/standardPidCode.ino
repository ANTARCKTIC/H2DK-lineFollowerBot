//declaring pins 
const int irFarLeft =2;
const int irLeft=4;
const int irCenter=5;
const int irRight=9;
const int irFarRight=10;
// in2 in1 ena right
// in3 in4 enb left
const int rightMotor1= 13;
const int rightMotor2= 12;
const int rightMotorS= 11;
const int leftMotor1= 8;
const int leftMotor2= 7;
const int leftMotorS= 6;

const int tFrontUs = A5; //front ultrasound trigger
const int eFrontUs = A4;// front ultrasound echo
const int tRightUs = A3;  //right ultrasound trigger
const int eRightUs = A2;  //right ultrasoud echo
const int tLeftUs = A1;  //left ultrasound trigger


//PID constants
double kp = 1.0;     // Proportional gain
double ki = 0.1;     // Integral gain
double kd = 0.05;    // Derivative gain
//PID variables
double lastError = 0;
double integral = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(rightMotor1 , OUTPUT);
pinMode(rightMotor2 , OUTPUT);
pinMode(rightMotorS , OUTPUT);
pinMode(leftMotor1 , OUTPUT);
pinMode(leftMotor2 , OUTPUT);
pinMode(leftMotorS , OUTPUT);

pinMode(tFrontUs , OUTPUT);
pinMode(tLeftUs , OUTPUT);
pinMode(tRightUs , OUTPUT);

pinMode(irFarLeft, INPUT);
pinMode(irLeft, INPUT);
pinMode(irCenter, INPUT);
pinMode(irRight, INPUT);
pinMode(irFarRight, INPUT);

pinMode(eFrontUs, INPUT);
pinMode(eRightUs, INPUT);
pinMode(eLeftUs, INPUT);
}

void loop() {
    // read sensor values
  int irFarLeftValue = digitalRead(irFarLeft);
  int irLeftValue = digitalRead(irLeft);
  int irCenterValue = digitalRead(irCenter);
  int irRightValue = digitalRead(irRight);
  int irFarRightValue = digitalRead(irFarRight);

  // calculate error (difference between desired and actual position)
  double error = irLeftValue - irRightValue;

  // update integral and prevent windup
  integral = integral + error;
  if (integral > 100) {
    integral = 100;
  } else if (integral < -100) {
    integral = -100;
  }

  // calculate PID output
  double output = kp * error + ki * integral + kd * (error - lastError);

  // update motor speeds based on PID output
  int leftSpeed = 100 - output;
  int rightSpeed = 100 + output;

  // apply motor speeds
  analogWrite(leftMotorS, leftSpeed);
  analogWrite(rightMotorS, rightSpeed);

  // save current error for the next iteration
  lastError = error;

  // add some delay to control loop speed
  delay(10);

}
