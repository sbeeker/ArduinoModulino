#include <Modulino.h>

ModulinoBuzzer buzzer;

// Musical notes (frequencies in Hz)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define REST     0

// Simple melody: "Twinkle Twinkle Little Star"
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, REST,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4, REST
};

// Note durations: 4 = quarter note, 8 = eighth note, etc.
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2, 4,
  4, 4, 4, 4, 4, 4, 2, 4
};

void setup() {
  Serial.begin(9600);
  Modulino.begin();
  buzzer.begin();
  
  Serial.println("Playing melody...");
  playMelody();
}

void playMelody() {
  for (int thisNote = 0; thisNote < 16; thisNote++) {
    // Calculate the note duration
    int noteDuration = 1000 / noteDurations[thisNote];
    
    buzzer.tone(melody[thisNote], noteDuration);
    
    // Pause between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    // Stop the tone
    buzzer.tone(0, 10);
  }
}

void loop() {
  // Play melody every 5 seconds
  delay(5000);
  playMelody();
}