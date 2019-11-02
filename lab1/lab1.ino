#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUZZER 6
#define PIN_BUTTON_OFF 5

Button buttonOff(PIN_BUTTON_OFF);
Buzzer buzzer(PIN_BUZZER);


int notes[] = {NOTE_G3, NOTE_SILENCE, NOTE_G3, NOTE_SILENCE, NOTE_G3, NOTE_SILENCE, NOTE_DS3, NOTE_SILENCE};
double durations[] = {8, 8, 1, 8, 1, 8, 1, 24};
int melodyLength = 8;

void setup() {
    buzzer.setMelody(notes, durations, melodyLength);
    buzzer.turnSoundOn();
}

void loop() {
  
    buzzer.playSound();
    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }
}

void print_rgb(colorData rgb)
{
  Serial.print(rgb.value[TCS230_RGB_R]);
  Serial.print(" ");
  Serial.print(rgb.value[TCS230_RGB_G]);
  Serial.print(" ");
  Serial.print(rgb.value[TCS230_RGB_B]);
  Serial.println();
}

void set_rgb_led(colorData rgb)
{
    analogWrite(R_OUT, 255 - rgb.value[TCS230_RGB_R]);
    analogWrite(G_OUT, 255 - rgb.value[TCS230_RGB_G]);
    analogWrite(B_OUT, 255 - rgb.value[TCS230_RGB_B]);
}
