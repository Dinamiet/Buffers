#ifndef _LIFO_BUFFER_H_
#define _LIFO_BUFFER_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct _LifoBuffer_
{
	uint8_t* Buffer;
	size_t   ElementSize;
	size_t   NumElements;
	size_t   WorkingIndex;
} LifoBuffer;

void   LifoBuffer_Init(LifoBuffer* lifo, void* buff, size_t elementSize, size_t numElements);
bool   LifoBuffer_Full(LifoBuffer* lifo);
bool   LifoBuffer_Empty(LifoBuffer* lifo);
size_t LifoBuffer_Used(LifoBuffer* lifo);
size_t LifoBuffer_Free(LifoBuffer* lifo);
void*  LifoBuffer_Add(LifoBuffer* lifo);
void*  LifoBuffer_Remove(LifoBuffer* lifo);
void   LifoBuffer_Clear(LifoBuffer* lifo);

#endif
