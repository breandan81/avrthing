#include "user.h"

char input[20];
void setup()
{
	gets(input);
	puts("beginning now... \n");
}

void loop()
{
	puts("Would you like to play a game? (y/m)\n");
	gets(input);
	switch(input[0])
	{
		case 'y':
			puts("lets play thermonuclear war\n");
			break;
		case 'n':
			puts("smart move, only way to win is not to play");
			break;
		
	}
}
