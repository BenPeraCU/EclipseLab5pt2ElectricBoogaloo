/*
 * button.c
 *
 *  Created on: Sep 30, 2020
 *      Author:
 */

#include "button.h"

/* Configure the S1 Button */
void config_button(void)
{
    //config S1 on the MSP432P401R SimpleLink Launchpad as a button interrupt
    //set up Button Interrupt
    P1 -> DIR &= ~BIT1; //configure 1.1 as input
    P1 -> REN |= BIT1; //enable pull up/down resistor
    P1 -> OUT |= BIT1; //choose pull up resistor

    P1 -> SEL0 &= ~BIT1; //configure as gpio
    P1 -> SEL1 &= ~BIT1;

    P1 -> IFG &= ~BIT1; //clear interrupt flag
    P1 -> IES |= BIT1; //set interrupt at falling edge
    P1 -> IE |= BIT1;   //enable interrupt
}

/* Configure NVIC for Interrupt Source */
void config_nvic_button(void)
{
    //configure the NVIC for the button interrupt source
    __NVIC_EnableIRQ(PORT1_IRQn); //enable interrupts on port 1
}


