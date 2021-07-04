#include "ringbuffer.h"

#include <stdio.h>

#define NUM_NODES 3
#define TEST_BUFFER_SIZE 5

int main()
{
	RingBuffer ringbuffer;
	uint32_t buffer[NUM_NODES]= { 0 };
	uint32_t item;

	RingBuffer_Init(&ringbuffer, (void*)buffer, sizeof(buffer[0]), NUM_NODES);

	if (RingBuffer_Remove(&ringbuffer, (void*)&item))
		return 1;

	item= 10;
	if (!RingBuffer_Insert(&ringbuffer, (void*)&item))
		return 2;

	item= 20;
	if (!RingBuffer_Insert(&ringbuffer, (void*)&item))
		return 3;

	if (!RingBuffer_Remove(&ringbuffer, (void*)&item))
		return 4;
	if (item != 10)
		return 4;

	if (!RingBuffer_Remove(&ringbuffer, (void*)&item))
		return 5;
	if (item != 20)
		return 5;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		item= 100*i;
		if (!RingBuffer_Insert(&ringbuffer, (void*)&item))
			return 100+i;
	}

	item= 20;
	if (RingBuffer_Insert(&ringbuffer, (void*)&item))
		return 3;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		if (!RingBuffer_Remove(&ringbuffer, (void*)&item))
			return 200+i;
		if (item != i*100)
			return 11+i;
	}

	if (RingBuffer_Remove(&ringbuffer, (void*)&item))
		return 10;

	return 0;
}
