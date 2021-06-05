#include "msp.h"
#include "delay.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P4->SEL0 |= BIT3;
	P4->SEL1 &= ~BIT3;
	P4->DIR |= BIT3; // Have now set p4.3 to output the MCLK

	P2->SEL1 &= ~(BIT1);
	P2->SEL0 &= ~(BIT1);
	P2->DIR |= (BIT1);// Have now set up p2.1 for the green LED

	set_DCO(FREQ_1_5_MHz);

	while (1) {
	    P2->OUT = BIT1;
	    delay_us(40000);
	    P2->OUT = 0; // turning off the LEDs
	    delay_us(40000);

	}
}
