#pragma once
#include "pitches.h"

#define BUZZER_NOTE_DURATION 100

class Buzzer
{
public:
    Buzzer(int _pin)
    {
        pinCurrent = _pin;
        pinMode(pinCurrent, OUTPUT);

        isEnabled = false;
        currentNote = 0;
        noteStartedMs = 0;
        pin1 = 6;
        pin2 = 7;

        notes = 0;
        durations = 0;
        melodyLength = 0;
    }

    void turnSoundOn()
    {
        isEnabled = true;
        currentNote = 0;
        noteStartedMs = 0;
    }

    void turnSoundOff()
    {
        isEnabled = false;
        currentNote = 0;
        noteStartedMs = 0;
        noTone(pinCurrent);
    }

    void changePin()
    {
        if (pinCurrent == pin1) 
        {
          pinCurrent = pin2;
        }  
        else {
          pinCurrent = pin1; 
        }
    }

    void setMelody(int _notes[], double _durations[], int _melodyLength)
    {
        notes = _notes;
        durations = _durations;
        melodyLength = _melodyLength;
    }

    void playSound()
    {
        unsigned long duration = round(BUZZER_NOTE_DURATION*durations[currentNote]);
        if ((millis() - noteStartedMs) > duration)
        {
            int note = notes[currentNote];
            
            if (note == NOTE_SILENCE or note == REST)
            {
                noTone(pinCurrent);
                changePin();
            }    
            else 
                tone(pinCurrent, notes[currentNote]);

            noteStartedMs = millis();
            currentNote = (currentNote + 1)%melodyLength;
        }
    }

private:
    int pin1;
    int pin2;
    int pinCurrent;
    
    bool isEnabled;

    int currentNote;
    unsigned long noteStartedMs;

    int* notes;
    double* durations;
    int melodyLength;
};