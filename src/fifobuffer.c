#include "fifobuffer.h"

#include <assert.h>
#include <string.h>

void FifoBuffer_Init(FifoBuffer* fifo, void* buffer, const size_t size)
{
	assert(fifo != NULL);
	assert(buffer != NULL);
	assert(size > 0);

	fifo->Start = buffer;
	fifo->End   = fifo->Start + size;
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

/** TODO: Check if this function can use less if statements */
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

/** TODO: Check if this function can use less if statements */
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

size_t FifoBuffer_Add(FifoBuffer* fifo, void* _data, size_t size)
{
	assert(fifo != NULL);
	assert(fifo->Start != NULL);
	assert(_data != NULL);

	uint8_t* data = _data;

	if (FifoBuffer_Full(fifo))
		return 0;

	// Check how much can be copied without overrunning
	ssize_t spaceToEnd = fifo->End - fifo->AddAddress;
	if (fifo->RemoveAddress > fifo->AddAddress)
		spaceToEnd = fifo->RemoveAddress - fifo->AddAddress;

	if (spaceToEnd < size) // Have to split copy
	{
		memcpy(fifo->AddAddress, data, spaceToEnd);
		fifo->AddAddress += spaceToEnd;
		if (fifo->AddAddress >= fifo->End) // Wrap around
			fifo->AddAddress = fifo->Start;
		return spaceToEnd + FifoBuffer_Add(fifo, &data[spaceToEnd], size - spaceToEnd);
	}

	// No need to split copy
	memcpy(fifo->AddAddress, data, size);
	fifo->AddAddress += size;
	if (fifo->AddAddress >= fifo->End) // Wrap around
		fifo->AddAddress = fifo->Start;
	return size;
}

size_t FifoBuffer_Remove(FifoBuffer* fifo, void* _data, size_t size)
{
	assert(fifo != NULL);
	assert(fifo->Start != NULL);
	assert(_data != NULL);

	uint8_t* data = _data;

	if (FifoBuffer_Empty(fifo))
		return 0;

	size_t spaceToEnd = fifo->End - fifo->RemoveAddress;
	if (fifo->AddAddress > fifo->RemoveAddress)
		spaceToEnd = fifo->AddAddress - fifo->RemoveAddress;

	if (spaceToEnd < size) // Have to split copy
	{
		memcpy(data, fifo->RemoveAddress, spaceToEnd);
		fifo->RemoveAddress += spaceToEnd;
		if (fifo->RemoveAddress >= fifo->End)
			fifo->RemoveAddress = fifo->Start;
		return spaceToEnd + FifoBuffer_Add(fifo, &data[spaceToEnd], size - spaceToEnd);
	}

	// No need to split copy
	memcpy(data, fifo->RemoveAddress, size);
	fifo->RemoveAddress += size;
	if (fifo->RemoveAddress >= fifo->End)
		fifo->RemoveAddress = fifo->Start;

	return size;
}

void FifoBuffer_Clear(FifoBuffer* fifo)
{
	assert(fifo != NULL);

	fifo->AddAddress = fifo->RemoveAddress = fifo->Start;
	fifo->LastAdd     = false;
}
