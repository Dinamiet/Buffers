#include "fifobuffer.h"

#include <assert.h>

void FifoBuffer_Init(FifoBuffer* fifo, void* buff, const size_t size)
{
	assert(fifo != NULL);
	assert(buff != NULL);
	assert(size > 0);

	fifo->Start = buff;
	fifo->End   = buff + size;
	fifo->Size  = size;

	FifoBuffer_Clear(fifo);
}

bool FifoBuffer_Full(const FifoBuffer* fifo)
{
	assert(fifo != NULL);

	return (fifo->AddAddress == fifo->RemoveAddress) && fifo->LastAdd;
}

bool FifoBuffer_Empty(const FifoBuffer* fifo)
{
	assert(fifo != NULL);

	return (fifo->AddAddress == fifo->RemoveAddress) && !fifo->LastAdd;
}

size_t FifoBuffer_Used(const FifoBuffer* fifo)
{
	assert(fifo != NULL);

	if (FifoBuffer_Empty(fifo))
		return 0;
	else if (FifoBuffer_Full(fifo))
		return fifo->Size;
	else if (fifo->AddAddress > fifo->RemoveAddress)
		return fifo->AddAddress - fifo->RemoveAddress;
	else
		return fifo->Size - FifoBuffer_Free(fifo);
}

size_t FifoBuffer_Free(const FifoBuffer* fifo)
{
	assert(fifo != NULL);

	if (FifoBuffer_Full(fifo))
		return 0;
	else if (FifoBuffer_Empty(fifo))
		return fifo->Size;
	else if (fifo->AddAddress < fifo->RemoveAddress)
		return fifo->RemoveAddress - fifo->AddAddress;
	else
		return fifo->Size - FifoBuffer_Used(fifo);
}

void* FifoBuffer_Add(FifoBuffer* fifo)
{
	assert(fifo != NULL);
	assert(fifo->Buffer != NULL);

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
	assert(fifo->Buffer != NULL);

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

	fifo->AddAddress = fifo->RemoveAddress = fifo->Start;
	fifo->LastAdd     = false;
}
