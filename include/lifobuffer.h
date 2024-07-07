#ifndef _LIFO_BUFFER_H_
#define _LIFO_BUFFER_H_

/** \file
 * Lifo buffer
 *
 * Last In, First Out buffer
 * Buffer is initialized with allocated memory that will be used as a lifo buffer.
 */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * LifoBuffer entity
 */
typedef struct _LifoBuffer_
{
	uint8_t* Buffer;
	size_t   ElementSize;
	size_t   NumElements;
	size_t   WorkingIndex;
} LifoBuffer;

/**
 * Initializes a LifoBuffer
 * \param lifo Buffer to initialize
 * \param buff Memory to use for the buffer
 * \param elementSize Size (in bytes) of a single buffer element
 * \param numElement Total number of elements that can be stored in the buffer
 */
void LifoBuffer_Init(LifoBuffer* lifo, void* buff, const size_t elementSize, const size_t numElements);

/**
 * Check if buffer is full
 * \param lifo Buffer to check
 * \return True if lifo is full, false otherwise
 */
bool LifoBuffer_Full(const LifoBuffer* lifo);

/**
 * Check if buffer is empty
 * \param lifo Buffer to check
 * \return True if lifo is empty, false otherwise
 */
bool LifoBuffer_Empty(const LifoBuffer* lifo);

/**
 * Get the number of used elements from a buffer
 * \param lifo Buffer to check usage
 * \return Number of elements active in the buffer
 */
size_t LifoBuffer_Used(const LifoBuffer* lifo);

/**
 * Get the number of free elements for a buffer
 * \param lifo Buffer to check usage
 * \return Number of elements not used by the buffer
 */
size_t LifoBuffer_Free(const LifoBuffer* lifo);

/**
 * Add an element to the lifo
 * \param lifo Buffer to which an element must be added
 * \return Reference to the newly added element, NULL if no element could be allocated/added
 */
void* LifoBuffer_Add(LifoBuffer* lifo);

/**
 * Remove an element from the lifo
 * \param lifo Buffer from which to remove an element
 * \return Reference to the removed element, NULL if no element could be removed
 */
void* LifoBuffer_Remove(LifoBuffer* lifo);

/**
 * Clear lifo of all used elements
 * \param lifo Buffer to clear
 */
void LifoBuffer_Clear(LifoBuffer* lifo);

#endif
