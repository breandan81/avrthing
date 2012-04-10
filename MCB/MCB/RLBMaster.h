/* copyright Breandan O'Shaughnessy, may be distributed under GPL, any version 
Goal here is to define only the functions needed for a polling (no interrupts) TWI master send and receive
functionality.  There are a million ways this could be expanded to take advantage of multimaster, interrupts,
etc.  The goal of RodLogic is KISS 
*/
extern "C"
{
#include "MCB.h"
}

#include <avr/io.h>
#include <stdio.h>

int RLBbegin(char slave, char receive); //returns -1 if fails
int RLBrcvByte(); //if twint is set pulls the last byte out and clears it, otherwise returns -1
int RLBsendByte();//sends a Byte
int RLBstop();//ends transmission
void RLBinit();


char status = 0; 





