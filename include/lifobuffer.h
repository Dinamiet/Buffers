#ifndef _LIFO_BUFFER_H_
#define _LIFO_BUFFER_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct
{
	void*	 Buffer;
	size_t ElementSize;
	size_t NumElements;
	size_t Head;
	bool	 Full;
	bool	 Empty;
} LifoBuffer;

void  LifoBuffer_Init(LifoBuffer* lifo, void* buff, size_t elementSize, size_t numElements);
void* LifoBuffer_Add(LifoBuffer* lifo);
void* LifoBuffer_Remove(LifoBuffer* lifo);

#endif
