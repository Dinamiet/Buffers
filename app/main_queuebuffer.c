#include "queuebuffer.h"

#include <stdio.h>

#define NUM_NODES 3
#define TEST_BUFFER_SIZE 5

int main()
{
	QueueBuffer queue;
	uint32_t buffer[NUM_NODES]= { 0 };
	uint32_t item;

	QueueBuffer_Init(&queue, (void*)buffer, sizeof(buffer[0]), NUM_NODES);

	if (QueueBuffer_Remove(&queue, (void*)&item))
		return 1;

	item= 10;
	if (!QueueBuffer_Add(&queue, (void*)&item))
		return 2;

	item= 20;
	if (!QueueBuffer_Add(&queue, (void*)&item))
		return 3;

	if (!QueueBuffer_Remove(&queue, (void*)&item))
		return 4;
	if (item != 10)
		return 4;

	if (!QueueBuffer_Remove(&queue, (void*)&item))
		return 5;
	if (item != 20)
		return 5;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		item= 100*i;
		if (!QueueBuffer_Add(&queue, (void*)&item))
			return 100+i;
	}

	item= 20;
	if (QueueBuffer_Add(&queue, (void*)&item))
		return 3;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		if (!QueueBuffer_Remove(&queue, (void*)&item))
			return 200+i;
		if (item != i*100)
			return 11+i;
	}

	if (QueueBuffer_Remove(&queue, (void*)&item))
		return 10;

	return 0;
}
