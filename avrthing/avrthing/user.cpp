#include "user.h"
#include "digitalIO.h"
#include "ringBuffer.h"
#include "delays.h"
#include "analogIO.h"


ringBuffer me(8);
int cur = 0;
void  setup()
{
	analogSetup();

	delayMillis(2000);
}
void loop()
{
	delayMillis(100);

/*	printf("pin 38 reads: %d \n\r", analogRead(38));
	printf("pin 37 reads: %d \n\r", analogRead(37));
	printf("pin 36 reads: %d \n\r", analogRead(36));
	printf("pin 35 reads: %d \n\r", analogRead(35));
	printf("pin 34 reads: %d \n\r", analogRead(34));
	printf("pin 33 reads: %d \n\r", analogRead(33));	
	printf("pin 22 reads: %d \n\r", analogRead(22));
	printf("pin 23 reads: %d \n\r", analogRead(23));
	printf("pin 24 reads: %d \n\r", analogRead(24));
	printf("pin 25 reads: %d \n\r", analogRead(25));
	printf("pin 26 reads: %d \n\r", analogRead(26));
	printf("pin 27 reads: %d \n\r\n\r\n\r", analogRead(27));
*/
	printf("123456\n\r");
}
