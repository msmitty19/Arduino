/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

const int speaker = 12;
const int led1 = 10;
const int led2 = 9;
const int led3 = 6;   // PWM fading LED

bool mode = false;  // false = WAIL, true = YELP

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(speaker, OUTPUT);
}

void fadeUp(int stepDelay) {
  for (int brightness = 0; brightness <= 255; brightness += 15) {
    analogWrite(led3, brightness);
    delay(stepDelay);
  }
}

void fadeDown(int stepDelay) {
  for (int brightness = 255; brightness >= 0; brightness -= 15) {
    analogWrite(led3, brightness);
    delay(stepDelay);
  }
}

void loop() {

  if (mode == false) {
    // ===== WAIL MODE (Sweep + Smooth Fade) =====

    for (int freq = 600; freq <= 1400; freq += 20) {
      tone(speaker, freq);

      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);

      analogWrite(led3, map(freq, 600, 1400, 0, 255));  // Fade with pitch

      delay(10);
    }

    for (int freq = 1400; freq >= 600; freq -= 20) {
      tone(speaker, freq);

      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);

      analogWrite(led3, map(freq, 1400, 600, 0, 255));  // Fade opposite

      delay(10);
    }

  } else {
    // ===== YELP MODE (Double Flash + Fade Pulse) =====

    tone(speaker, 900);

    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    fadeUp(5);

    digitalWrite(led1, LOW);
    fadeDown(5);

    digitalWrite(led1, HIGH);
    fadeUp(5);
  }
}
