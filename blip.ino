// uses L298N Motor Driver
// https://create.arduino.cc/projecthub/ryanchan/how-to-use-the-l298n-motor-driver-b124c5

// left motor
const uint8_t motor1pin1 = 2;
const uint8_t motor1pin2 = 3;

// right motor
const uint8_t motor2pin1 = 4;
const uint8_t motor2pin2 = 5;

// enable pins
const uint8_t ENA = 9; // left motor
const uint8_t ENB = 10; // right motor

// value 0 (stop) -> 255 (full)
uint8_t speedLeft = 0;
uint8_t speedRight = 0;

// speed controller pot
const uint8_t READ_PIN = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(ENA, OUTPUT); 
  pinMode(ENB, OUTPUT);
}

void loop() {
  // read speed pot
  uint16_t speedPot = analogRead(READ_PIN);

  // set the left wheel speed (debug)
  speedLeft = map(speedPot,0,1023,0,255)

  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(9, speedLeft); //ENA pin
  analogWrite(10, speedRight); //ENB pin

  //Controlling spin direction of motors:
  uint8_t count = 50;

  while(count < 255) {
    speedLeft = count;
    count ++;
    leftForward();
    analogWrite(ENA,speedLeft);
    delay(100);
  }
  delay(1000);

  while(count > 50) {
    speedLeft = count;
    count --;
    leftReverse();
    analogWrite(ENA,speedLeft);
    delay(100);
  }
  delay(1000);
}

void leftForward() {
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
}

void leftReverse() {
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
}

void rightForward() {
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void rightReverse() {
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

}
