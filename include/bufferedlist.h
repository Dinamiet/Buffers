#ifndef _BUFFEREDLIST_H_
#define _BUFFEREDLIST_H_

#include "linkedlist.h"

typedef struct _BufferedList
{
	LinkedList Free;
	LinkedList Used;
} BufferedList;

void   BufferedList_Init(BufferedList* list, void* nodes, size_t nodeSize, size_t numNodes);
bool   BufferedList_Empty(BufferedList* list);
bool   BufferedList_Full(BufferedList* list);
size_t BufferedList_Used(BufferedList* list);
size_t BufferedList_Free(BufferedList* list);
void*  BufferedList_First(BufferedList* list);
void*  BufferedList_Last(BufferedList* list);
void*  BufferedList_Next(void* node);
void*  BufferedList_Prev(void* node);
void*  BufferedList_AddHead(BufferedList* list);
void*  BufferedList_AddTail(BufferedList* list);
void*  BufferedList_RemoveHead(BufferedList* list);
void*  BufferedList_RemoveTail(BufferedList* list);
void*  BufferedList_AddAfter(BufferedList* list, void* afterNode);
void*  BufferedList_AddBefore(BufferedList* list, void* beforeNode);
void*  BufferedList_RemoveNode(BufferedList* list, void* node);
void   BufferedList_Clear(BufferedList* list);

#endif
