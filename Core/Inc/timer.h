/*
 * timer.h
 *
 *  Created on: Oct 21, 2026
 *      Author: trungvu
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIMER_CYCLE 10

extern int timer_traffic_flag; // 1-second timer for Mode 1 traffic countdown
extern int timer_blink_flag;   // 250ms timer for 2Hz LED blinking
extern int timer_7seg_flag;    // Timer for scanning the 4 7-segment displays
extern int timer_auto_inc_flag;// 250ms timer for holding Button 2 > 1 second

void setTimerTraffic(int duration);
void setTimerBlink(int duration);
void setTimer7SEG(int duration);
void setTimerAutoInc(int duration);
void timer_run();

#endif /* INC_TIMER_H_ */
