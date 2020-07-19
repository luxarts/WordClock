#include "words.hpp"

/* @brief Turn off all the LEDs
 * @param leds: CRGB array
 * @param length: CRGB array's length
 */
void CleanWords(CRGB *leds, uint8_t length){
  for(uint8_t i=0; i<length; i++){
    leds[i]=CRGB(0,0,0);
  }
}

/* @brief Set the LEDs array for the given hours
 * @param leds: CRGB array
 * @param hours: Hour (range 1 to 12)
 * @param minutes: Minutes (range 0 to 59)
 */
void SetHoursWord(CRGB *leds, uint8_t hours, uint8_t minutes){
  uint8_t minutesStatus = getMinutesStatus(minutes);
  
  if(minutesStatus == MENOS_CUARTO || minutesStatus == MENOS_DIEZ || minutesStatus == MENOS_CINCO || minutesStatus == MENOS_EN_PUNTO){
    hours++;
    if(hours>13)hours=1;
  }
  
  uint8_t idx, len;
  switch(hours){
    case 1:
      idx = UNA_I;
      len = UNA_L;
      break;
    case 2:
      idx = DOS_I;
      len = DOS_L;
      break;
    case 3:
      idx = TRES_I;
      len = TRES_L;
      break;
    case 4:  
      idx = CUATRO_I;
      len = CUATRO_L;
      break;
    case 5:
      idx = CINCO_I;
      len = CINCO_L;
      break;
    case 6:
      idx = SEIS_I;
      len = SEIS_L;
      break;
    case 7:
      idx = SIETE_I;
      len = SIETE_L;
      break;
    case 8:
      idx = OCHO_I;
      len = OCHO_L;
      break;
    case 9:
      idx = NUEVE_I;
      len = NUEVE_L;
      break;
    case 10:
      idx = DIEZ_I;
      len = DIEZ_L;
      break;
    case 11:
      idx = ONCE_I;
      len = ONCE_L;
      break;
    case 12:
      idx = DOCE_I;
      len = DOCE_L;
      break;
  }
  
  Serial.print("idx: ");
  Serial.print(idx);
  Serial.print("\tlen: ");
  Serial.println(len);
  
  for(uint8_t i=0; i<len; i++){
    leds[idx+i]=HOURS_COLOR;
  }
}

/* @brief Set the LEDs array for the given minutes
 * @param leds: CRGB array
 * @param minutes: Minutes (range 0 to 59)
 */
void SetMinutesWord(CRGB *leds, uint8_t minutes){
  uint8_t minutesStatus = getMinutesStatus(minutes);
  
  uint8_t idx, len=0;
  if (minutesStatus == Y_CINCO || minutesStatus == MENOS_CINCO){
    idx = CINCOM_I;
    len = CINCOM_L;
  }
  else if (minutesStatus == Y_DIEZ || minutesStatus == MENOS_DIEZ){
    idx = DIEZM_I;
    len = DIEZM_L;
  }
  else if (minutesStatus == Y_CUARTO || minutesStatus == MENOS_CUARTO){
    idx = CUARTO_I;
    len = CUARTO_L;
  }
  else if (minutesStatus == Y_MEDIA){
    idx = MEDIA_I;
    len = MEDIA_L;
  }

  for(uint8_t i=0; i<len; i++){
    leds[idx+i]=MINUTES_COLOR;
  }
}

/* @brief Set the LEDs array for the given connector
 * @param leds: CRGB array
 * @param minutes: Minutes (range 0 to 59)
 */
void SetConnectorWord(CRGB *leds, uint8_t minutes){
  uint8_t minutesStatus = getMinutesStatus(minutes);
  
  uint8_t idx, len=0;
  if(minutesStatus == Y_CINCO || minutesStatus == Y_DIEZ || minutesStatus == Y_CUARTO || minutesStatus == Y_MEDIA){
    idx = Y_I;
    len = Y_L;
  }
  else if(minutesStatus == MENOS_CUARTO || minutesStatus == MENOS_DIEZ || minutesStatus == MENOS_CINCO) {
    idx = MENOS_I;
    len = MENOS_L;
  }

  for(uint8_t i=0; i<len; i++){
    leds[idx+i]=CONNECTORS_COLOR;
  }
}

/* @brief Set the LEDs array for the special words
 * @param leds: CRGB array
 */
void SetSpecialWords(CRGB *leds){
  // Word: I
  for(uint8_t i=0; i<I_L; i++){
    leds[I_I+i]=SPECIAL_COLOR;
  }
  // Word: love
  for(uint8_t i=0; i<LOVE_L; i++){
    leds[LOVE_I+i]=SPECIAL_HEART_COLOR;
  }
  // Word: you
  for(uint8_t i=0; i<YOU_L; i++){
    leds[YOU_I+i]=SPECIAL_COLOR;
  }
  // Word: Lu
  for(uint8_t i=0; i<LU_L; i++){
    leds[LU_I+i]=SPECIAL_COLOR;
  }
}

/* @brief Get the minutes with the modifier
 * @param minutes: Minutes (range 0 to 59)
 */
uint8_t getMinutesStatus(uint8_t minutes){ 
  if(minutes>=0 && minutes<3) return EN_PUNTO;
  else if(minutes>2 && minutes<8) return Y_CINCO;
  else if(minutes>7 && minutes<13) return Y_DIEZ;
  else if(minutes>12 && minutes<23) return Y_CUARTO;
  else if(minutes>22 && minutes<38) return Y_MEDIA;
  else if(minutes>37 && minutes<48) return MENOS_CUARTO;
  else if(minutes>47 && minutes<53) return MENOS_DIEZ;
  else if(minutes>52 && minutes<58) return MENOS_CINCO;
  else if(minutes>57 && minutes<60) return MENOS_EN_PUNTO;
}
