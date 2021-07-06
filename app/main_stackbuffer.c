#include "stackbuffer.h"

#include <stdio.h>

#define NUM_NODES		 3
#define TEST_BUFFER_SIZE 5

int main()
{
	StackBuffer stack;
	uint32_t	buffer[NUM_NODES] = {0};
	uint32_t*	item= NULL;

	StackBuffer_Init(&stack, (void*)buffer, sizeof(buffer[0]), NUM_NODES);

	if (StackBuffer_Remove(&stack) != NULL)
		return 1;

	item = StackBuffer_Add(&stack);
	if (item == NULL)
		return 2;
	*item= 10;

	item = StackBuffer_Add(&stack);
	if (item == NULL)
		return 3;
	*item= 20;

	item= StackBuffer_Remove(&stack);
	if (item == NULL)
		return 4;
	if (*item != 20)
		return 4;

	item= StackBuffer_Remove(&stack);
	if (item == NULL)
		return 5;
	if (*item != 10)
		return 5;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		item = StackBuffer_Add(&stack);
		if (item == NULL)
			return 100 + i;
		*item = 100*i+1;
	}

	if (StackBuffer_Add(&stack) != NULL)
		return 3;

	for (size_t i = 0; i < NUM_NODES; i++)
	{
		item= StackBuffer_Remove(&stack);
		if (item == NULL)
			return 200 + i;
		if (*item != 201-100*i)
			return 11 + i;
	}

	item= StackBuffer_Remove(&stack);
	if (item != NULL)
		return 10;

	return 0;
}
