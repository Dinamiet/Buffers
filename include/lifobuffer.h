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
 * \param lifo Buffer entity to initialize
 * \param buffer Memory to be used as a Lifo
 * \param size Size of the buffer (in bytes)
 */
void LifoBuffer_Init(LifoBuffer* lifo, void* buff, const size_t size);

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
 * Add data to the lifo
 * \param lifo The Lifo to add data to
 * \param data The data to add to the Lifo
 * \param size The number of bytes to add
 * \return Number of bytes added
 */
size_t LifoBuffer_Add(LifoBuffer* lifo, const void* data, const size_t size);

/**
 * Remove elements from the lifo and place them in data
 * \param lifo The Lifo from which to remove data
 * \param data Storage where removed data will be placed
 * \param size The number of bytes to remove
 * \return Number of bytes removed
 */
size_t LifoBuffer_Remove(LifoBuffer* lifo, void* data, const size_t size);

/**
 * Delete data from lfio
 * \param lifo The lifo from which to delete data
 * \param size Number of bytes to delete
 * \return Number of bytes deleted
 */
size_t LifoBuffer_Delete(LifoBuffer* lifo, size_t size);

/**
 * Clear lifo of all used elements
 * \param lifo Buffer to clear
 */
void LifoBuffer_Clear(LifoBuffer* lifo);

#endif
