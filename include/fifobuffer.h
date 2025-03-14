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
	uint8_t* Start;
	uint8_t* End;
	uint8_t* AddAddress;
	uint8_t* RemoveAddress;
	bool     LastAdd;
} FifoBuffer;

/**
 * Initializes a FifoBuffer
 * \param fifo Buffer entity to initialize
 * \param buffer Memory to be used as a Fifo
 * \param size The size (bytes) of the buffer
 */
void FifoBuffer_Init(FifoBuffer* fifo, void* buff, const size_t size);

/**
 * Check if buffer is full
 * \param fifo Buffer to check
 * \return True if fifo is full, false otherwise
 */
bool FifoBuffer_Full(const FifoBuffer* fifo);

/**
 * Check if buffer is empty
 * \param fifo Buffer to check
 * \return True if fifo is empty, false otherwise
 */
bool FifoBuffer_Empty(const FifoBuffer* fifo);

/**
 * Get the number of used elements from a buffer
 * \param fifo Buffer to check usage
 * \return Number of bytes in the buffer
 */
size_t FifoBuffer_Used(const FifoBuffer* fifo);

/**
 * Get the number of free elements for a buffer
 * \param fifo Buffer to check usage
 * \return Number of bytes not used by the buffer
 */
size_t FifoBuffer_Free(const FifoBuffer* fifo);

/**
 * Add an element to the fifo
 * \param fifo The Fifo to add data to
 * \param data The data to add to the Fifo
 * \param size The number of bytes to add
 * \return Number of bytes added
 */
size_t FifoBuffer_Add(FifoBuffer* fifo, const void* data, const size_t size);

/**
 * Remove data from fifo and place in data
 * \param fifo The Fifo from which to remove data
 * \param data Storage where removed data will be stored
 * \param size Number of bytes to remove from Fifo
 * \return Number of bytes removed
 */
size_t FifoBuffer_Remove(FifoBuffer* fifo, void* data, const size_t size);

/**
 * Clear fifo of all used elements
 * \param fifo Buffer to clear
 */
void FifoBuffer_Clear(FifoBuffer* fifo);

#endif
