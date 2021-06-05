/*
 * delay.h
 *
 *  Created on: Apr 12, 2021
 *      Author: akimmi
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "stdio.h"
#include "msp.h"

/* DCO Needed Frequencies */

#define FREQ_1_5_MHz CS_CTL0_DCORSEL_0
#define FREQ_3_MHz CS_CTL0_DCORSEL_1
#define FREQ_6_MHz CS_CTL0_DCORSEL_2
#define FREQ_12_MHz CS_CTL0_DCORSEL_3
#define FREQ_24_MHz CS_CTL0_DCORSEL_4
#define FREQ1500 15/10
#define FREQ3 3
#define FREQ6 6
#define FREQ12 12
#define FREQ24 24


/* calls the frequency */

void set_DCO(int FREQUENCY);

/* Causes a software delay of a specified time
This functions should
take in the number of microseconds as an integer and
provide the appropriate delay up to 50 ms.
 */

void delay_us(uint32_t const num_us);


#endif /* DELAY_H_ */
