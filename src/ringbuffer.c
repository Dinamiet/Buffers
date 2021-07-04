#include "ringbuffer.h"
#include <string.h>

void RingBuffer_Init(RingBuffer* ring, void* buff, uint32_t elementSize, uint32_t numElements)
{
	ring->Buffer= buff;
	ring->ElementSize= elementSize;
	ring->NumElements= numElements;
	ring->Head= 0;
	ring->Tail= 0;
	ring->Full= false;
	ring->Empty= true;
}

bool RingBuffer_Insert(RingBuffer* ring, void* element)
{
	if (ring->Full)
		return false;

	uint32_t offset= ring->Head * ring->ElementSize;
	memcpy((uint8_t*)ring->Buffer + offset, element, ring->ElementSize);

	if (++ring->Head >= ring->NumElements) // Wrap around at buffer end
		ring->Head = 0;

	ring->Full = ring->Head == ring->Tail;
	ring->Empty = false; // Cannot be empty - just added element

	return true;
}

bool RingBuffer_Remove(RingBuffer* ring, void* element)
{
	if (ring->Empty)
		return false;

	uint32_t offset= ring->Tail * ring->ElementSize;
	memcpy(element, (uint8_t*)ring->Buffer + offset, ring->ElementSize);

	if (++ring->Tail >= ring->NumElements) // Wrap around at buffer end
		ring->Tail= 0;

	ring->Empty = ring->Head == ring->Tail;
	ring->Full= false; // Cannot be full - just removed element

	return true;
}
