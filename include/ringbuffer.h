#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

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
} RingBuffer;

void RingBuffer_Init(RingBuffer* ring, void* buff, uint32_t elementSize, uint32_t numElements);
bool RingBuffer_Insert(RingBuffer* ring, void* element);
bool RingBuffer_Remove(RingBuffer* ring, void* element);

#endif
