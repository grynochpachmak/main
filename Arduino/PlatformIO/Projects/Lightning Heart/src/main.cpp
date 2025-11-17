#include <Arduino.h>

const int led = 9; // pin pentru LED
const int buz = 8; // pin pentru buzzer

void setup() {
  pinMode(led, OUTPUT); 
  pinMode(buz, OUTPUT);
}

void pulse(float bpm) {
  int T = 60000.0 / bpm; // durata ciclului (ms)
  const float a=0.28, b=0.12, c=0.20, d=0.40; // împărțirea unui ciclu în două bătăi și pauze
  const float up=0.70, hold=0.05, down=0.25; // fazele unei bătăi
  const int base=20, peak[2]={255,210}, toneHz=880;
  const int beatMs[2]={int(T*a), int(T*c)}, gaps[2]={int(T*b), int(T*d)};

  for (int i=0; i<2; i++) { // două bătăi
    int steps=peak[i]-base;
    int upMs=beatMs[i]*up, holdMs=beatMs[i]*hold, downMs=beatMs[i]*down;

    tone(buz, toneHz, beatMs[i]); // sunet egal cu durata bătăii

    // urcare luminozitate
    for (int v=base; v<=peak[i]; v++) {
      analogWrite(led, v);
      delay(max(1, upMs/steps));
    }

    delay(holdMs); // menținere scurtă la vârf

    // coborâre luminozitate
    for (int v=peak[i]; v>=base; v--) {
      analogWrite(led, v);
      delay(max(1, downMs/steps));
    }

    delay(gaps[i]); // pauză între bătăi
  }
}

void loop() {
  pulse(100); // puls
}
