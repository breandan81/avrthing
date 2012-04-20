#include <digitalIO.h>
#include <avr/io.h>
#define NULL 0


unsigned char pins[40] = 
{
	0x56,//1
	0x00,
	0x00,
	0x00,
	0x00,//5
	0x00,
	0x00,
	0x20,
	0x21,
	0x22,//10
	0x23,
	0x27,
	0x00,
	0x00,
	0x00,//15
	0x40,
	0x41,
	0x42,
	0x43,
	0x45,//20
	0x00,
	0x44,//22
	0x46,
	0x47,
	0x44,

	0x45,
	0x46,
	0x47,
	0x52,
	0x00,

	0x36,
	0x00,
	0x67,
	0x65,
	0x66,

	0x64,
	0x61,
	0x60,
	0x00,
	0x00};

volatile uint8_t *outs[7] = {NULL, NULL, &PORTB, &PORTC, &PORTD, &PORTE, &PORTF}; 
volatile uint8_t *ins[7]  = {NULL, NULL, &PINB, &PINC, &PIND, &PINE, &PINF}; 
volatile uint8_t *ddrs[7] = {NULL, NULL, &DDRB, &DDRC, &DDRD, &DDRE, &DDRF}; 

volatile uint8_t *getPORT(int x);
volatile uint8_t *getDDR(int x);
volatile uint8_t *getPIN(int x);


#define maxPin 40
#include <stdio.h>

volatile uint8_t *getPORT(int x)
{
	if(x > maxPin)
		return NULL;

	else
	{	
		return outs[pins[x-1] >>4];
	}
}
volatile uint8_t *getPIN(int x)
{

	if(x > maxPin)
		return NULL;

	else
	{
		return ins[pins[x-1] >> 4];
	}
}

volatile uint8_t *getDDR(int x)
{
	if(x > maxPin)
		return NULL;

	else
		return ddrs[pins[x-1] >> 4];
}

int digitalWrite(char pin, char val)
{
	if(pin > maxPin)
		return -1;
	if(val)
		*getPORT(pin) |= _BV(pins[pin-1] & 0xF);
	else
		*getPORT(pin) &= ~_BV(pins[pin-1] & 0xF);
	return 0;
}

int setDirection(char pin, char val)
{
	if(pin > maxPin)
		return -1;

	if(val)
		*getDDR(pin) |= _BV(pins[pin-1] & 0xF);
	else
		*getDDR(pin) &= ~_BV(pins[pin-1] & 0xF);
	return 0;
}

int digitalRead(char pin)
{

	if(pin > maxPin)
		return -1;

	return (*getPIN(pin) >> (pins[pin-1] & 0xF)) &1;
}
