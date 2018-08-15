/*
 * [tkim058]_lab[8]_part[1].c
 * Partner(s) Name & E-mail: MinHwan Oh
 * Lab Section: B01
 * Assignment: Lab #7 Exercise #1
 * Exercise Description: [A2D]
 *
 * I acknowledge all content contained herein, excluding template or example
 * code, is my own original work.
 */ 


#include <avr/io.h>

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
	// ADEN: setting this bit enables analog-to-digital conversion.
	// ADSC: setting this bit starts the first conversion.
	// ADATE: setting this bit enables auto-triggering. Since we are
	//        in Free Running Mode, a new conversion will trigger whenever
	//        the previous conversion completes.
}

int main(void)
{
	DDRB = 0xFF; PORTB = 0x00;
	
	ADC_init();
	
	while (1)
	{
		if(ADC >= 0x000E/2)
		{
			PORTB = 0x01;
		}
		else
		{
			PORTB = 0x00;
		}
	}
}


