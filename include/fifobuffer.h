#ifndef _FIFO_BUFFER_H_
#define _FIFO_BUFFER_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct
{
	uint8_t* Buffer;
	size_t   ElementSize;
	size_t   NumElements;
	size_t   AddIndex;
	size_t   RemoveIndex;
	bool     LastAdd;
} FifoBuffer;

void   FifoBuffer_Init(FifoBuffer* fifo, void* buff, size_t elementSize, size_t numElements);
bool   FifoBuffer_Full(FifoBuffer* fifo);
bool   FifoBuffer_Empty(FifoBuffer* fifo);
size_t FifoBuffer_Used(FifoBuffer* fifo);
size_t FifoBuffer_Free(FifoBuffer* fifo);
void*  FifoBuffer_Add(FifoBuffer* fifo);
void*  FifoBuffer_Remove(FifoBuffer* fifo);
void   FifoBuffer_Clear(FifoBuffer* fifo);

#endif
