//declaring pins 
//Infrared sensors pins
 const int irFarLeft =2;
 const int irLeft=4;
 const int irCenter=5;
 const int irRight=9;
 const int irFarRight=10;
// motor pins
 const int rightMotor1= 13;
 const int rightMotor2= 12;
 const int rightMotorS= 11;
 const int leftMotor1= 8;
 const int leftMotor2= 7;
 const int leftMotorS= 6;
//ultrasonic pins
 const int tFrontUs = A5; //front ultrasonic trigger
 const int eFrontUs = A4;// front ultrasonic echo
 const int tRightUs = A3;  //right ultrasonic trigger
 const int eRightUs = A2;  //right ultrasonic echo
 const int tLeftUs = A1;  //left ultrasonic trigger
 const int eLeftUs =A0; // left ultrasonic echo

// additional ultrasonic sensor constants
 const int tunnelThreshold = 30; // distance threshold for entering/exiting the tunnel (adjust as needed)
 const int turnThreshold = 10;    // distance threshold for deciding to turn (adjust as needed)
 const int turnAngle = 45;        // angle to turn when encountering an obstacle (adjust as needed)

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

void navigateTunnel() {
  // Move forward a small distance
  moveForward();
  delay(500); // Adjust the delay based on the distance you want the robot to move forward

  // Send ultrasonic wave and get the distance
  int distance = getUltrasonicDistance(tFrontUs , eFrontUs);

  // Check if the distance is below the tunnel threshold
  if (distance < tunnelThreshold) {
    // Inside the tunnel
    while (true) {
      // Send ultrasonic wave and get the distance
      int currentDistance = getUltrasonicDistance(tFrontUs , eFrontUs);

      // Check if the distance has increased
      if (currentDistance > distance) {
        // Keep moving forward
        moveForward();
      } else {
        // Distance decreased, turn right
        turnRight();
        delay(500); // Adjust the delay based on the turning time needed
        stopMotors();

        // Send ultrasonic wave and get the distance after turning
        distance = getUltrasonicDistance(tFrontUs,eFrontUs);

        // Check if the distance is below the turn threshold
        if (distance < turnThreshold) {
          // If still too close, turn left instead
          turnLeft();
          delay(500); // Adjust the delay based on the turning time needed
          stopMotors();
        }
      }

      // Check if the distance is below the tunnel threshold again
      if (currentDistance < tunnelThreshold) {
        // Exit the tunnel
        break;
      }
    }
  }
}
void moveForward() {
  // Implement your code to move the robot forward using the motors
  digitalWrite(rightMotor1 ,HIGH);
  digitalWrite(rightMotor2 ,LOW);
  digitalWrite(leftMotor1 ,HIGH);
  digitalWrite(leftMotor2 ,LOW);
  analogWrite(rightMotorS, 125);
  analogWrite(leftMotorS,125);
}

void turnRight() {
  digitalWrite(rightMotor1 ,LOW);
  digitalWrite(rightMotor2 ,LOW);
  digitalWrite(leftMotor1 ,HIGH);
  digitalWrite(leftMotor2 ,LOW);
  analogWrite(leftMotorS,125);
}

void turnLeft() {
  digitalWrite(rightMotor1 ,HIGH);
  digitalWrite(rightMotor2 ,LOW);
  digitalWrite(leftMotor1 ,LOW);
  digitalWrite(leftMotor2 ,LOW);
  analogWrite(rightMotorS,125);
}

void stopMotors() {
  digitalWrite(rightMotor1 ,LOW);
  digitalWrite(rightMotor2 ,LOW);
  digitalWrite(leftMotor1 ,LOW);
  digitalWrite(leftMotor2 ,LOW);
}

int getUltrasonicDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.0343 / 2;
  return distance;
}


void loop() {
  // put your main code here, to run repeatedly:
  navigateTunnel();
}

