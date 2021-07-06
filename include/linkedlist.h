#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stddef.h>
#include <stdint.h>

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
void* LinkedList_LinkHead(LinkedList* list, void* node);
void* LinkedList_LinkTail(LinkedList* list, void* node);
void* LinkedList_UnlinkHead(LinkedList* list);
void* LinkedList_UnlinkTail(LinkedList* list);
void* LinkedList_LinkAfter(LinkedList* list, void* afterNode, void* node);
void* LinkedList_LinkBefore(LinkedList* list, void* beforeNode, void* node);
void* LinkedList_UnlinkNode(LinkedList* list, void* node);

#endif
