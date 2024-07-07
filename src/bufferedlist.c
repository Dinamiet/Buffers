#include "bufferedlist.h"

#include <stdint.h>

void BufferedList_Init(BufferedList* list, const void* nodes, const size_t nodeSize, const size_t numNodes)
{
	LinkedList_Init(&list->Free);
	LinkedList_Init(&list->Used);

	for (size_t i = 0; i < numNodes; i++)
	{
		void* node = ((uint8_t*)nodes) + nodeSize * i;
		LinkedList_AddTail(&list->Free, node);
	}
}

bool BufferedList_Empty(const BufferedList* list) { return LinkedList_Empty(&list->Used); }

bool BufferedList_Full(const BufferedList* list) { return LinkedList_Empty(&list->Free); }

size_t BufferedList_Used(const BufferedList* list) { return LinkedList_Length(&list->Used); }

size_t BufferedList_Free(const BufferedList* list) { return LinkedList_Length(&list->Free); }

void* BufferedList_First(const BufferedList* list) { return LinkedList_Head(&list->Used); }

void* BufferedList_Last(const BufferedList* list) { return LinkedList_Tail(&list->Used); }

void* BufferedList_Next(const void* node) { return LinkedList_Next(node); }

void* BufferedList_Prev(const void* node) { return LinkedList_Prev(node); }

void* BufferedList_AddHead(BufferedList* list)
{
	Node* tmp = LinkedList_RemoveHead(&list->Free);
	return LinkedList_AddHead(&list->Used, tmp);
}

void* BufferedList_AddTail(BufferedList* list)
{
	Node* tmp = LinkedList_RemoveHead(&list->Free);
	return LinkedList_AddTail(&list->Used, tmp);
}

void* BufferedList_RemoveHead(BufferedList* list)
{
	Node* tmp = LinkedList_RemoveHead(&list->Used);
	return LinkedList_AddTail(&list->Free, tmp);
}

void* BufferedList_RemoveTail(BufferedList* list)
{
	Node* tmp = LinkedList_RemoveTail(&list->Used);
	return LinkedList_AddTail(&list->Free, tmp);
}

void* BufferedList_AddAfter(BufferedList* list, void* afterNode)
{
	Node* tmp = LinkedList_RemoveHead(&list->Free);
	return LinkedList_AddAfter(afterNode, tmp);
}

void* BufferedList_RemoveNode(BufferedList* list, void* node)
{
	Node* tmp = LinkedList_RemoveNode(&list->Used, node);
	return LinkedList_AddTail(&list->Free, tmp);
}

void BufferedList_Clear(BufferedList* list) { LinkedList_Merge(&list->Free, &list->Used); }
