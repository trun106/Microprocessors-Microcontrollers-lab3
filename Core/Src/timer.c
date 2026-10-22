/*
 * timer.c
 *
 *  Created on: Oct 20, 2026
 *      Author: trungvu
 */


#include "main.h"
#include "input_reading.h"
#include "timer.h"

int timer_traffic_counter = 0;
int timer_traffic_flag = 0;

int timer_blink_counter = 0;
int timer_blink_flag = 0;

int timer_7seg_counter = 0;
int timer_7seg_flag = 0;

int timer_auto_inc_counter = 0;
int timer_auto_inc_flag = 0;

void setTimerTraffic(int duration){
    timer_traffic_counter = duration / TIMER_CYCLE;
    timer_traffic_flag = 0;
}

void setTimerBlink(int duration){
    timer_blink_counter = duration / TIMER_CYCLE;
    timer_blink_flag = 0;
}

void setTimer7SEG(int duration){
    timer_7seg_counter = duration / TIMER_CYCLE;
    timer_7seg_flag = 0;
}

void setTimerAutoInc(int duration){
    timer_auto_inc_counter = duration / TIMER_CYCLE;
    timer_auto_inc_flag = 0;
}

void timer_run(void){
    if(timer_traffic_counter > 0){
        timer_traffic_counter--;
        if(timer_traffic_counter <= 0) timer_traffic_flag = 1;
    }
    if(timer_blink_counter > 0){
        timer_blink_counter--;
        if(timer_blink_counter <= 0) timer_blink_flag = 1;
    }
    if(timer_7seg_counter > 0){
        timer_7seg_counter--;
        if(timer_7seg_counter <= 0) timer_7seg_flag = 1;
    }
    if(timer_auto_inc_counter > 0){
        timer_auto_inc_counter--;
        if(timer_auto_inc_counter <= 0) timer_auto_inc_flag = 1;
    }
}

//every 10ms by TIM2
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if(htim->Instance == TIM2){
        button_reading();
        timer_run();
    }
}
