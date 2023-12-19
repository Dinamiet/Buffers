#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

/** \file
 * Linked List
 *
 * Doubly circular linked list implementation
 */

#include <stdbool.h>
#include <stddef.h>

/**
 * Holds the information for node elements
 * This structure must be included at the beginning of larger linked list nodes
 */
typedef struct _Node
{
	struct _Node* Next;
	struct _Node* Prev;
} Node;

/**
 * LinkedList entity
 */
typedef struct _LinkedList_
{
	Node* Head;
} LinkedList;

/**
 * Initializes a LinkedList entity
 */
void LinkedList_Init(LinkedList* list);

/**
 * Check if list contains no nodes
 * \param list List to check
 * \return True if list contains no nodes, false otherwise
 */
bool LinkedList_Empty(LinkedList* list);

/**
 * Get the length/number of nodes of list
 * \param list List to check
 * \return Number of nodes contained in list
 */
size_t LinkedList_Length(LinkedList* list);

/**
 * The first node of the list
 * \param list List to use
 * \return Reference to the first node of list. NULL if list does not contain any nodes
 */
void* LinkedList_Head(LinkedList* list);

/**
 * The last node of the list
 * \param list List to use
 * \return Reference to the last node of list. NULL if list does not contain any nodes
 */
void* LinkedList_Tail(LinkedList* list);

/**
 * The next node
 * \param node Current node
 * \return Reference to the node after node
 */
void* LinkedList_Next(void* node);

/**
 * The previous node
 * \param node Current node
 * \return Reference to the node before node
 */
void* LinkedList_Prev(void* node);

/**
 * Add an node to the start of the list
 * \param list List to which the node will be added
 * \param node The node that will be added to the list
 * \return Reference to the first node in the list
 */
void* LinkedList_AddHead(LinkedList* list, void* node);

/**
 * Add an node after a selected node
 * \param afterNode Node after which node should be added to the list
 * \param node The node to be added
 * \return Reference to the added node
 */
void* LinkedList_AddAfter(void* afterNode, void* node);

/**
 * Add an node to the end of the list
 * \param list List to which the node will be added
 * \param node The node that will be added to the list
 * \return Reference to the last node in the list
 */
void* LinkedList_AddTail(LinkedList* list, void* node);

/**
 * Remove a node from the list
 * \param list List from which node should be removed
 * \param node The node to remove from the list
 * \return Reference to the removed node
 */
void* LinkedList_RemoveNode(LinkedList* list, void* node);

/**
 * Remove the first node from the list
 * \param list List from which first node will be removed.
 * \return Reference to the removed node. NULL if no node could be removed.
 */
void* LinkedList_RemoveHead(LinkedList* list);

/**
 * Remove the last node from the list
 * \param list List from which the last node will be removed.
 * \return Reference to the remcoed node. NULL if no node could be removed.
 */
void* LinkedList_RemoveTail(LinkedList* list);

/**
 * Empties the list
 * \param list The list to clear
 */
void LinkedList_Clear(LinkedList* list);

/**
 * Merge two lists together into one list, appending other to list
 * \param list Master list, this list will contain all nodes after the merge
 * \param other Slave list, this list will be empty after the merge
 */
void LinkedList_Merge(LinkedList* list, LinkedList* other);

#endif
