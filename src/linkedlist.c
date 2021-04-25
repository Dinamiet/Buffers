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

	if (list->Head)
	{
		list->Head->Prev= node;
		list->Tail->Next= node;
	}
	else
	{
		list->Head= node;
		list->Tail= node;
	}

	node->Next= list->Head;
	node->Prev= list->Tail;

	list->Head= node;

	return list->Head;
}

Node* LinkedList_LinkTail(LinkedList* list, Node* node)
{
	if (node == NULL)
		return node;

	if (list->Tail)
	{
		list->Head->Prev= node;
		list->Tail->Next= node;
	}
	else
	{
		list->Head= node;
		list->Tail= node;
	}

	node->Next= list->Head;
	node->Prev= list->Tail;

	list->Tail= node;

	return list->Tail;
}

Node* LinkedList_UnlinkHead(LinkedList* list)
{
	Node* unlinked= list->Head;
	if (unlinked)
	{
		if (list->Head != list->Tail)
		{
			list->Head= list->Tail->Next= unlinked->Next;
			list->Head->Prev= unlinked->Prev;
		}
		else
		{
			list->Head = list->Tail = NULL;
		}

		unlinked->Next= unlinked->Prev= NULL;
	}
	return unlinked;
}

Node* LinkedList_UnlinkTail(LinkedList* list)
{
	Node* unlinked= list->Tail;
	if (unlinked)
	{
		if (list->Head != list->Tail)
		{
			list->Tail= list->Head->Prev = unlinked->Prev;
			list->Tail->Next= unlinked->Next;
		}
		else
		{
			list->Head= list->Tail = NULL;
		}

		unlinked->Next= unlinked->Prev= NULL;
	}
	return unlinked;
}
