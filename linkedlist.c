#include "linkedlist.h"

void LinkedList_Init(LinkedList* list)
{
	list->Head= NULL;
	list->Tail= NULL;
}

Node* LinkedList_LinkHead(LinkedList* list, Node* node)
{
	if (node == NULL)
		return node;

	node->Next= list->Head;
	node->Prev= NULL;

	if (list->Head)
		list->Head->Prev= node;
	else
		list->Tail= node;

	list->Head= node;

	return list->Head;
}

Node* LinkedList_LinkTail(LinkedList* list, Node* node)
{
	if (node == NULL)
		return node;
		
	node->Next= NULL;
	node->Prev= list->Tail;

	if (list->Tail)
		list->Tail->Next= node;
	else
		list->Head= node;

	list->Tail= node;

	return list->Tail;
}

Node* LinkedList_UnlinkHead(LinkedList* list)
{
	Node* unlinked= list->Head;
	if (unlinked)
	{
		list->Head= unlinked->Next;

		if (list->Head)
			list->Head->Prev= NULL;
		else
			list->Tail= NULL;

		unlinked->Next= unlinked->Prev= NULL;
	}
	return unlinked;
}

Node* LinkedList_UnlinkTail(LinkedList* list)
{
	Node* unlinked= list->Tail;
	if (unlinked)
	{
		list->Tail= unlinked->Prev;

		if (list->Tail)
			list->Tail->Next= NULL;
		else
			list->Head= NULL;

		unlinked->Next= unlinked->Prev= NULL;
	}
	return unlinked;
}
