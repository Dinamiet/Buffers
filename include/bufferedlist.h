#ifndef _BUFFEREDLIST_H_
#define _BUFFEREDLIST_H_

/** \file
 * Buffered List
 *
 * Initialize the list with a buffer of elements/storage.
 * When adding elements to the list it is done from the provided buffer.
 * Removing elements is added back into an available memory pool to be used again if requested.
 */

#include "linkedlist.h"

/**
 * BufferedList entity
 */
typedef struct _BufferedList
{
	LinkedList Free;
	LinkedList Used;
} BufferedList;

/**
 * Initializes a BufferedList
 * \param list BufferedList to initialize
 * \param nodes Preallocated buffer for nodes
 * \param nodeSize Size (in bytes) of a single node in the buffer
 * \param numNodes The number of nodes in the buffer
 * \note Storage structure (node elements) should contain a Node structure at start of each items memory structure.
 */
void BufferedList_Init(BufferedList* list, void* nodes, size_t nodeSize, size_t numNodes);

/**
 * Check if list is empty
 * \param list List to retreive information from
 * \return True if list is empty and does not have any allocated/in use nodes. False otherwise
 */
bool BufferedList_Empty(BufferedList* list);

/**
 * Check if list is full
 * \param list List to retreive information from
 * \return True if list does not have any unallocated/unused nodes availabel. False otherwise
 */
bool BufferedList_Full(BufferedList* list);

/**
 * Number of used nodes
 * \param list List to retreive information from
 * \return Number of used elements/allocated nodes
 */
size_t BufferedList_Used(BufferedList* list);

/**
 * Number of free nodes
 * \param list List to retreive information from
 * \return Number of free elements/unused nodes
 */
size_t BufferedList_Free(BufferedList* list);

/**
 * First used node in list
 * \param list List to retreive information from
 * \return Reference to the first used node in the list
 */
void* BufferedList_First(BufferedList* list);

/**
 * Last used node in list
 * \param list List to retreive information from
 * \return Reference to the last used node in the list
 */
void* BufferedList_Last(BufferedList* list);

/**
 * Next node in list
 * \param node Current node
 * \return Reference to the node after the current node
 */
void* BufferedList_Next(void* node);

/**
 * \param node Current node
 * \return Reference to the node before the current node
 */
void* BufferedList_Prev(void* node);

/**
 * Add element/node to the start of the list. An unused node must be available.
 * \param list List to which a element/node will be added
 * \return Reference to the newly added node/element. NULL if no node/element could be added.
 */
void* BufferedList_AddHead(BufferedList* list);

/**
 * Add element/node to the end of the list. An unused node must be available.
 * \param list List to which a element/node will be added
 * \return Reference to the newly added node/element. NULL if no node/element could be added.
 */
void* BufferedList_AddTail(BufferedList* list);

/**
 * Remove an element/node from the beginning of the list. The list must contain at least one element/node.
 * \param list List from which to remove
 * \return Reference to the removed element/node. NULL if no node/element could be removed.
 */
void* BufferedList_RemoveHead(BufferedList* list);

/**
 * Remove an element/node from the end of the list. The list must contain at least one element/node.
 * \param list List from which to remove
 * \return Reference to the removed element/node. NULL if no node/element could be removed.
 */
void* BufferedList_RemoveTail(BufferedList* list);

/**
 * Add node/element after a specific node/element in the list
 * \param list List to add to
 * \param afterNode Node after which an element/node will be added
 * \return Reference to newly added node/element. NULL if no node/element could be added.
 */
void* BufferedList_AddAfter(BufferedList* list, void* afterNode);

/**
 * Add node/element before a specific node/element in the list
 * \param list List to add to
 * \param afterNode Node before which an element/node will be added
 * \return Reference to newly added node/element. NULL if no node/element could be added.
 */
void* BufferedList_AddBefore(BufferedList* list, void* beforeNode);

/**
 * Remove a specific node from the list
 * \param list List to remove from
 * \param node Node/element to remove
 * \return Reference to removed node/element
 */
void* BufferedList_RemoveNode(BufferedList* list, void* node);

/**
 * Clear/Empties the list of all used nodes/elements. All nodes/elements will be marked as unused.
 * \param list List to clear/empty
 */
void BufferedList_Clear(BufferedList* list);

#endif
