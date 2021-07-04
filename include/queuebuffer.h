#ifndef _QUEUE_BUFFER_H_
#define _QUEUE_BUFFER_H_

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
} QueueBuffer;

void QueueBuffer_Init(QueueBuffer* queue, void* buff, uint32_t elementSize, uint32_t numElements);
bool QueueBuffer_Add(QueueBuffer* queue, void* element);
bool QueueBuffer_Remove(QueueBuffer* queue, void* element);

#endif
