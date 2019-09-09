#include "SR04.h" // Need for Ultrasonic Sensor
#include <pitches.h> //Need for Song

//Initialize Ultrasonic Sensor
SR04 ultra = SR04(5, 2); // Echo 5 Trig 2 Ports
long dec; //Value that stores distance in cm

void setup() {
  //Initialize Buzzer Port 8 is Passive and 9 is Active
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(9, LOW);
  // Begin Serial (Mainly Needed for Debugging)
  Serial.begin(9600);
  //Delay to avoid instant beeping
  delay(1000);
  dec = ultra.Distance(); //Initialize the distance to the wall
}

long check;

void loop() {
  //Check the distance at every loop instance
  check = ultra.Distance();
  if (dec - check >= 3) { // If there is a difference in the wall and current Sensor reading (error +3)
    while (1) { //Repeat the Beeping till reset
      //Choose between active and passive beeping
        // activeBeeping();
        passiveBeeping();
    }
  } else if (check - dec >= 5) { //In case Sensor gets moved further back
    //Reinitialize
    dec = ultra.Distance();
  }
}

void activeBeeping() {
  // Active Buzzer (9, GND)
  //Normal Beeping Sound
    digitalWrite(9, HIGH);
    delay(500);
    digitalWrite(9, LOW);
    delay(500);
}


int duration = 500; //base interval

void passiveBeeping() {
  // Omnious Tune on Passive Buzzer (9, GND)
  //Mary had a Little Lamb
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
