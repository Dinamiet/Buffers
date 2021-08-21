#include "bufferedlist.h"

void BufferedList_Init(BufferedList* list, void* nodes, size_t nodeSize, size_t numNodes)
{
	LinkedList_Init(&list->Free);
	LinkedList_Init(&list->Used);

	for (uint32_t i = 0; i < numNodes; i++)
	{
		Node* node = (Node*)(((uint8_t*)nodes) + nodeSize * i);
		LinkedList_LinkTail(&list->Free, node);
	}
}

void* BufferedList_LinkHead(BufferedList* list)
{
	Node* tmp = LinkedList_UnlinkHead(&list->Free);
	return LinkedList_LinkHead(&list->Used, tmp);
}

void* BufferedList_LinkTail(BufferedList* list)
{
	Node* tmp = LinkedList_UnlinkHead(&list->Free);
	return LinkedList_LinkTail(&list->Used, tmp);
}

void* BufferedList_UnlinkHead(BufferedList* list)
{
	Node* tmp = LinkedList_UnlinkHead(&list->Used);
	return LinkedList_LinkTail(&list->Free, tmp);
}

void* BufferedList_UnlinkTail(BufferedList* list)
{
	Node* tmp = LinkedList_UnlinkTail(&list->Used);
	return LinkedList_LinkTail(&list->Free, tmp);
}

void* BufferedList_LinkAfter(BufferedList* list, void* afterNode)
{
	Node* tmp = LinkedList_UnlinkHead(&list->Free);
	return LinkedList_LinkAfter(&list->Used, afterNode, tmp);
}

void* BufferedList_LinkBefore(BufferedList* list, void* beforeNode)
{
	Node* tmp = LinkedList_UnlinkHead(&list->Free);
	return LinkedList_LinkBefore(&list->Used, beforeNode, tmp);
}

void* BufferedList_UnlinkNode(BufferedList* list, void* node)
{
	Node* tmp = LinkedList_UnlinkNode(&list->Used, node);
	return LinkedList_LinkTail(&list->Free, tmp);
}
