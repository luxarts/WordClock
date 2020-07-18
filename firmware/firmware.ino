#include <FastLED.h>

#define PIN_LED 4
#define NUM_LEDS 80
#define COLOR_ORDER RGB
#define CHIPSET WS2812

CRGB leds[NUM_LEDS];

typedef struct {
  uint8_t Hours;
  uint8_t Minutes;
} Clock_t;

Clock_t clock = {0};

void setup(){
  FastLED.addLeds<CHIPSET, PIN_LED, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness(255);
}
void loop(){
  clock.Hours = 0;
  clock.Minutes = 0;
  
}

uint8_t setMinuteWord(uint8_t minutes){
  if(minutes>=0 && minutes<=) return EN_PUNTO;        // 55-0-5
  else if(minutes> && minutes<=) return Y_CINCO;      // 0-5-10
  else if(minutes> && minutes<=) return Y_DIEZ;       // 5-10-15
  else if(minutes> && minutes<=) return Y_CUARTO;     // 10-15-30
  else if(minutes> && minutes<=) return Y_MEDIA;      // 15-30-45
  else if(minutes> && minutes<=) return MENOS_CUARTO; // 30-45-50
  else if(minutes> && minutes<=) return MENOS_DIEZ;   // 45-50-55
  else if(minutes> && minutes<=) return MENOS_CINCO;  // 50-55-0
}
