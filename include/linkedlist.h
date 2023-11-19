#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdbool.h>
#include <stddef.h>

typedef struct _Node
{
	struct _Node* Next;
	struct _Node* Prev;
} Node;

typedef struct _LinkedList_
{
	Node* Head;
} LinkedList;

void   LinkedList_Init(LinkedList* list);
bool   LinkedList_Empty(LinkedList* list);
size_t LinkedList_Length(LinkedList* list);
void*  LinkedList_Head(LinkedList* list);
void*  LinkedList_Tail(LinkedList* list);
void*  LinkedList_Next(void* node);
void*  LinkedList_Prev(void* node);
void*  LinkedList_AddHead(LinkedList* list, void* node);
void*  LinkedList_AddAfter(void* afterNode, void* node);
void*  LinkedList_AddTail(LinkedList* list, void* node);
void*  LinkedList_RemoveNode(LinkedList* list, void* node);
void*  LinkedList_RemoveHead(LinkedList* list);
void*  LinkedList_RemoveTail(LinkedList* list);
void   LinkedList_Clear(LinkedList* list);
void   LinkedList_Merge(LinkedList* list, LinkedList* other);

#endif
