#include "queuebuffer.h"

#include <stdio.h>

#define NUM_NODES		 3
#define TEST_BUFFER_SIZE 5

int main()
{
	QueueBuffer queue;
	uint32_t	buffer[NUM_NODES] = {0};
	uint32_t*	item= NULL;

	QueueBuffer_Init(&queue, (void*)buffer, sizeof(buffer[0]), NUM_NODES);

	item= QueueBuffer_Remove(&queue);
	if (item != NULL)
		return 1;

	item = QueueBuffer_Add(&queue);
	if (item == NULL)
		return 2;
	*item= 10;

	item = QueueBuffer_Add(&queue);
	if (item == NULL)
		return 3;
	*item= 20;

	item= QueueBuffer_Remove(&queue);
	if (item == NULL)
		return 4;
	if (*item != 10)
		return 4;

	item= QueueBuffer_Remove(&queue);
	if (item == NULL)
		return 5;
	if (*item != 20)
		return 5;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		item = QueueBuffer_Add(&queue);
		if (item == NULL)
			return 100 + i;
		*item = 100*i+1;
	}

	if (QueueBuffer_Add(&queue) != NULL)
		return 3;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		item= QueueBuffer_Remove(&queue);
		if (item == NULL)
			return 200 + i;
		if (*item != 100*i+1)
			return 11 + i;
	}

	item= QueueBuffer_Remove(&queue);
	if (item != NULL)
		return 10;

	return 0;
}
