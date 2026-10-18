// PUL+ goes to Arduino D2
// DIR+ goes to Arduino D3
// PUL- and DIR- goes to GNDs


const byte STEP_PIN = 2;
const byte DIR_PIN  = 3;

const int PULSES_PER_REV = 400;

// 5 ms HIGH + 5 ms LOW = 100 pulses/second.
// At 400 pulses/revolution, one revolution takes 4 seconds.
const unsigned int HALF_PERIOD_US = 5000;

void turnOneRevolution(bool direction) {
  digitalWrite(DIR_PIN, direction);
  delay(10);  // Allow direction signal to settle.

  for (int step = 0; step < PULSES_PER_REV; step++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(HALF_PERIOD_US);

    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(HALF_PERIOD_US);
  }
}

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  digitalWrite(STEP_PIN, LOW);
  digitalWrite(DIR_PIN, LOW);

  delay(1000);
}

void loop() {
  turnOneRevolution(HIGH);
  delay(1000);

  turnOneRevolution(LOW);
  delay(1000);
}