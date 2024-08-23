#include "lifobuffer.h"

#include <assert.h>

void LifoBuffer_Init(LifoBuffer* lifo, void* buff, const size_t elementSize, const size_t numElements)
{
	assert(lifo != NULL);
	assert(buff != NULL);
	assert(elementSize > 0);

	lifo->Buffer      = buff;
	lifo->ElementSize = elementSize;
	lifo->NumElements = numElements;
	LifoBuffer_Clear(lifo);
}

bool LifoBuffer_Full(const LifoBuffer* lifo)
{
	assert(lifo != NULL);

	return (lifo->WorkingIndex == lifo->NumElements);
}

bool LifoBuffer_Empty(const LifoBuffer* lifo)
{
	assert(lifo != NULL);

	return (lifo->WorkingIndex == 0);
}

size_t LifoBuffer_Used(const LifoBuffer* lifo)
{
	assert(lifo != NULL);

	return lifo->WorkingIndex;
}

size_t LifoBuffer_Free(const LifoBuffer* lifo)
{
	assert(lifo != NULL);

	return lifo->NumElements - lifo->WorkingIndex;
}

void* LifoBuffer_Add(LifoBuffer* lifo)
{
	assert(lifo != NULL);

	if (LifoBuffer_Full(lifo))
		return NULL;

	size_t offset = lifo->WorkingIndex++ * lifo->ElementSize;

	return lifo->Buffer + offset;
}

void* LifoBuffer_Remove(LifoBuffer* lifo)
{
	assert(lifo != NULL);

	if (LifoBuffer_Empty(lifo))
		return NULL;

	size_t offset = --lifo->WorkingIndex * lifo->ElementSize;

	return lifo->Buffer + offset;
}

void LifoBuffer_Clear(LifoBuffer* lifo)
{
	assert(lifo != NULL);

	lifo->WorkingIndex = 0;
}
