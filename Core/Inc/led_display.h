/*
 * led_display.h
 *
 *  Created on: Oct 21, 2026
 *      Author: trungvu
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_
#include "main.h"

//segment
#define SEG0_Pin GPIO_PIN_1
#define SEG1_Pin GPIO_PIN_2
#define SEG2_Pin GPIO_PIN_3
#define SEG3_Pin GPIO_PIN_4
#define SEG4_Pin GPIO_PIN_5
#define SEG5_Pin GPIO_PIN_6
#define SEG6_Pin GPIO_PIN_7

//enable
#define EN0_Pin GPIO_PIN_8
#define EN1_Pin GPIO_PIN_9
#define EN2_Pin GPIO_PIN_10
#define EN3_Pin GPIO_PIN_11

//traffic lights
#define R1_Pin GPIO_PIN_4
#define Y1_Pin GPIO_PIN_5
#define G1_Pin GPIO_PIN_6
#define R2_Pin GPIO_PIN_7
#define Y2_Pin GPIO_PIN_8
#define G2_Pin GPIO_PIN_9

void display7SEG(int counter);
void update7SEG(int index);
void updateClockBuffer(int val1, int val2);

void setTrafficLightRoad1(int red, int yellow, int green);
void setTrafficLightRoad2(int red, int yellow, int green);
void turnOffAllTrafficLEDs();
void blinkRed();
void blinkYellow();
void blinkGreen();

#endif /* INC_LED_DISPLAY_H_ */
