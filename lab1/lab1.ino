#include <Arduino.h>

#include "button.h"
#include "buzzer.h"
#include "pitches.h"

#define BUZZER1 6
#define BUZZER2 7
#define BUTTON 5

Button buttonOff(BUTTON);
int countBuzzer = 2;
Buzzer buzzers[2] = {
    Buzzer(BUZZER1),
    Buzzer(BUZZER2)
};

int notes1[] = {NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations1[] = {8, 1, 4, 1};
int melodyLength1 = 4;
int f = 0;
int countMelody = 2;

int notes2[] = {NOTE_E4, NOTE_E4, REST, NOTE_E4, 
  REST, NOTE_C4, NOTE_E4, REST,
  NOTE_A4, REST, REST, NOTE_G3, REST,
  NOTE_C4, REST, REST, NOTE_G3,
  REST, NOTE_E3, REST,
  REST, NOTE_A3, REST, NOTE_B3,   
  REST, NOTE_AS3, NOTE_A3, REST,
  NOTE_G3, NOTE_E4, NOTE_G4,
  NOTE_A4, REST, NOTE_F4, NOTE_G4, 
  REST, NOTE_E4, REST, NOTE_C4, 
  NOTE_G4, NOTE_B3, REST};
double durations2[] = {
  4, 4, 4, 4,
  4, 4, 4, 4,
  8, 2, 4, 2, 2,
  4, 4, 4, 4,
  2, 4, 4,
  8, 4, 4, 4,  
  4, 4, 4, 4,
  8, 2, 4,
  4, 4, 4, 4,
  4, 4, 4, 4, 
  4, 4, 2
  };
int melodyLength2 = 42;


void setup() {
  for (int i = 0; i < countBuzzer; i++)
  {
    buzzers[i].setMelody(notes1, durations1 , melodyLength1);
  }
}

void loop() {
    for (int i = 0; i < countBuzzer; i++) {
        buzzers[0].playSound();
        buzzers[1].playSound();
    }
        
    if (buttonOff.wasPressed()) {
      f = (f+1) % countMelody;
      for (int i = 0; i < countBuzzer; i++)
      {
          f == 1 ? buzzers[i].setMelody(notes2, durations2, melodyLength2) : buzzers[i].setMelody(notes1, durations1, melodyLength1);
      }
    }
}