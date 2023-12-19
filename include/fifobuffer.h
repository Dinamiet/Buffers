#ifndef _FIFO_BUFFER_H_
#define _FIFO_BUFFER_H_

/** \file
 * Fifo buffer
 *
 * First In, First Out buffer
 * Buffer is initialized with allocated memory that will be used as a fifo buffer.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * FifoBuffer entity
 */
typedef struct
{
	uint8_t* Buffer;
	size_t   ElementSize;
	size_t   NumElements;
	size_t   AddIndex;
	size_t   RemoveIndex;
	bool     LastAdd;
} FifoBuffer;

/**
 * Initializes a FifoBuffer
 * \param fifo Buffer to initialize
 * \param buff Memory to use for the buffer
 * \param elementSize Size (in bytes) of a single buffer element
 * \param numElement Total number of elements that can be stored in the buffer
 */
void FifoBuffer_Init(FifoBuffer* fifo, void* buff, size_t elementSize, size_t numElements);

/**
 * Check if buffer is full
 * \param fifo Buffer to check
 * \return True if fifo is full, false otherwise
 */
bool FifoBuffer_Full(FifoBuffer* fifo);

/**
 * Check if buffer is empty
 * \param fifo Buffer to check
 * \return True if fifo is empty, false otherwise
 */
bool FifoBuffer_Empty(FifoBuffer* fifo);

/**
 * Get the number of used elements from a buffer
 * \param fifo Buffer to check usage
 * \return Number of elements active in the buffer
 */
size_t FifoBuffer_Used(FifoBuffer* fifo);

/**
 * Get the number of free elements for a buffer
 * \param fifo Buffer to check usage
 * \return Number of elements not used by the buffer
 */
size_t FifoBuffer_Free(FifoBuffer* fifo);

/**
 * Add an element to the fifo
 * \param fifo Buffer to which an element must be added
 * \return Reference to the newly added element. NULL if no element could be allocated/added
 */
void* FifoBuffer_Add(FifoBuffer* fifo);

/**
 * Remove an element from the fifo
 * \param fifo Buffer from which to remove an element
 * \return Reference to the removed element. NULL if no element could be removed
 */
void* FifoBuffer_Remove(FifoBuffer* fifo);

/**
 * Clear fifo of all used elements
 * \param fifo Buffer to clear
 */
void FifoBuffer_Clear(FifoBuffer* fifo);

#endif
