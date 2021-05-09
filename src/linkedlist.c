#include "linkedlist.h"

void LinkedList_Init(LinkedList* list)
{
	list->Head = NULL;
	list->Tail = NULL;
}

Node* LinkedList_LinkHead(LinkedList* list, Node* node)
{
	if (list->Head == NULL && list->Tail == NULL)
		return list->Head = list->Tail = node->Next = node->Prev = node;
	return LinkedList_LinkBefore(list, list->Head, node);
}

Node* LinkedList_LinkTail(LinkedList* list, Node* node)
{
	if (list->Head == NULL && list->Tail == NULL)
		return list->Head = list->Tail = node->Next = node->Prev = node;
	return LinkedList_LinkAfter(list, list->Tail, node);
}

Node* LinkedList_UnlinkHead(LinkedList* list) { return LinkedList_UnlinkNode(list, list->Head); }

Node* LinkedList_UnlinkTail(LinkedList* list) { return LinkedList_UnlinkNode(list, list->Tail); }

Node* LinkedList_LinkAfter(LinkedList* list, Node* afterNode, Node* node)
{
	if (afterNode == NULL || node == NULL)
	{
		return NULL;
	}

	node->Prev		= afterNode;
	node->Next		= afterNode->Next;
	afterNode->Next = node;

	if (list->Tail == afterNode)
	{
		list->Tail = list->Head->Prev = node;
	}

	return node;
}

Node* LinkedList_LinkBefore(LinkedList* list, Node* beforeNode, Node* node)
{
	if (beforeNode == NULL || node == NULL)
	{
		return NULL;
	}

	node->Next		 = beforeNode;
	node->Prev		 = beforeNode->Prev;
	beforeNode->Prev = node;

	if (list->Head == beforeNode)
	{
		list->Head = list->Tail->Next = node;
	}

	return node;
}

Node* LinkedList_UnlinkNode(LinkedList* list, Node* node)
{
	if (node == NULL)
		return NULL;
	if (list->Head == node && list->Tail == node)
	{
		list->Head = list->Tail = NULL;
		node->Next = node->Prev = NULL;
		return node;
	}

	if (node == list->Head)
	{
		list->Head = node->Next;
	}

	if (node == list->Tail)
	{
		list->Tail = node->Prev;
	}

	node->Next->Prev = node->Prev;
	node->Prev->Next = node->Next;

	node->Next = node->Prev = NULL;
	return node;
}
