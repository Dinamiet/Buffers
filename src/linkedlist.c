#include "linkedlist.h"

#include <assert.h>

void LinkedList_Init(LinkedList* list)
{
	assert(list != NULL);

	list->Head = NULL;
}

bool LinkedList_Empty(const LinkedList* list)
{
	assert(list != NULL);

	return list->Head == NULL;
}

size_t LinkedList_Length(const LinkedList* list)
{
	assert(list != NULL);

	if (LinkedList_Empty(list))
		return 0;

	Node*  node  = list->Head;
	size_t count = 0;
	do {
		count++;
		node = node->Next;
	} while (node != list->Head);

	return count;
}

void* LinkedList_First(const LinkedList* list)
{
	assert(list != NULL);

	return list->Head;
}

void* LinkedList_Last(const LinkedList* list)
{
	assert(list != NULL);

	return list->Head ? list->Head->Prev : NULL;
}

void* LinkedList_Next(const void* _node)
{
	const Node* node = _node;
	return node ? node->Next : NULL;
}

void* LinkedList_Prev(const void* _node)
{
	const Node* node = _node;
	return node ? node->Prev : NULL;
}

void* LinkedList_AddAfter(void* _afterNode, void* _node)
{
	Node* node      = _node;
	Node* afterNode = _afterNode;

	if (!afterNode || !node)
		return NULL;

	node->Prev            = afterNode;
	node->Next            = afterNode->Next;
	afterNode->Next->Prev = node;
	afterNode->Next       = node;

	return node;
}

void* LinkedList_AddStart(LinkedList* list, void* _node)
{
	assert(list != NULL);

	Node* node = _node;
	if (!node)
		return NULL;

	if (!list->Head)
		return list->Head = node->Next = node->Prev = node;

	list->Head = LinkedList_AddAfter(list->Head->Prev, node);
	return list->Head;
}

void* LinkedList_AddEnd(LinkedList* list, void* _node)
{
	assert(list != NULL);

	Node* node = _node;
	if (!list->Head)
		return list->Head = node->Next = node->Prev = node;

	return LinkedList_AddAfter(list->Head->Prev, node);
}

void* LinkedList_Remove(LinkedList* list, void* _node)
{
	assert(list != NULL);

	Node* node = _node;
	if (!node)
		return NULL;

	// If removing Head node, move head to next node
	if (node == list->Head)
		list->Head = node->Next;

	// If node is still the head node, node was only node in list, empty list
	if (node == list->Head)
		list->Head = NULL;

	node->Next->Prev = node->Prev;
	node->Prev->Next = node->Next;

	node->Next = node->Prev = NULL;

	return node;
}

void* LinkedList_RemoveFirst(LinkedList* list)
{
	assert(list != NULL);

	return LinkedList_Remove(list, list->Head);
}

void* LinkedList_RemoveLast(LinkedList* list)
{
	assert(list != NULL);

	return LinkedList_Remove(list, list->Head->Prev);
}

void LinkedList_Clear(LinkedList* list)
{
	assert(list != NULL);

	list->Head = NULL;
}

void LinkedList_Merge(LinkedList* list, LinkedList* other)
{
	assert(list != NULL);
	assert(other != NULL);

	if (LinkedList_Empty(other)) // No need to do anything
		return;

	if (LinkedList_Empty(list))
		list->Head = other->Head;
	else
	{
		Node* thisHead  = list->Head;
		Node* thisTail  = list->Head->Prev;
		Node* otherHead = other->Head;
		Node* otherTail = other->Head->Prev;

		thisTail->Next  = otherHead;
		otherTail->Next = thisHead;
		thisHead->Prev  = otherTail;
		otherHead->Prev = thisTail;
	}
	LinkedList_Clear(other);
}
