#include "SR04.h"
#include <math.h>
#include <pitches.h>

SR04 ultra = SR04(5, 2);
long dec;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  digitalWrite(9, LOW);
  // Echo 5 Trig 2
  Serial.begin(9600);
  delay(1000);
  dec = ultra.Distance();
}

long check;

void loop() {
  // put your main code here, to run repeatedly:
  check = ultra.Distance();
  if (dec - check >= 3) {
    while (1) {
        // startBeeping();
        passiveBeeping();
    }
  } else if (check - dec >= 5) {
    dec = ultra.Distance();
  }
}

void startBeeping() {
  // Active Buzzer (9, GND)
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
    delay(500);
}


int duration = 500;

void passiveBeeping() {
  // Omnious Tune on Passive Buzzer (9, GND)
  tone(8, NOTE_E5, duration);
  delay(500);
  tone(8, NOTE_D5, duration);
  delay(250);
  tone(8, NOTE_C5, duration * 1.5);
  delay(500);
  tone(8, NOTE_D5, duration);
  delay(500);
  
  tone(8, NOTE_E5, duration);
  delay(500);
  tone(8, NOTE_E5, duration);
  delay(500);
  tone(8, NOTE_E5, duration * 2);
  delay(1000);

  tone(8, NOTE_D5, duration);
  delay(500);
  tone(8, NOTE_D5, duration);
  delay(500);
  tone(8, NOTE_D5, duration * 2);
  delay(1000);

  tone(8, NOTE_E5, duration);
  delay(500);
  tone(8, NOTE_G5, duration);
  delay(500);
  tone(8, NOTE_G5, duration * 2);
  delay(1000);

  tone(8, NOTE_E5, duration);
  delay(500);
  tone(8, NOTE_D5, duration);
  delay(250);
  tone(8, NOTE_C5, duration * 1.5);
  delay(500);
  tone(8, NOTE_D5, duration);
  delay(500);
  
  tone(8, NOTE_E5, duration);
  delay(500);
  tone(8, NOTE_E5, duration);
  delay(500);
  tone(8, NOTE_E5, duration * 2);
  delay(1000);

  tone(8, NOTE_D5, duration);
  delay(500);
  tone(8, NOTE_D5, duration);
  delay(500);
  tone(8, NOTE_E5, duration);
  delay(500);
  tone(8, NOTE_D5, duration);
  delay(500);
  tone(8, NOTE_C5, duration * 2);
  delay(1000);

  delay(2000);

  
  
}
