#include "user.h"
#include "digitalIO.h"
#define blinkPin 22

void  setup()
{
	setDirection(blinkPin, 1);
	
}

void loop()
{
	static char state = 0;

//	printf("toggling pin %d \n\r", blinkPin);
	state = !state;
	digitalWrite(blinkPin, state);
	unsigned int time = millis();
	//printf("%d \n\r", time);
	while(millis()-time < 500)
	;//	printf("%d\r", (unsigned int)millis()-time);
	
}
