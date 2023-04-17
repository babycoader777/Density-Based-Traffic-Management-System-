#define F_CPU 8000000UL
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

#define R1 PA0
#define Y1 PA1
#define G1 PA2

#define R2 PA3
#define Y2 PA4
#define G2 PA5

#define R3 PB0
#define Y3 PB1
#define G3 PB6

#define R4 PB3
#define Y4 PB4
#define G4 PB5

int main(void)
{
	DDRA=0xff;             //make port A output
	DDRB=0xff;            // make port B output
	DDRC=0x00;             //make port C input
	//DDRC|=(1<<4);
	//DDRC|=(1<<5);
	//DDRC|=(1<<6);
	//DDRC|=(1<<7);
	
	//DDRB=0xff;
	
	DDRD &=~(1<<PD2);       //make pd2 an i/p pin (INT0 pin)
	PORTD|=(1<<PD2);        //activate the pull up
	
	DDRD &=~(1<<PD3);       //make pd3 an i/p pin (INT1 pin)
	PORTD|=(1<<PD3);        //activate the pull up
	
	DDRB &=~(1<<PB2);       //make pb2 an i/p pin (INT2 pin)
	PORTB|=(1<<PB2);        //activate the pull up
	
	GICR=0xE0 ;         //enable external interrupt
	
	// _delay_ms(50);
	//MCUCR=0x00;             //make int0 as level triggerred interrupt
	sei();                   //enable interrupts
	while(1)
	{
		PORTA = 0x00;
		PORTB = 0x00;
		if((PINC&0x10) == 0x00)
		{
			
		}
		else
		{
			
			PORTA |= (1<<G1);
			PORTA |= (1<<Y2);
			PORTB |= (1<<R3);
			PORTB |= (1<<R4);
			
			_delay_ms(100);
			PORTA = 0x00;
			PORTB = 0x00;
			
		}
		// _delay_ms(50);
		if((PINC&0x02) == 0x00)
		{
			
		}
		
		else
		{
			PORTA |= (1<<R1);
			PORTA |= (1<<G2);
			PORTB |= (1<<Y3);
			PORTB |= (1<<R4);
			
			
			_delay_ms(100);
			PORTA = 0x00;
			PORTB = 0x00;
			
			
		}
		// _delay_ms(50);
		if((PINC&0x04) == 0x00)
		{
			
		}
		else
		{
			PORTA |= (1<<R1);
			PORTA |= (1<<R2);
			PORTB |= (1<<G3);
			PORTB |= (1<<Y4);
			
			_delay_ms(100);
			PORTA = 0x00;
			PORTB = 0x00;

		}
		//	 _delay_ms(50);
		if((PINC&0x08) == 0x00)
		{

			
		}
		else
		{
			PORTA |= (1<<Y1);
			PORTA |= (1<<R2);
			PORTB |= (1<<R3);
			PORTB |= (1<<G4);
			
			_delay_ms(100);
			PORTA = 0x00;
			PORTB = 0x00;
		}
		
		
	}
	return 0;
}

ISR(INT0_vect)
{
	PORTA = 0x00;
	PORTB = 0x00;
	//PORTC=0x00;
	
	PORTA |= (1<<G1);
	PORTA |= (1<<Y2);
	PORTB |= (1<<R3);
	PORTB |= (1<<R4);
	
	//	PORTC |= (1<<PC0);
	_delay_ms(300);
	
	//PORTA = 0x00;
	//PORTB = 0x00;
}


ISR(INT1_vect)
{
	
	PORTA = 0x00;
	PORTB = 0x00;
	//PORTC=0x00;
	
	PORTA |= (1<<R1);
	PORTA |= (1<<G2);
	PORTB |= (1<<Y3);
	PORTB |= (1<<R4);
	
	//PORTC |= (1<<PC1);
	_delay_ms(300);
	
	
	//PORTA = 0x00;
	//PORTB = 0x00;
}

ISR(INT2_vect)
{
	PORTA = 0x00;
	PORTB = 0x00;
	//PORTC=0x00;
	
	PORTA |= (1<<R1);
	PORTA |= (1<<R2);
	PORTB |= (1<<G3);
	PORTB |= (1<<Y4);
	
	//PORTC |= (1<<PC2);
	_delay_ms(300);
	
	// 	 PORTA = 0x00;
	// 	 PORTB = 0x00;
}