#include <FastLED.h>
#include "words.hpp"

// LEDs config
#define PIN_LED 4
#define NUM_LEDS 64
#define COLOR_ORDER GRB
#define CHIPSET WS2812
CRGB leds[NUM_LEDS];

// Clock config
typedef struct {
  uint8_t Hours;
  uint8_t Minutes;
} Clock_t;
Clock_t clock = {0};

void setup(){
  Serial.begin(115200);
  FastLED.addLeds<CHIPSET, PIN_LED, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness(10);

  clock.Hours = 1;
  clock.Minutes = 0;
}

void loop(){
  // Change clock
  clock.Minutes++;
  if(clock.Minutes == 60){
    clock.Minutes = 0;
    clock.Hours++;
    if(clock.Hours == 13){
      clock.Hours = 1;
    }
  }

  // Print time
  Serial.print(clock.Hours);
  Serial.print(":");
  Serial.println(clock.Minutes);
  
  // Show words
  CleanWords(leds, NUM_LEDS);
  SetHoursWord(leds, clock.Hours, clock.Minutes);
  SetMinutesWord(leds, clock.Minutes);
  SetConnectorWord(leds, clock.Minutes);
  
  if(clock.Hours == 2)SetSpecialWords(leds);
  
  FastLED.show();
  
  delay(250);
}
