#include <stdlib.h>

extern "C" void __cxa_pure_virtual(void); 

void * operator new[](size_t size);
void * operator new(size_t size);
void operator delete(void * ptr); 

