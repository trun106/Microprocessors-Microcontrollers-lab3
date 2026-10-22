/*
 * input_processing.c
 *
 *  Created on: Oct 20, 2026
 *      Author: trungvu
 */

#include "main.h"
#include "input_reading.h"
#include "input_processing.h"
#include "led_display.h"
#include "timer.h"

enum ButtonState{BUTTON_RELEASED, BUTTON_PRESSED, BUTTON_PRESSED_MORE_THAN_1_SECOND} ;
static enum ButtonState btnState[3] = {BUTTON_RELEASED, BUTTON_RELEASED, BUTTON_RELEASED};//all btn released initially

#define MODE_1	1 //normal
#define MODE_2  2 //adj red
#define MODE_3	3//adj yellow
#define MODE_4	4//adj green

int mode = MODE_1;

//modified value at adjusting mode 2 3 4
int temp_value = 5;//init to 5

//init
int time_red = 5;
int time_yellow = 2;
int time_green = 3;

//backup if adj dumply like 16 red and 2 yellow, 3 red (red != yellow + green)
int prev_valid_red = 5;//init
int prev_valid_yellow = 2;
int prev_valid_green = 3;

//transistion state betw 2 roads
#define INIT_TRAFFIC		0
#define R1_RED_R2_GREEN 	1//road1 red, road2 green
#define R1_RED_R2_YELLOW 	2//road1 red, road2 to yellow
#define R1_GREEN_R2_RED 	3
#define R1_YELLOW_R2_RED 	4

int traffic_state = INIT_TRAFFIC;
int countdown_road1 = 5;
int countdown_road2 = 3;
int index_7seg = 0;

//return 1 if the button pressed
static int is_button_just_pressed(int index){
    switch(btnState[index]){
        case BUTTON_RELEASED:
            if(is_button_pressed(index)){
                btnState[index] = BUTTON_PRESSED;
                return 1;
            }
            break;
        case BUTTON_PRESSED://to decide press once or hold
            if (!is_button_pressed(index)) {
                btnState[index] = BUTTON_RELEASED;
            } else if (is_button_pressed_1s(index)) {
                btnState[index] = BUTTON_PRESSED_MORE_THAN_1_SECOND;
                setTimerAutoInc(250);
            }
            break;
        case BUTTON_PRESSED_MORE_THAN_1_SECOND:
            if(!is_button_pressed(index)){
                btnState[index] = BUTTON_RELEASED;
            }else if(timer_auto_inc_flag == 1){
                setTimerAutoInc(250); //increment every 250ms when holding
                return 1;//return 1 every 250ms
            }
            break;
    }
    return 0;
}

static void run_normal_traffic_light(){
    switch(traffic_state){
        case INIT_TRAFFIC:
            traffic_state = R1_RED_R2_GREEN;
            countdown_road1 = time_red;
            countdown_road2 = time_green;
            setTrafficLightRoad1(1, 0, 0);//r1 red
            setTrafficLightRoad2(0, 0, 1);//r2 green
            updateClockBuffer(countdown_road1, countdown_road2);
            setTimerTraffic(1000);
            break;

        case R1_RED_R2_GREEN:
            setTrafficLightRoad1(1, 0, 0);
            setTrafficLightRoad2(0, 0, 1);
            if(timer_traffic_flag == 1){
                setTimerTraffic(1000);
                countdown_road1--;
                countdown_road2--;
                if (countdown_road2 <= 0) {
                    traffic_state = R1_RED_R2_YELLOW;
                    countdown_road2 = time_yellow;
                }
                updateClockBuffer(countdown_road1, countdown_road2);
            }
            break;

        case R1_RED_R2_YELLOW:
            setTrafficLightRoad1(1, 0, 0);
            setTrafficLightRoad2(0, 1, 0);
            if(timer_traffic_flag == 1){
                setTimerTraffic(1000);
                countdown_road1--;
                countdown_road2--;
                if(countdown_road2 <= 0 || countdown_road1 <= 0){
                    traffic_state = R1_GREEN_R2_RED;
                    countdown_road1 = time_green;
                    countdown_road2 = time_red;
                }
                updateClockBuffer(countdown_road1, countdown_road2);
            }
            break;

        case R1_GREEN_R2_RED:
            setTrafficLightRoad1(0, 0, 1);
            setTrafficLightRoad2(1, 0, 0);
            if (timer_traffic_flag == 1) {
                setTimerTraffic(1000);
                countdown_road1--;
                countdown_road2--;
                if(countdown_road1 <= 0){
                    traffic_state = R1_YELLOW_R2_RED;
                    countdown_road1 = time_yellow;
                }
                updateClockBuffer(countdown_road1, countdown_road2);
            }
            break;

        case R1_YELLOW_R2_RED:
            setTrafficLightRoad1(0, 1, 0);
            setTrafficLightRoad2(1, 0, 0);
            if(timer_traffic_flag == 1){
                setTimerTraffic(1000);
                countdown_road1--;
                countdown_road2--;
                if(countdown_road1 <= 0 || countdown_road2 <= 0){
                    traffic_state = R1_RED_R2_GREEN;
                    countdown_road1 = time_red;
                    countdown_road2 = time_green;
                }
                updateClockBuffer(countdown_road1, countdown_road2);
            }
            break;
    }
}

void fsm_for_input_processing(void){
	if(timer_7seg_flag == 1){
		setTimer7SEG(50);//50ms
	    update7SEG(index_7seg);
	    index_7seg++;
	    if(index_7seg >= 4){
	    	index_7seg = 0;
	    }
	}

	    switch(mode){
	        case MODE_1:
	            run_normal_traffic_light();

	            if(is_button_just_pressed(0)){//button 1 is pressed (b1 idx 0)
	            	//backup
	            	prev_valid_red = time_red;
	            	prev_valid_yellow = time_yellow;
	            	prev_valid_green = time_green;


	                mode = MODE_2;
	                temp_value = time_red;
	                turnOffAllTrafficLEDs();
	                setTimerBlink(250);//2hz is 250ms period
	                updateClockBuffer(temp_value, mode);
	            }
	            break;

	        case MODE_2:
	            //ex6 blink red
	            if(timer_blink_flag == 1){
	                setTimerBlink(250);
	                blinkRed();
	            }

	            //ex5 button 1 to move adj yellow
	            if(is_button_just_pressed(0)){
	                mode = MODE_3;
	                temp_value = time_yellow;
	                turnOffAllTrafficLEDs();
	                setTimerBlink(250);
	                updateClockBuffer(temp_value, mode);
	            }

	            //ex7 button2 to adj current red
	            if(is_button_just_pressed(1)){
	                temp_value++;
	                if (temp_value > 99) temp_value = 1;
	                updateClockBuffer(temp_value, mode);
	            }

	            //ex7 button 3 to save
	            if(is_button_just_pressed(2)){
	                time_red = temp_value;
	            }
	            break;

	        case MODE_3:
	            //ex6
	            if(timer_blink_flag == 1){
	                setTimerBlink(250);
	                blinkYellow();
	            }

	            //ex5
	            if(is_button_just_pressed(0)){
	                mode = MODE_4;
	                temp_value = time_green;
	                turnOffAllTrafficLEDs();
	                setTimerBlink(250);
	                updateClockBuffer(temp_value, mode);
	            }

	            //ex8
	            if(is_button_just_pressed(1)){
	                temp_value++;
	                if(temp_value > 99) temp_value = 1;
	                updateClockBuffer(temp_value, mode);
	            }

	            //ex8
	            if(is_button_just_pressed(2)){
	                time_yellow = temp_value;
	            }
	            break;

	        case MODE_4:
	            //ex6
	            if(timer_blink_flag == 1){
	                setTimerBlink(250);
	                blinkGreen();
	            }

	            //ex5
	            if(is_button_just_pressed(0)){
	            	if(time_red != (time_green + time_yellow)){
	            		time_red = prev_valid_red;
	            		time_yellow = prev_valid_yellow;
	            		time_green = prev_valid_green;
	            	}

	                mode = MODE_1;
	                traffic_state = INIT_TRAFFIC;
	            }

	            //ex9
	            if(is_button_just_pressed(1)){
	                temp_value++;
	                if(temp_value > 99) temp_value = 1;
	                updateClockBuffer(temp_value, mode);
	            }

	            //ex9
	            if(is_button_just_pressed(2)){
	                time_green = temp_value;
	            }
	            break;
	    }
}

