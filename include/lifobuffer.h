#ifndef _LIFO_BUFFER_H_
#define _LIFO_BUFFER_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
	void*	 Buffer;
	uint32_t ElementSize;
	uint32_t NumElements;
	uint32_t Head;
	bool	 Full;
	bool	 Empty;
} LifoBuffer;

void LifoBuffer_Init(LifoBuffer* lifo, void* buff, uint32_t elementSize, uint32_t numElements);
void* LifoBuffer_Add(LifoBuffer* lifo);
void* LifoBuffer_Remove(LifoBuffer* lifo);

#endif
