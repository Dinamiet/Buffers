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

bool StackBuffer_Add(StackBuffer* stack, void* element)
{
	if (stack->Full)
		return false;

	uint32_t offset = stack->Head * stack->ElementSize;
	memcpy((uint8_t*)stack->Buffer + offset, element, stack->ElementSize);

	stack->Full	 = ++stack->Head == stack->NumElements;
	stack->Empty = false; // Cannot be full - just added element

	return true;
}

bool StackBuffer_Remove(StackBuffer* stack, void* element)
{
	if (stack->Empty)
		return false;

	uint32_t offset = --stack->Head * stack->ElementSize;
	memcpy(element, (uint8_t*)stack->Buffer + offset, stack->ElementSize);

	stack->Empty = stack->Head == 0;
	stack->Full	 = false; // Cannot be empty - just removed element

	return true;
}
