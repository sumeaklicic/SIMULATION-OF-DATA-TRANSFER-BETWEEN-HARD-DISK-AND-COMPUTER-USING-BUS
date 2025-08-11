// Pin definicije
const int redLed = 7;
const int yellowLed = 8;
const int greenLed = 9;

const int trig1 = 6;
const int echo1 = 5;
const int trig2 = 4;
const int echo2 = 3;

const int whiteLed1 = 1;
const int whiteLed2 = 2;
const int blueLed1 = 10;
const int blueLed2 = 11;
const int buzzer = 12;

// Promjenjive za logiku
bool whiteActive = false;
bool blueInterrupt = false;
bool blueRunning = false;
int whiteStage = 0;

long duration;
float distance1, distance2;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  pinMode(whiteLed1, OUTPUT);
  pinMode(whiteLed2, OUTPUT);
  pinMode(blueLed1, OUTPUT);
  pinMode(blueLed2, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(greenLed, HIGH); // start with green
}

float readDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  distance1 = readDistance(trig1, echo1);
  distance2 = readDistance(trig2, echo2);

  if (!whiteActive && !blueRunning) {
    if (distance1 <= 10) {
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, HIGH);
      if (distance1 <= 5) {
        digitalWrite(yellowLed, LOW);
        digitalWrite(redLed, HIGH);
        whiteActive = true;
        whiteStage = 0;
      }
    } else {
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(greenLed, HIGH);
    }
  }

  if (whiteActive) {
    if (distance2 <= 10 && !blueRunning) {
      blueInterrupt = true;
      blueRunning = true;
      whiteActive = false;
      turnOffWhites();
      runBlueSequence();
    } else {
      runWhiteSequence();
    }
  }
}

void runWhiteSequence() {
  switch (whiteStage) {
    case 0:
      digitalWrite(whiteLed1, HIGH);
      delay(500);
      whiteStage++;
      break;
    case 1:
      digitalWrite(whiteLed2, HIGH);
      delay(500);
      whiteStage++;
      break;
    case 2:
      for (int i = 0; i < 6; i++) {
        digitalWrite(whiteLed1, i % 2);
        digitalWrite(whiteLed2, i % 2);
        delay(300);
      }
      whiteStage++;
      break;
    case 3:
      tone(buzzer, 1000);
      delay(4000);
      noTone(buzzer);
      resetAll();
      break;
  }
}
void runBlueSequence() {
  digitalWrite(blueLed1, HIGH);
  delay(500);
  digitalWrite(blueLed2, HIGH);
  delay(500);
  for (int i = 0; i < 6; i++) {
    digitalWrite(blueLed1, i % 2);
    digitalWrite(blueLed2, i % 2);
    delay(300);
  }
  tone(buzzer, 1000);
  delay(4000);
  noTone(buzzer);
  turnOffBlues();

  // NE NASTAVLJA se na bijelu sekvencu
  resetAll();
}

void turnOffWhites() {
  digitalWrite(whiteLed1, LOW);
  digitalWrite(whiteLed2, LOW);
}

void turnOffBlues() {
  digitalWrite(blueLed1, LOW);
  digitalWrite(blueLed2, LOW);
}

void resetAll() {
  turnOffWhites();
  turnOffBlues();
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, HIGH);
  whiteActive = false;
  blueRunning = false;
  whiteStage = 0;
} 
