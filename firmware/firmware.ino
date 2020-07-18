#include <FastLED.h>
#include "words.hpp"

// LEDs config
#define PIN_LED 4
#define NUM_LEDS 80
#define COLOR_ORDER RGB
#define CHIPSET WS2812
CRGB leds[NUM_LEDS];

// Clock config
typedef struct {
  uint8_t Hours;
  uint8_t Minutes;
} Clock_t;
Clock_t clock = {0};

void setup(){
  FastLED.addLeds<CHIPSET, PIN_LED, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness(25);

  clock.Hours = 1;
  clock.Minutes = 0;
  CleanWords(leds);
  SetHoursWord(leds, clock.Hours, clock.Minutes);
  SetMinutesWord(leds, clock.Minutes);
  SetConnectorWord(leds, clock.Minutes);
  SetSpecialWord(leds);
}

void loop(){
  
}
