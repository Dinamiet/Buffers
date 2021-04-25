#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdint.h>

#ifndef NULL
#define NULL 0
#endif

typedef struct _Node
{
	struct _Node* Prev;
	struct _Node* Next;
	void* Data;
} Node;

typedef struct _LinkedList
{
	Node* Head;
	Node* Tail;
} LinkedList;

void  LinkedList_Init(LinkedList* list);
Node* LinkedList_LinkHead(LinkedList* list, Node* node);
Node* LinkedList_LinkTail(LinkedList* list, Node* node);
Node* LinkedList_UnlinkHead(LinkedList* list);
Node* LinkedList_UnlinkTail(LinkedList* list);

#endif
