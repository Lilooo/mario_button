/*
  Melody Mario
 */
 
#include "pitches.h"

// Declare Pins
int speakerPin = 7;
int buttonPin = A5;
int leds[] = {5,6,A2,A4,A3};

// Melody Notes
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
  
  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6, 
  0, 0, NOTE_E6, 0, 
  0, NOTE_A6, 0, NOTE_B6, 
  0, NOTE_AS6, NOTE_A6, 0, 

  NOTE_G6, NOTE_E7, NOTE_G7, 
  NOTE_A7, 0, NOTE_F7, NOTE_G7, 
  0, NOTE_E7, 0,NOTE_C7, 
  NOTE_D7, NOTE_B6, 0, 0,
  
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
  };

// Each Note Duration
int noteDurations[] = {
  12, 12, 12, 12, 
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12, 

  12, 12, 12, 12,
  12, 12, 12, 12, 
  12, 12, 12, 12, 
  12, 12, 12, 12, 

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12
  };

// Play Melody
void play_tone(int note) {
  int noteDuration = 1000 / noteDurations[note];
  tone(7, melody[note], noteDuration);
  int pauseBetweenNotes = noteDuration * 1.30;
  delay(pauseBetweenNotes);
  noTone(7);
}

// Shut Down Every Leds
void reset_led() {
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[3], LOW);
  digitalWrite(leds[4], LOW);
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i <= 4; i++) {
     pinMode(leds[i], OUTPUT);
  }
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT); 
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  // If button is pressed
  if(digitalRead(buttonPin) == 0)
   {
     int y = 0;
     // For Every Notes...
     for (int i = 0; i < 94; i++)
     {
       // Different of 0
       if (melody[i] != 0)
       {
         // Light up Led
         digitalWrite(leds[y], HIGH);
         y++;
         // Reset Count After Five Pins
         if (y > 4)
           y = 0;
       }
       play_tone(i);
       reset_led();
     }
   // If Button NOT Pressed
   } else {
     digitalWrite(speakerPin, LOW);
   }
 }
