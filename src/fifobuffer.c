#include "fifobuffer.h"

#include <assert.h>
#include <string.h>

void FifoBuffer_Init(FifoBuffer* fifo, void* buff, const size_t size)
{
	assert(fifo != NULL);
	assert(buff != NULL);
	assert(size > 0);

	fifo->Start = buff;
	fifo->End   = fifo->Start + size;

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
	assert(fifo->Start != NULL); // Init check

	size_t size = fifo->End - fifo->Start;

	if (fifo->AddAddress == fifo->RemoveAddress)
		return fifo->LastAdd ? size : 0;

	size_t used = fifo->AddAddress - fifo->RemoveAddress;
	if (fifo->AddAddress < fifo->RemoveAddress)
		used += size;

	return used;
}

size_t FifoBuffer_Free(const FifoBuffer* fifo)
{
	assert(fifo != NULL);
	assert(fifo->Start != NULL); // Init check

	size_t size = fifo->End - fifo->Start;
	if (fifo->RemoveAddress == fifo->AddAddress)
		return (!fifo->LastAdd) ? size : 0;

	size_t free = fifo->RemoveAddress - fifo->AddAddress;
	if (fifo->RemoveAddress < fifo->AddAddress)
		free += size;

	return free;
}

size_t FifoBuffer_Add(FifoBuffer* fifo, const void* _data, const size_t size)
{
	assert(fifo != NULL);
	assert(fifo->Start != NULL);

	const uint8_t* data = _data;

	if (!data)
		return 0;

	if (FifoBuffer_Full(fifo) || size == 0)
		return 0;

	fifo->LastAdd = true;

	// Check how much can be copied without overrunning
	size_t spaceToEnd = fifo->End - fifo->AddAddress;
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

size_t FifoBuffer_Remove(FifoBuffer* fifo, void* _data, const size_t size)
{
	assert(fifo != NULL);
	assert(fifo->Start != NULL);

	uint8_t* data = _data;

	if (FifoBuffer_Empty(fifo) || size == 0)
		return 0;

	fifo->LastAdd = false;

	// Check how much can be copied without overrunning
	size_t spaceToEnd = fifo->End - fifo->RemoveAddress;
	if (fifo->AddAddress > fifo->RemoveAddress)
		spaceToEnd = fifo->AddAddress - fifo->RemoveAddress;

	if (spaceToEnd < size) // Have to split copy
	{
		if (data)
			memcpy(data, fifo->RemoveAddress, spaceToEnd);
		fifo->RemoveAddress += spaceToEnd;
		if (fifo->RemoveAddress >= fifo->End)
			fifo->RemoveAddress = fifo->Start;

		return spaceToEnd + FifoBuffer_Remove(fifo, data ? &data[spaceToEnd] : NULL, size - spaceToEnd);
	}

	// No need to split copy
	if (data)
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
