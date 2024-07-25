#include "bufferedlist.h"

#include <stdint.h>

void BufferedList_Init(BufferedList* list, const void* nodes, const size_t nodeSize, const size_t numNodes)
{
	LinkedList_Init(&list->Free);
	LinkedList_Init(&list->Used);

	for (size_t i = 0; i < numNodes; i++)
	{
		void* node = ((uint8_t*)nodes) + nodeSize * i;
		LinkedList_AddEnd(&list->Free, node);
	}
}

bool BufferedList_Empty(const BufferedList* list) { return LinkedList_Empty(&list->Used); }

bool BufferedList_Full(const BufferedList* list) { return LinkedList_Empty(&list->Free); }

size_t BufferedList_Used(const BufferedList* list) { return LinkedList_Length(&list->Used); }

size_t BufferedList_Free(const BufferedList* list) { return LinkedList_Length(&list->Free); }

void* BufferedList_First(const BufferedList* list) { return LinkedList_First(&list->Used); }

void* BufferedList_Last(const BufferedList* list) { return LinkedList_Last(&list->Used); }

void* BufferedList_Next(const void* node) { return LinkedList_Next(node); }

void* BufferedList_Prev(const void* node) { return LinkedList_Prev(node); }

void* BufferedList_AddStart(BufferedList* list)
{
	Node* tmp = LinkedList_RemoveFirst(&list->Free);
	return LinkedList_AddStart(&list->Used, tmp);
}

void* BufferedList_AddEnd(BufferedList* list)
{
	Node* tmp = LinkedList_RemoveFirst(&list->Free);
	return LinkedList_AddEnd(&list->Used, tmp);
}

void* BufferedList_RemoveFirst(BufferedList* list)
{
	Node* tmp = LinkedList_RemoveFirst(&list->Used);
	return LinkedList_AddEnd(&list->Free, tmp);
}

void* BufferedList_RemoveLast(BufferedList* list)
{
	Node* tmp = LinkedList_RemoveLast(&list->Used);
	return LinkedList_AddEnd(&list->Free, tmp);
}

void* BufferedList_AddAfter(BufferedList* list, void* afterNode)
{
	Node* tmp = LinkedList_RemoveFirst(&list->Free);
	return LinkedList_AddAfter(afterNode, tmp);
}

void* BufferedList_Remove(BufferedList* list, void* node)
{
	Node* tmp = LinkedList_Remove(&list->Used, node);
	return LinkedList_AddEnd(&list->Free, tmp);
}

void BufferedList_Clear(BufferedList* list) { LinkedList_Merge(&list->Free, &list->Used); }
