char command;

void setup() {
  // Enable pins
  pinMode(6, OUTPUT);   // ENA
  pinMode(7, OUTPUT);   // ENB

  // Motor control pins
  pinMode(8, OUTPUT);   // IN1
  pinMode(9, OUTPUT);   // IN2
  pinMode(10, OUTPUT);  // IN3
  pinMode(11, OUTPUT);  // IN4

  // Enable both motors
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

  // Stop motors initially
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);

  // Start Bluetooth Serial
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {

    command = Serial.read();

    switch (command) {

      case 'F':   // Forward
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        break;

      case 'B':   // Backward
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        break;

      case 'L':   // Left
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        break;

      case 'R':   // Right
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        break;

      case 'S':   // Stop
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        break;
    }
  }
}