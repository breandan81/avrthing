/* copyright Breandan O'Shaughnessy, may be distributed under GPL, any version 
Goal here is to define only the functions needed for a polling (no interrupts) TWI master send and receive
functionality.  There are a million ways this could be expanded to take advantage of multimaster, interrupts,
etc.  The goal of RodLogic is KISS 
*/

int sendCommand(char slave, command = 0); //returns -1 if fails
int sendStop(); //sends a stop condition
int rcvByte(); //if twint is set pulls the last byte out and clears it, otherwise returns -1
int sendByte();//sends a Byte
int sendStop();//ends transmission
int rcvFrom();//begins a master receive


char status = 0; 
#define CLEAR 0
#define SENDING 1
#define RECEIVING 2





