// constants

const int TRIG_PIN = 13;
const int ECHO_PIN = 12;
const int MOTOR_PIN1 = 6;
const int MOTOR_PIN2 = 5;
const float SPEED_OF_SOUND = 0.0345;

// helper functions

int distance_ms() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  return pulseIn(ECHO_PIN, HIGH);
}

float distance_cm() {
  int microsecs = distance_ms();
  return microsecs * SPEED_OF_SOUND / 2;
}

void start_motor() {
  digitalWrite(MOTOR_PIN1, HIGH);
  digitalWrite(MOTOR_PIN2, HIGH);
}

void stop_motor() {
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, LOW);
}

// run once before loop

void setup() {
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);  // initialise ultrasonic distance probe to not detect
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600) ;
}

// loop forever

void loop() {
  float cms = distance_cm();
  Serial.println(cms);
  if (cms < 30) {
    stop_motor();
  } else {
    start_motor();
  }
  delay(10);  // in milliseconds
}
