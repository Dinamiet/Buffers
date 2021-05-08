#include "bufferedlist.h"

void BufferedList_Init(BufferedList* list, Node* nodes, uint32_t nodeSize, uint32_t numNodes)
{
	LinkedList_Init(&list->Free);
	LinkedList_Init(&list->Used);

	for (uint32_t i = 0; i < numNodes; i++)
	{
		Node* node = (Node*)(((uint8_t*)nodes) + nodeSize * i);
		LinkedList_LinkTail(&list->Free, node);
	}
}

Node* BufferedList_LinkHead(BufferedList* list)
{
	Node* tmp = LinkedList_UnlinkHead(&list->Free);
	return LinkedList_LinkHead(&list->Used, tmp);
}

Node* BufferedList_LinkTail(BufferedList* list)
{
	Node* tmp = LinkedList_UnlinkHead(&list->Free);
	return LinkedList_LinkTail(&list->Used, tmp);
}

Node* BufferedList_UnlinkHead(BufferedList* list)
{
	Node* tmp = LinkedList_UnlinkHead(&list->Used);
	return LinkedList_LinkTail(&list->Free, tmp);
}

Node* BufferedList_UnlinkTail(BufferedList* list)
{
	Node* tmp = LinkedList_UnlinkTail(&list->Used);
	return LinkedList_LinkTail(&list->Free, tmp);
}
