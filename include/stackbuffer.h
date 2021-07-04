#ifndef _STACK_BUFFER_H_
#define _STACK_BUFFER_H_

#include <stdbool.h>
#include <stdint.h>

typedef struct
{
	void*	 Buffer;
	uint32_t ElementSize;
	uint32_t NumElements;
	uint32_t Head;
	bool	 Full;
	bool	 Empty;
} StackBuffer;

void StackBuffer_Init(StackBuffer* stack, void* buff, uint32_t elementSize, uint32_t numElements);
bool StackBuffer_Add(StackBuffer* stack, void* element);
bool StackBuffer_Remove(StackBuffer* stack, void* element);

#endif
