#include "fifobuffer.h"

#include <stdio.h>

#define NUM_NODES		 3
#define TEST_BUFFER_SIZE 5

int main()
{
	FifoBuffer queue;
	uint32_t	buffer[NUM_NODES] = {0};
	uint32_t*	item= NULL;

	FifoBuffer_Init(&queue, (void*)buffer, sizeof(buffer[0]), NUM_NODES);

	item= FifoBuffer_Remove(&queue);
	if (item != NULL)
		return 1;

	item = FifoBuffer_Add(&queue);
	if (item == NULL)
		return 2;
	*item= 10;

	item = FifoBuffer_Add(&queue);
	if (item == NULL)
		return 3;
	*item= 20;

	item= FifoBuffer_Remove(&queue);
	if (item == NULL)
		return 4;
	if (*item != 10)
		return 4;

	item= FifoBuffer_Remove(&queue);
	if (item == NULL)
		return 5;
	if (*item != 20)
		return 5;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		item = FifoBuffer_Add(&queue);
		if (item == NULL)
			return 100 + i;
		*item = 100*i+1;
	}

	if (FifoBuffer_Add(&queue) != NULL)
		return 3;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		item= FifoBuffer_Remove(&queue);
		if (item == NULL)
			return 200 + i;
		if (*item != 100*i+1)
			return 11 + i;
	}

	item= FifoBuffer_Remove(&queue);
	if (item != NULL)
		return 10;

	return 0;
}
