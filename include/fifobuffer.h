#ifndef _FIFO_BUFFER_H_
#define _FIFO_BUFFER_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
	void*	 Buffer;
	uint32_t ElementSize;
	uint32_t NumElements;
	uint32_t Head;
	uint32_t Tail;
	bool	 Full;
	bool	 Empty;
} FifoBuffer;

void  FifoBuffer_Init(FifoBuffer* fifo, void* buff, uint32_t elementSize, uint32_t numElements);
void* FifoBuffer_Add(FifoBuffer* fifo);
void* FifoBuffer_Remove(FifoBuffer* fifo);

#endif
