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
	uint8_t* Start;
	uint8_t* End;
	uint8_t* WorkingAddress;
} LifoBuffer;

/**
 * Initializes a LifoBuffer
 * TODO: Docs
 */
void LifoBuffer_Init(LifoBuffer* lifo, void* buffer, const size_t size);

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
 * TODO: Docs
 */
size_t LifoBuffer_Add(LifoBuffer* lifo, void* data, size_t size);

/**
 * Remove an element from the lifo
 * TODO: Docs
 */
size_t LifoBuffer_Remove(LifoBuffer* lifo, void* data, size_t size);

/**
 * Clear lifo of all used elements
 * \param lifo Buffer to clear
 */
void LifoBuffer_Clear(LifoBuffer* lifo);

#endif
