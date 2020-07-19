#ifndef WORDS_H
#define WORDS_H
#include <FastLED.h>

// Words colors
#define HOURS_COLOR CRGB(255,0,0)
#define MINUTES_COLOR CRGB(0,255,0)
#define CONNECTORS_COLOR CRGB(0,0,255)
#define SPECIAL_COLOR CRGB(255,0,255)

// Minutes status
#define EN_PUNTO        0
#define Y_CINCO         1
#define Y_DIEZ          2
#define Y_CUARTO        3
#define Y_MEDIA         4
#define MENOS_CUARTO    5
#define MENOS_DIEZ      6
#define MENOS_CINCO     7
#define MENOS_EN_PUNTO  8

// Character position index and length for each word
//#define UNA_I     0
//#define UNA_L     3
//#define DOS_I     3
//#define DOS_L     3
//#define TRES_I    6
//#define TRES_L    4
//#define CUATRO_I  10
//#define CUATRO_L  6
//#define CINCO_I   20
//#define CINCO_L   5
//#define SEIS_I    16
//#define SEIS_L    4
//#define SIETE_I   25
//#define SIETE_L   5
//#define OCHO_I    30
//#define OCHO_L    4
//#define NUEVE_I   35
//#define NUEVE_L   5
//#define DIEZ_I    40
//#define DIEZ_L    4
//#define ONCE_I    46
//#define ONCE_L    4
//#define DOCE_I    50
//#define DOCE_L    4
//#define MENOS_I   54
//#define MENOS_L   5
//#define Y_I       59
//#define Y_L       1
//#define CINCOM_I  60
//#define CINCOM_L  5
//#define DIEZM_I   70
//#define DIEZM_L   4
//#define CUARTO_I  74
//#define CUARTO_L  6
//#define MEDIA_I   65
//#define MEDIA_L   5
//#define I_I       34
//#define I_L       1
//#define LOVE_I    44
//#define LOVE_L    4
//#define YOU_I     45
//#define YOU_L     3

#define UNA_I     0
#define UNA_L     1
#define DOS_I     1
#define DOS_L     1
#define TRES_I    2
#define TRES_L    1
#define CUATRO_I  3
#define CUATRO_L  1
#define CINCO_I   4
#define CINCO_L   1
#define SEIS_I    5
#define SEIS_L    1
#define SIETE_I   6
#define SIETE_L   1
#define OCHO_I    7
#define OCHO_L    1
#define NUEVE_I   8
#define NUEVE_L   1
#define DIEZ_I    9
#define DIEZ_L    1
#define ONCE_I    10
#define ONCE_L    1
#define DOCE_I    11
#define DOCE_L    1
#define MENOS_I   16
#define MENOS_L   5
#define Y_I       21
#define Y_L       1
#define CINCOM_I  24
#define CINCOM_L  1
#define DIEZM_I   25
#define DIEZM_L   1
#define CUARTO_I  26
#define CUARTO_L  1
#define MEDIA_I   27
#define MEDIA_L   1
#define I_I       32
#define I_L       1
#define LOVE_I    33
#define LOVE_L    1
#define YOU_I     34
#define YOU_L     1

// Prototypes
void CleanWords(CRGB *leds, uint8_t length);
void SetHoursWord(CRGB *leds, uint8_t hours, uint8_t minutes);
void SetMinutesWord(CRGB *leds, uint8_t minutes);
void SetConnectorWord(CRGB *leds, uint8_t minutes);
void SetSpecialWords(CRGB *leds);
uint8_t getMinutesStatus(uint8_t minutes);

#endif
