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

bool mode = false;  // false = WAIL, true = YELP

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(speaker, OUTPUT);
}

void loop() {

  if (mode == false) {
    // ===== WAIL MODE (Smooth Sweep) =====
    for (int freq = 600; freq <= 1400; freq += 20) {
      tone(speaker, freq);

      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      delay(10);
    }

    for (int freq = 1400; freq >= 600; freq -= 20) {
      tone(speaker, freq);

      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      delay(10);
    }

  } else {
    // ===== YELP MODE (Double Flash) =====
    tone(speaker, 900);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    delay(80);
    digitalWrite(led1, LOW);
    delay(60);
    digitalWrite(led1, HIGH);
    delay(80); 


