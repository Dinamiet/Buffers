#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdint.h>

#ifndef NULL
#	define NULL 0x0
#endif

typedef struct _Node
{
	struct _Node* Next;
	struct _Node* Prev;
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
Node* LinkedList_LinkAfter(LinkedList* list, Node* afterNode, Node* node);
Node* LinkedList_LinkBefore(LinkedList* list, Node* beforeNode, Node* node);
Node* LinkedList_UnlinkNode(LinkedList* list, Node* node);

#endif // __LINKEDLIST_H__
