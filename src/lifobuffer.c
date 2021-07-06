#include "lifobuffer.h"

#include <string.h>

void LifoBuffer_Init(LifoBuffer* lifo, void* buff, uint32_t elementSize, uint32_t numElements)
{
	lifo->Buffer	   = buff;
	lifo->ElementSize = elementSize;
	lifo->NumElements = numElements;
	lifo->Head		   = 0;
	lifo->Full		   = false;
	lifo->Empty	   = true;
}

void* LifoBuffer_Add(LifoBuffer* lifo)
{
	if (lifo->Full)
		return NULL;

	uint32_t offset = lifo->Head * lifo->ElementSize;

	lifo->Full	 = ++lifo->Head == lifo->NumElements;
	lifo->Empty = false; // Cannot be full - just added element

	return (uint8_t*)lifo->Buffer + offset;
}

void* LifoBuffer_Remove(LifoBuffer* lifo)
{
	if (lifo->Empty)
		return NULL;

	uint32_t offset = --lifo->Head * lifo->ElementSize;

	lifo->Empty = lifo->Head == 0;
	lifo->Full	 = false; // Cannot be empty - just removed element

	return (uint8_t*)lifo->Buffer + offset;
}
