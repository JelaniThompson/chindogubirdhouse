// This is the version of the code that makes use of the piezo

// Servo library for controlling the door
#include <Servo.h>

// Sensor port and config
const int vibrationSensor = A0;
int vibrationThreshold = 100;

// Assign input from sensor to a variable
piezoValue = analogRead(vibrationSensor);

int piezoValue = 0; // Intial vibration value

// Initialize Servo instance and have default value for position
Servo door;
int pos = 90;

void setup() {  
  pinMode(12, OUTPUT);
	pinMode(9, OUTPUT);
  
	digitalWrite(12, LOW);
  delay(500);

	door.attach(9); // Telling our servo to use pin 9
  Serial.begin(9600);
}

void loop() {
  digitalWrite(12, LOW);
  delay(100);

	  // Solenoid in, door vertical
  for (pos = 180; pos >= 90; pos -= 1) {
    door.write(pos);
  }

  // When piezo value is 0, that means a vibration was detected
  Serial.println(piezoValue);

  if (piezoValue == 0) {
		// When vibration detected, stick out
    digitalWrite(12, HIGH);
		digitalWrite(9, HIGH);
  } else if (piezoValue > 0) {
    digitalWrite(12, LOW);
  }
  
  delay(1000);
}