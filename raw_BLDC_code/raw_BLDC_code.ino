#include <ps5.h>
#include <ps5Controller.h>
#include <ps5_int.h>

int escPin = 23;  // ESC signal wire on pin 9

void setup() {
  pinMode(escPin, OUTPUT);

  // Arm the ESC (send 1000µs pulses for 3 sec)
  for (int i = 0; i < 150; i++) {   // 150 pulses ≈ 3 seconds
    digitalWrite(escPin, HIGH);
    delayMicroseconds(1000);        // 1000 µs pulse = minimum throttle
    digitalWrite(escPin, LOW);
    delayMicroseconds(19000);       // remainder of 20ms frame
  }
}

void loop() {
  // Run motor at medium speed (1500µs)
  for (int i = 0; i < 250; i++) {   // run for ~5 sec
    digitalWrite(escPin, HIGH);
    delayMicroseconds(1122);        // 1500 µs = medium throttle
    digitalWrite(escPin, LOW);
    delayMicroseconds(18878);       // 20ms frame total
  }

  // Stop motor (1000µs)
  for (int i = 0; i < 250; i++) {   // run for ~5 sec
    digitalWrite(escPin, HIGH);
    delayMicroseconds(1000);        // min throttle
    digitalWrite(escPin, LOW);
    delayMicroseconds(19000);
  }
}
