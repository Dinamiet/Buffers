#ifndef _STACK_BUFFER_H_
#define _STACK_BUFFER_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
	void*	 Buffer;
	uint32_t ElementSize;
	uint32_t NumElements;
	uint32_t Head;
	bool	 Full;
	bool	 Empty;
} StackBuffer;

void StackBuffer_Init(StackBuffer* stack, void* buff, uint32_t elementSize, uint32_t numElements);
void* StackBuffer_Add(StackBuffer* stack);
void* StackBuffer_Remove(StackBuffer* stack);

#endif
