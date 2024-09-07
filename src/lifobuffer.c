#include "lifobuffer.h"

#include <assert.h>

void LifoBuffer_Init(LifoBuffer* lifo, void* buffer, const size_t size)
{
	assert(lifo != NULL);
	assert(buffer != NULL);

	lifo->Start = buffer;
	lifo->End   = buffer + size;
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

void* LifoBuffer_Add(LifoBuffer* lifo)
{
	assert(lifo != NULL);
	assert(lifo->Start != NULL);

	if (LifoBuffer_Full(lifo))
		return NULL;

	size_t offset = lifo->WorkingIndex++ * lifo->ElementSize;

	return lifo->Buffer + offset;
}

void* LifoBuffer_Remove(LifoBuffer* lifo)
{
	assert(lifo != NULL);
	assert(lifo->Buffer != NULL);

	if (LifoBuffer_Empty(lifo))
		return NULL;

	size_t offset = --lifo->WorkingIndex * lifo->ElementSize;

	return lifo->Buffer + offset;
}

void LifoBuffer_Clear(LifoBuffer* lifo)
{
	assert(lifo != NULL);

	lifo->WorkingAddress = lifo->Start;
}
