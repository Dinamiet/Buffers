#include "fifobuffer.h"

#include <stdint.h>
#include <string.h>

void FifoBuffer_Init(FifoBuffer* fifo, void* buff, size_t elementSize, size_t numElements)
{
	fifo->Buffer	  = buff;
	fifo->ElementSize = elementSize;
	fifo->NumElements = numElements;
	fifo->Head		  = 0;
	fifo->Tail		  = 0;
	fifo->Full		  = false;
	fifo->Empty		  = true;
}

void* FifoBuffer_Add(FifoBuffer* fifo)
{
	if (fifo->Full)
		return NULL;

	size_t offset = fifo->Head++ * fifo->ElementSize;

	if (fifo->Head >= fifo->NumElements) // Wrap around at buffer end
		fifo->Head = 0;

	fifo->Full	= fifo->Head == fifo->Tail;
	fifo->Empty = false; // Cannot be empty - just added element

	return (uint8_t*)fifo->Buffer + offset;
}

void* FifoBuffer_Remove(FifoBuffer* fifo)
{
	if (fifo->Empty)
		return NULL;

	size_t offset = fifo->Tail++ * fifo->ElementSize;

	if (fifo->Tail >= fifo->NumElements) // Wrap around at buffer end
		fifo->Tail = 0;

	fifo->Empty = fifo->Head == fifo->Tail;
	fifo->Full	= false; // Cannot be full - just removed element

	return (uint8_t*)fifo->Buffer + offset;
}
