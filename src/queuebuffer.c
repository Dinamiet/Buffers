#include "queuebuffer.h"

#include <string.h>

void QueueBuffer_Init(QueueBuffer* queue, void* buff, uint32_t elementSize, uint32_t numElements)
{
	queue->Buffer	   = buff;
	queue->ElementSize = elementSize;
	queue->NumElements = numElements;
	queue->Head		   = 0;
	queue->Tail		   = 0;
	queue->Full		   = false;
	queue->Empty	   = true;
}

bool QueueBuffer_Add(QueueBuffer* queue, void* element)
{
	if (queue->Full)
		return false;

	uint32_t offset = queue->Head * queue->ElementSize;
	memcpy((uint8_t*)queue->Buffer + offset, element, queue->ElementSize);

	if (++queue->Head >= queue->NumElements) // Wrap around at buffer end
		queue->Head = 0;

	queue->Full	 = queue->Head == queue->Tail;
	queue->Empty = false; // Cannot be empty - just added element

	return true;
}

bool QueueBuffer_Remove(QueueBuffer* queue, void* element)
{
	if (queue->Empty)
		return false;

	uint32_t offset = queue->Tail * queue->ElementSize;
	memcpy(element, (uint8_t*)queue->Buffer + offset, queue->ElementSize);

	if (++queue->Tail >= queue->NumElements) // Wrap around at buffer end
		queue->Tail = 0;

	queue->Empty = queue->Head == queue->Tail;
	queue->Full	 = false; // Cannot be full - just removed element

	return true;
}
