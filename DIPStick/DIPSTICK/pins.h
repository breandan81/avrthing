#include <avr/pgmspace.h> 

//This file defines pin mappings for the board, allowing digitalWrite and read to work
#define maxPin 40

int pinMappings[40] PROGMEM = //highbyte is port, low byte is pin number
{
0x0506,//1
0,//2
0,//3
0,//4
0,//5
0,//6
0,//7
0x0200,//8
0x0201,//9
0x0202,//10
0x0203,//11
0x0207,//12
0,//13
0,//14
0,//15
0x0400,//16
0x0401,//17
0x0402,//18
0x0403,//19
0x0405,//20
0,//21
0x0404,//22
0x0406,//23
0x0407,//24
0x0204,//25
0x0205,//26
0x0206,//27
0x0307,//28
0x0502,//29
0,//30
0x0306,//31
0,//32
0x0607,//33
0x0606,//34
0x0605,//35
0x0604,//36
0x0601,//37
0x0600,//38
0,//39
0
};

char *ports[7] PROGMEM = {NULL, &PORTA, &PORTB, &PORTC, &PORTD, &PORTE, &PORTF};
char *inputs[7] PROGMEM = {NULL, &PINA, &PINB, &PINC, &PIND, &PINE, &PINF};
char *ddrs[7] PROGMEM = {NULL, &DDRA, &DDRB, &DDRC, &DDRD, &DDRE, &DDRF};


