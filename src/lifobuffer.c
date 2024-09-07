#include "lifobuffer.h"

#include <assert.h>
#include <string.h>

void LifoBuffer_Init(LifoBuffer* lifo, void* buff, const size_t size)
{
	assert(lifo != NULL);
	assert(buff != NULL);

	lifo->Start = buff;
	lifo->End   = lifo->Start + size;
	LifoBuffer_Clear(lifo);
}

bool LifoBuffer_Full(const LifoBuffer* lifo)
{
	assert(lifo != NULL);

	return (lifo->WorkingAddress == lifo->End);
}

bool LifoBuffer_Empty(const LifoBuffer* lifo)
{
	assert(lifo != NULL);

	return (lifo->WorkingAddress == lifo->Start);
}

size_t LifoBuffer_Used(const LifoBuffer* lifo)
{
	assert(lifo != NULL);

	return lifo->WorkingAddress - lifo->Start;
}

size_t LifoBuffer_Free(const LifoBuffer* lifo)
{
	assert(lifo != NULL);

	return lifo->End - lifo->WorkingAddress;
}

size_t LifoBuffer_Add(LifoBuffer* lifo, const void* data, const size_t size)
{
	assert(lifo != NULL);
	assert(lifo->Start != NULL);

	size_t spaceAvailable = LifoBuffer_Free(lifo);

	if (!spaceAvailable)
		return 0;

	if (size > spaceAvailable)
	{
		memcpy(lifo->WorkingAddress, data, spaceAvailable);
		lifo->WorkingAddress += spaceAvailable;
		return spaceAvailable;
	}

	memcpy(lifo->WorkingAddress, data, size);
	lifo->WorkingAddress += size;
	return size;
}

size_t LifoBuffer_Remove(LifoBuffer* lifo, void* data, const size_t size)
{
	assert(lifo != NULL);
	assert(lifo->Start != NULL);

	size_t spaceUsed = LifoBuffer_Used(lifo);
	if (!spaceUsed)
		return 0;

	if (size > spaceUsed)
	{
		memcpy(data, lifo->WorkingAddress - spaceUsed, spaceUsed);
		lifo->WorkingAddress -= spaceUsed;
		return spaceUsed;
	}

	memcpy(data, lifo->WorkingAddress - size, size);
	lifo->WorkingAddress -= size;
	return size;
}

void LifoBuffer_Clear(LifoBuffer* lifo)
{
	assert(lifo != NULL);

	lifo->WorkingAddress = lifo->Start;
}
