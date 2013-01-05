#ifndef ANALOGIO_H
#define ANALOGIO_H

//variables

//prototypes
short 	getPin(short me);
void  	setRefVCC(void);
void	setRef(short me);
void 	setRefInternal(void);
void	setRefExternal(void);
short 	setPin(short me);
short 	convert(void);
short	analogRead(short me);
void	setDefaults(void);
void 	analogSetup(void);
#endif
