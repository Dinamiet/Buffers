#include "fifobuffer.h"

#include <assert.h>

void FifoBuffer_Init(FifoBuffer* fifo, void* buff, const size_t elementSize, const size_t numElements)
{
	assert(fifo != NULL);
	assert(buff != NULL);
	assert(elementSize > 0);

	fifo->Buffer      = buff;
	fifo->ElementSize = elementSize;
	fifo->NumElements = numElements;
	FifoBuffer_Clear(fifo);
}

bool FifoBuffer_Full(const FifoBuffer* fifo)
{
	assert(fifo != NULL);

	return (fifo->AddIndex == fifo->RemoveIndex) && fifo->LastAdd;
}

bool FifoBuffer_Empty(const FifoBuffer* fifo)
{
	assert(fifo != NULL);

	return (fifo->AddIndex == fifo->RemoveIndex) && !fifo->LastAdd;
}

size_t FifoBuffer_Used(const FifoBuffer* fifo)
{
	assert(fifo != NULL);

	if (FifoBuffer_Empty(fifo))
		return 0;
	else if (FifoBuffer_Full(fifo))
		return fifo->NumElements;
	else if (fifo->AddIndex > fifo->RemoveIndex)
		return fifo->AddIndex - fifo->RemoveIndex;
	else
		return fifo->NumElements - FifoBuffer_Free(fifo);
}

size_t FifoBuffer_Free(const FifoBuffer* fifo)
{
	assert(fifo != NULL);

	if (FifoBuffer_Full(fifo))
		return 0;
	else if (FifoBuffer_Empty(fifo))
		return fifo->NumElements;
	else if (fifo->AddIndex < fifo->RemoveIndex)
		return fifo->RemoveIndex - fifo->AddIndex;
	else
		return fifo->NumElements - FifoBuffer_Used(fifo);
}

void* FifoBuffer_Add(FifoBuffer* fifo)
{
	assert(fifo != NULL);

	if (FifoBuffer_Full(fifo))
		return NULL;

	size_t offset = fifo->AddIndex++ * fifo->ElementSize; // Convert index to address

	if (fifo->AddIndex >= fifo->NumElements)
		fifo->AddIndex = 0; // Wrap around

	fifo->LastAdd = true;

	return fifo->Buffer + offset;
}

void* FifoBuffer_Remove(FifoBuffer* fifo)
{
	assert(fifo != NULL);

	if (FifoBuffer_Empty(fifo))
		return NULL;

	size_t offset = fifo->RemoveIndex++ * fifo->ElementSize; // Convert index to address

	if (fifo->RemoveIndex >= fifo->NumElements)
		fifo->RemoveIndex = 0; // Wrap around

	fifo->LastAdd = false;

	return fifo->Buffer + offset;
}

void FifoBuffer_Clear(FifoBuffer* fifo)
{
	assert(fifo != NULL);

	fifo->AddIndex    = 0;
	fifo->RemoveIndex = 0;
	fifo->LastAdd     = false;
}
