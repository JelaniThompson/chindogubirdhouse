// This is the version of the code that doesn't use the Piezo sensor

// Servo library for controlling the door
#include <Servo.h>

// Working with servo and door
Servo door;
int pos = 90;

void setup() {
  // 12 for solenoid, 9 for servo
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
    
  // Solenoid out, door sideways
  digitalWrite(12, HIGH);
  digitalWrite(9, HIGH);

  // 180 degrees wasn't quite what we expected so we changed it to 150
  for (pos = 0; pos <= 150; pos += 1) {
    door.write(pos);
    delay(15);
  } 
   delay(300);
}
