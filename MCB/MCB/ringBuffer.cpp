#include "ringBuffer.h"


ringBuffer::ringBuffer(int len)
{
	bytes = 0;
	size = len;
	index = 0
	buf = new char[len];
}
ringBuffer::~ringBuffer()
{
	delete buf;
}
int ringBuffer::push(char me)
{
	if(bytes == size)
	{
		return -1;
	}
	else
	{
		buf[(index+bytes)%size] = me;
		bytes++;
		return 0;
	}
}
int ringBuffer::pop()
{
	if(bytes == 0)
	{
		return -1;
	}
	else
	{
		int retVal = buf[index];
		bytes--;
		index = (index + 1)%size;
		return retVal;
	}
}
