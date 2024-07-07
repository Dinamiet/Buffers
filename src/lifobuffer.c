#include "lifobuffer.h"

void LifoBuffer_Init(LifoBuffer* lifo, void* buff, const size_t elementSize, const size_t numElements)
{
	lifo->Buffer      = buff;
	lifo->ElementSize = elementSize;
	lifo->NumElements = numElements;
	LifoBuffer_Clear(lifo);
}

bool LifoBuffer_Full(const LifoBuffer* lifo) { return (lifo->WorkingIndex == lifo->NumElements); }

bool LifoBuffer_Empty(const LifoBuffer* lifo) { return (lifo->WorkingIndex == 0); }

size_t LifoBuffer_Used(const LifoBuffer* lifo) { return lifo->WorkingIndex; }

size_t LifoBuffer_Free(const LifoBuffer* lifo) { return lifo->NumElements - lifo->WorkingIndex; }

void* LifoBuffer_Add(LifoBuffer* lifo)
{
	if (LifoBuffer_Full(lifo))
		return NULL;

	size_t offset = lifo->WorkingIndex++ * lifo->ElementSize;

	return lifo->Buffer + offset;
}

void* LifoBuffer_Remove(LifoBuffer* lifo)
{
	if (LifoBuffer_Empty(lifo))
		return NULL;

	size_t offset = --lifo->WorkingIndex * lifo->ElementSize;

	return lifo->Buffer + offset;
}

void LifoBuffer_Clear(LifoBuffer* lifo) { lifo->WorkingIndex = 0; }
