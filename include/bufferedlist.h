#ifndef __BUFFEREDLIST_H__
#define __BUFFEREDLIST_H__

#include "linkedlist.h"
#include <stddef.h>

typedef struct _BufferedList
{
	LinkedList Free;
	LinkedList Used;
} BufferedList;

void  BufferedList_Init(BufferedList* list, void* nodes, size_t nodeSize, size_t numNodes);
void* BufferedList_LinkHead(BufferedList* list);
void* BufferedList_LinkTail(BufferedList* list);
void* BufferedList_UnlinkHead(BufferedList* list);
void* BufferedList_UnlinkTail(BufferedList* list);
void* BufferedList_LinkAfter(BufferedList* list, void* afterNode);
void* BufferedList_LinkBefore(BufferedList* list, void* beforeNode);
void* BufferedList_UnlinkNode(BufferedList* list, void* node);

#endif
