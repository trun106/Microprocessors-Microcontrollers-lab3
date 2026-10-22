/*
 * led_display.c
 *
 *  Created on: Oct 21, 2026
 *      Author: trungvu
 */

#include "main.h"
#include "led_display.h"

//init
int led_buffer[4] = {0, 5, 0, 3};

void updateClockBuffer(int val1, int val2){
	//1st pair EN0, EN1
    led_buffer[0] = val1 / 10;//en0
    led_buffer[1] = val1 % 10;//1

    //2nd pair 2, 3
    led_buffer[2] = val2 / 10;//2
    led_buffer[3] = val2 % 10;//3
}

void display7SEG(int counter){
    switch(counter){
        case 0:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, SET);
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, SET);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, RESET);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, RESET);
            break;
        case 4:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, RESET);
            break;
        case 5:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, RESET);
            break;
        case 6:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, RESET);
            break;
        case 7:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, SET);
            break;
        case 8:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, RESET);
            break;
        case 9:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, RESET);
            break;
        default:
            HAL_GPIO_WritePin(GPIOA, SEG0_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG1_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG2_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG3_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG4_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG5_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, SEG6_Pin, SET);
            break;
    }
}

void update7SEG(int index){
    switch(index){
        case 0:
            HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
            display7SEG(led_buffer[0]);
            break;
        case 1:
            HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
            display7SEG(led_buffer[1]);
            break;
        case 2:
            HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
            HAL_GPIO_WritePin(GPIOA, EN3_Pin, SET);
            display7SEG(led_buffer[2]);
            break;
        case 3:
            HAL_GPIO_WritePin(GPIOA, EN0_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, EN1_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, EN2_Pin, SET);
            HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
            display7SEG(led_buffer[3]);
            break;
        default:
            break;
    }
}

//(1,0,0) red light, all black
void setTrafficLightRoad1(int r, int y, int g){
    HAL_GPIO_WritePin(GPIOB, R1_Pin, r? RESET: SET);
    HAL_GPIO_WritePin(GPIOB, Y1_Pin, y? RESET: SET);
    HAL_GPIO_WritePin(GPIOB, G1_Pin, g? RESET: SET);
}

void setTrafficLightRoad2(int r, int y, int g){
    HAL_GPIO_WritePin(GPIOB, R2_Pin, r? RESET: SET);
    HAL_GPIO_WritePin(GPIOB, Y2_Pin, y? RESET: SET);
    HAL_GPIO_WritePin(GPIOB, G2_Pin, g? RESET: SET);
}

void turnOffAllTrafficLEDs(){
    HAL_GPIO_WritePin(GPIOB, R1_Pin | Y1_Pin | G1_Pin | R2_Pin | Y2_Pin | G2_Pin, SET);
}

void blinkRed(){
    HAL_GPIO_TogglePin(GPIOB, R1_Pin | R2_Pin);
}

void blinkYellow() {
    HAL_GPIO_TogglePin(GPIOB, Y1_Pin | Y2_Pin);
}

void blinkGreen(){
    HAL_GPIO_TogglePin(GPIOB, G1_Pin | G2_Pin);
}
