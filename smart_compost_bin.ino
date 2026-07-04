#include <Servo.h>

//
// ---------------- Motor 1 Pins ----------------
#define M1_IN1 4
#define M1_IN2 5

// ---------------- Motor 2 Pins (30 sec run) ----------------
#define M2_IN1 8
#define M2_IN2 9

// ---------------- Ultrasonic 1 (for Motor 1) ----------------
#define TRIG1 3
#define ECHO1 2

// ---------------- Ultrasonic 2 (for Servo 1) ----------------
#define TRIG2 7
#define ECHO2 6

// ---------------- Servo Motors ----------------
Servo servo1;   // controlled by ultrasonic
Servo servo2;   // runs continuous +10° -10°
int servo1Pin = 9;     // You can change if needed
int servo2Pin = 12;

int initialAngle = 90;
int bendAmount = 10;

// ---------------- Durations ----------------
const unsigned long M1_phaseTime = 120000UL;   // 2 minutes

// Motor 1 state machine variables
unsigned long m1_startTime = 0;
int m1_state = 0; // 0 = idle, 1 = CW, 2 = CCW


// ---------------- Distance functions ----------------
long getDistance1() {
  digitalWrite(TRIG1, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG1, LOW);
  long duration = pulseIn(ECHO1, HIGH);
  return duration * 0.034 / 2;
}

long getDistance2() {
  digitalWrite(TRIG2, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG2, LOW);
  long duration = pulseIn(ECHO2, HIGH);
  return duration * 0.034 / 2;
}


// ---------------- Motor 1 control ----------------
void motor1_CW() {
  digitalWrite(M1_IN1, HIGH);
  digitalWrite(M1_IN2, LOW);
}

void motor1_CCW() {
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, HIGH);
}

void motor1_STOP() {
  digitalWrite(M1_IN1, LOW);
  digitalWrite(M1_IN2, LOW);
}



// ---------------------- SETUP -----------------------
void setup() {

  // Motor 1
  pinMode(M1_IN1, OUTPUT);
  pinMode(M1_IN2, OUTPUT);

  // Motor 2
  pinMode(M2_IN1, OUTPUT);
  pinMode(M2_IN2, OUTPUT);

  // Ultrasonic 1
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO1, INPUT);

  // Ultrasonic 2
  pinMode(TRIG2, OUTPUT);
  pinMode(ECHO2, INPUT);

  // Servo motors
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);

  servo1.write(initialAngle);
  servo2.write(initialAngle);
  delay(500);


  // -------- Motor 2: one-time 30-second run --------
  digitalWrite(M2_IN1, HIGH);
  digitalWrite(M2_IN2, LOW);
  delay(30000);
  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, LOW);
}



// ---------------------- LOOP ------------------------
void loop() {

  // -------------- ULTRASONIC 1 → MOTOR 1 CONTROL --------------
  long d1 = getDistance1();
  unsigned long now = millis();

  if (d1 < 5) {

    if (m1_state == 0) {
      motor1_CW();
      m1_startTime = now;
      m1_state = 1;
    }

    if (m1_state == 1 && now - m1_startTime >= M1_phaseTime) {
      motor1_CCW();
      m1_startTime = now;
      m1_state = 2;
    }

    if (m1_state == 2 && now - m1_startTime >= M1_phaseTime) {
      motor1_STOP();
      m1_state = 0;
    }

  } else {
    motor1_STOP();
    m1_state = 0;
  }



  // -------------- ULTRASONIC 2 → SERVO 1 CONTROL --------------
  long d2 = getDistance2();

  if (d2 < 10) {

    // Move +10°
    servo1.write(initialAngle + bendAmount);
    delay(700);

    // Wait 10 sec
    delay(10000);

    // Move -10° (100 → 80)
    servo1.write(initialAngle - bendAmount);
    delay(700);

    // Go back to 90°
    servo1.write(initialAngle);
    delay(500);
  }



  // -------------- SERVO 2 CONTINUOUS ACTION --------------
  servo2.write(initialAngle + bendAmount);
  delay(700);

  delay(5000);

  servo2.write(initialAngle - bendAmount);
  delay(700);

  servo2.write(initialAngle);
  delay(500);
}
