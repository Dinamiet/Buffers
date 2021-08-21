#ifndef _FIFO_BUFFER_H_
#define _FIFO_BUFFER_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct
{
	void*	 Buffer;
	size_t ElementSize;
	size_t NumElements;
	size_t Head;
	size_t Tail;
	bool	 Full;
	bool	 Empty;
} FifoBuffer;

void  FifoBuffer_Init(FifoBuffer* fifo, void* buff, size_t elementSize, size_t numElements);
void* FifoBuffer_Add(FifoBuffer* fifo);
void* FifoBuffer_Remove(FifoBuffer* fifo);

#endif
