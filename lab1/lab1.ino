#include <Arduino.h>

#include "button.h"
#include "buzzer.h"
#include "pitches.h"

#define BUZZER1 6
#define BUTTON 5

Button buttonOff(BUTTON);
int countBuzzer = 2;
Buzzer buzzer = Buzzer(BUZZER1);

int notes1[] = {NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations1[] = {8, 1, 4, 1};
int melodyLength1 = 4;
int currentMelody = 0;
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
  buzzer.setMelody(notes1, durations1 , melodyLength1);
}

void loop() {
    buzzer.playSound();
    if (buttonOff.wasPressed())
    {
      currentMelody = (currentMelody+1) % countMelody;
      currentMelody == 1 ? buzzer.setMelody(notes2, durations2, melodyLength2) : buzzer.setMelody(notes1, durations1, melodyLength1);
    }
}
