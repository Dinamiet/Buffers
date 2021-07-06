#include "stackbuffer.h"

#include <string.h>

void StackBuffer_Init(StackBuffer* stack, void* buff, uint32_t elementSize, uint32_t numElements)
{
	stack->Buffer	   = buff;
	stack->ElementSize = elementSize;
	stack->NumElements = numElements;
	stack->Head		   = 0;
	stack->Full		   = false;
	stack->Empty	   = true;
}

void* StackBuffer_Add(StackBuffer* stack)
{
	if (stack->Full)
		return NULL;

	uint32_t offset = stack->Head * stack->ElementSize;

	stack->Full	 = ++stack->Head == stack->NumElements;
	stack->Empty = false; // Cannot be full - just added element

	return (uint8_t*)stack->Buffer + offset;
}

void* StackBuffer_Remove(StackBuffer* stack)
{
	if (stack->Empty)
		return NULL;

	uint32_t offset = --stack->Head * stack->ElementSize;

	stack->Empty = stack->Head == 0;
	stack->Full	 = false; // Cannot be empty - just removed element

	return (uint8_t*)stack->Buffer + offset;
}
