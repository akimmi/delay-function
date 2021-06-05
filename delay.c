/*
 * delay.c
 *
 *  Created on: Apr 12, 2021
 *      Author: akimmi
 */

#include "msp.h"
#include "delay.h"
#include <stdint.h>

//set_DCO is a function that is setting the CS registers
//to set the DCO CLK frequency to a specified value
int frequency = FREQ_1_5_MHz;

void set_DCO(int FREQUENCY) {
    CS->KEY = CS_KEY_VAL;            // Unlock CS module for register access
    CS->CTL0 = 0;                    //Clear registers for re-init
    CS->CTL0 = FREQUENCY;
    frequency = FREQUENCY;
    // Set DCO to specified frequency
    // Select ACLK = REFO, SMCLK = MCLK = DCO
    CS->CTL1 = CS_CTL1_SELA_2 | CS_CTL1_SELS_3 | CS_CTL1_SELM_3;
    CS->KEY = 0;                            // Lock CS module from unintended accesses

}



void delay_us(uint32_t const num_us) {
    uint32_t loops = 0;
    uint32_t x = 0;
    switch(CS->CTL0){ // setup different cases for MCLK freq
        case FREQ_1_5_MHz:
           loops = num_us*FREQ1500-50; //
           break;
        case FREQ_3_MHz:
           loops = num_us*FREQ3-50;
           break;
        case FREQ_6_MHz:
            loops = num_us*FREQ6-50;
            break;
        case FREQ_12_MHz:
            loops = num_us*FREQ12-50;
            break;
        case FREQ_24_MHz:
            loops = num_us*FREQ24-50;
            break;
    }
        for(x=0; x<loops; x+=12) // delay by the set ‘loops’ value  THERES 12 CYCLES. CHECK DATA SHEET. IF THERE ARE QUESTIONS
            __delay_cycles(1);
}



























/*
   * convert your int delay val;ue to us
   * int u_sec = delay (do math to convert to us)
   *
   * switch(frequency){
   *   case FREQ_1_5_MHz:
   *       //use u_sec rather than delay
   *   case FREQ_3_MHz:
   *       //Frequency = 1/s = figure out the period of each clk, and how to convert that to a proper delay us
   *
   *
   *
   *
   */
